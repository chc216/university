#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <memory.h>
#include <time.h>
#include <ctype.h>

#define DIM   9

enum LabelType { Empty = 0, Bomb = 9 };
enum MaskType { Hide = 0, Open, Flag };
// 전역 변수를 지워준다
// int   MineMapMask[DIM][DIM];
// int   MineMapLabel[DIM][DIM];
int   nx = DIM, ny = DIM;
int   nBomb = DIM;

inline int& mask(int MineMapMask[][DIM], int x, int y) { return MineMapMask[y][x]; }
inline int& label(int MineMapLabel[][DIM], int x, int y) { return MineMapLabel[y][x]; }
inline bool   isValid(int x, int y) { return (x >= 0 && x < nx&& y >= 0 && y < ny); }
inline bool   isBomb(int MineMapLabel[][DIM], int x, int y) { return isValid(x, y) && label(MineMapLabel, x, y) == Bomb; }
inline bool   isEmpty(int MineMapLabel[][DIM], int x, int y) { return isValid(x, y) && label(MineMapLabel, x, y) == Empty; }

// 특정 위치 x, y를 선택하고 그를 둘러싼 모든 칸들을 탐색한다
void dig(int MineMapMask[][DIM], int MineMapLabel[][DIM], int x, int y) {
    if (isValid(x, y) && mask(MineMapMask, x, y) != Open) {
        mask(MineMapMask, x, y) = Open;
        if (label(MineMapLabel, x, y) == 0) {
            dig(MineMapMask, MineMapLabel, x - 1, y - 1);
            dig(MineMapMask, MineMapLabel, x - 1, y);
            dig(MineMapMask, MineMapLabel, x - 1, y + 1);
            dig(MineMapMask, MineMapLabel, x, y - 1);
            dig(MineMapMask, MineMapLabel, x, y + 1);
            dig(MineMapMask, MineMapLabel, x + 1, y - 1);
            dig(MineMapMask, MineMapLabel, x + 1, y);
            dig(MineMapMask, MineMapLabel, x + 1, y + 1);
        }
    }
}

// 만약에 적절한 x, y를 입력 받았고 mark가 되지 않았다면 mark를 해준다
void mark(int MineMapMask[][DIM], int x, int y) {
    if (isValid(x, y) && mask(MineMapMask, x, y) == Hide)
        mask(MineMapMask, x, y) = Flag;
}

// 모든 영역을 이중 for문으로 탐색한 후 지뢰가 몇개 남았는지 확인한다
int getBombCount(int MineMapMask[][DIM]) {
    int count = 0;
    for (int y = 0; y < ny; y++)
        for (int x = 0; x < nx; x++)
            if (mask(MineMapMask, x, y) == Flag) count++;
    return count;
}

// 숨겨져 있는 칸이면 □
// flag가 꽂혀 있는 칸이면 ¤
// 폭탄이 있는 칸이면 ※
void print(int MineMapMask[][DIM], int MineMapLabel[][DIM]) {
    system("cls");
    printf("   발견:%2d   전체:%2d\n", getBombCount(MineMapMask), nBomb);
    printf("    ① ② ③ ④ ⑤ ⑥ ⑦ ⑧ ⑨\n");
    for (int y = 0; y < ny; y++) {
        printf("%2c ", 'A' + y);
        for (int x = 0; x < nx; x++) {
            if (mask(MineMapMask, x, y) == Hide)   printf(" □");
            else if (mask(MineMapMask, x, y) == Flag) printf("¤");
            else {
                if (isBomb(MineMapLabel, x, y)) printf(" ※");
                else if (isEmpty(MineMapLabel, x, y)) printf("  ");
                else printf("%2d", label(MineMapLabel, x, y));
            }
        }
        printf("\n");
    }
}

// 인접 8칸의 폭탄의 갯수를 계산한다
int countNbrBombs(int MineMapMask[][DIM], int MineMapLabel[][DIM], int x, int y) {
    int count = 0;
    for (int yy = y - 1; yy <= y + 1; yy++)
        for (int xx = x - 1; xx <= x + 1; xx++)
            if (isValid(xx, yy) && label(MineMapLabel, xx, yy) == Bomb)
                count++;
    return count;
}

// 초기 설정
// 1. 칸들을 숨겨준다
// 2. 인접 폭탄의 갯수를 각 위치에 적어준다
void init(int MineMapMask[][DIM], int MineMapLabel[][DIM], int total = 9) {
    srand((unsigned int)time(NULL));
    for (int y = 0; y < ny; y++)
        for (int x = 0; x < nx; x++) {
            mask(MineMapMask, x, y) = Hide;
            label(MineMapLabel, x, y) = 0;
        }
    nBomb = total;
    for (int i = 0; i < nBomb; i++) {
        int x, y;
        // 이미 해당 칸에 폭탄이 존재하면 다시 돌림
        do {
            x = rand() % nx;
            y = rand() % ny;
        } while (label(MineMapLabel, x, y) != Empty);
        label(MineMapLabel, x, y) = Bomb;
    }
    for (int y = 0; y < ny; y++)
        for (int x = 0; x < nx; x++)
            if (label(MineMapLabel, x, y) == Empty)
                label(MineMapLabel, x, y) = countNbrBombs(MineMapMask, MineMapLabel, x, y);
}

// 특정 위치가 폭탄이 있는지 없는지 반환한다
bool getPos(int& x, int& y) {
    printf("\n지뢰(P)행(A-I)열(1-9)\n      입력 --> ");
    bool isBomb = false;
    y = toupper(_getch()) - 'A';    
    
    // P를 입력 받으면 isBomb를 true로 만들어 준다
    if (y == 'P' - 'A') {
        isBomb = true;
        y = toupper(_getche()) - 'A';
    }
    x = _getch() - '1';
    return isBomb;
}

// 지뢰찾기에 성공했는지 반환한다
int checkDone(int MineMapMask[][DIM], int MineMapLabel[][DIM]) {
    int count = 0;
    for (int y = 0; y < ny; y++)
        for (int x = 0; x < nx; x++) {
            // 특정 위치가 비어 있다면 count 증가
            if (mask(MineMapMask, x, y) != Open) count++;
            // 특정 위치에 폭탄이 있다면 실패
            else if (isBomb(MineMapLabel, x, y)) return -1;
        }
    return (count == nBomb) ? 1 : 0;
}

// 지뢰찾기를 실행
void playMineSweeper(int MineMapMask[][DIM], int MineMapLabel[][DIM], int total) {
    int x, y, status;
    init(MineMapMask, MineMapLabel, total);
    do {
        print(MineMapMask, MineMapLabel);
        bool isBomb = getPos(x, y);
        if (isBomb) mark(MineMapMask, x, y);
        else        dig(MineMapMask, MineMapLabel, x, y);
        status = checkDone(MineMapMask, MineMapLabel);
    } while (status == 0);
    print(MineMapMask, MineMapLabel);
    if (status < 0)
        printf("\n실패: 지뢰 폭발!!!\n\n");
    else   printf("\n성공: 탐색 성공!!!\n\n");
}

int main()
{
    int total;
    int MineMapMask[DIM][DIM];
    int MineMapLabel[DIM][DIM];

    printf(" <Mine Sweeper>\n");
    printf(" 매설할 총 지뢰의 개수 입력 : ");
    scanf("%d", &total);
    playMineSweeper(MineMapMask, MineMapLabel, total);
}