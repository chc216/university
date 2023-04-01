#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <memory.h>
#include <time.h>
#include <ctype.h>

#define DIM	9

enum LabelType { Empty = 0, Bomb = 9 };
enum MaskType { Hide = 0, Open, Flag };
//int	MineMapMask[DIM][DIM];		
//int	MineMapLabel[DIM][DIM];		
int	nx = DIM, ny = DIM;
int	nBomb = DIM;

inline int& mask(int MineMapMask[][DIM], int x, int y) { return MineMapMask[y][x]; }
inline int& label(int MineMapLabel[][DIM], int x, int y) { return MineMapLabel[y][x]; }
inline bool	isValid(int x, int y) { return (x >= 0 && x < nx&& y >= 0 && y < ny); }
inline bool	isBomb(int MineMaLabel[][DIM], int x, int y) { return isValid(x, y) && label(x, y) == Bomb; }
inline bool	isEmpty(int MineMapLabel[][DIM], int x, int y) { return isValid(x, y) && label(x, y) == Empty; }

void dig(int MineMapMask[][DIM], int MineMapLabel[][DIM], int x, int y) {			
	if (isValid(x, y) && mask(MineMapMask, x, y) != Open) {  
        //해당 x,y값에 있는 MineMapMAsk요소가 오픈된 상태가 아니라면 오픈으로 변경하고 해당 MineMapLabel[y][x]요소가 비어있는 상태라면(Empty) 그 주변부를 오픈한다.
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
void mark(int MineMapMask[][DIM], int x, int y) {			
    if (isValid(x, y) && mask(MineMapMask, x, y) == Hide)
        mask(MineMapMask, x, y) = Flag;
}
int getBombCount(int MineMapMask[][DIM]) {
    int count = 0;
    for (int y = 0; y < ny; y++)
        for (int x = 0; x < nx; x++)
            if (mask(MineMapMask, x, y) == Flag) count++;
    return count;   //모든 영역을 검사하여 지뢰가 몇 개 남았는지 반환한다.
}
void print(int MineMapMask[][DIM], int MineMapLabel[][DIM]) {					
	system("cls");  //화면을 초기화한다.
	printf("    발견:%2d   전체:%2d\n", getBombCount(MineMapMask), nBomb);
	printf("    1 2 3 4 5 6 7 8 9\n");
	for (int y = 0; y < ny; y++) {
		printf("%2c ", 'A' + y);
		for (int x = 0; x < nx; x++) {
			if (mask(MineMapMask, x, y) == Hide)	printf(" □");		//해당 MapMineMask[y,x]요소가 Hide, 즉 0이라면 □를 출력한다.
			else if (mask(MineMapMask, x, y) == Flag) printf("¤");	//해당 MapMineMask[y,x]요소가 Flag, 즉 2이라면 ¤를 출력한다.
			else {									
				if (isBomb(MineMapLabel, x, y)) printf("※");		    //폭탄이 발견된 칸이라면 ※출력
				else if (isEmpty(MineMapLabel, x, y)) printf("  ");	//Empty상태라면 빈칸을 출력한다.
				else printf("%2d", label(MineMapLabel, x, y));		
			}
		}
		printf("\n");
	}
}
int countNbrBombs(int MineMapMask[][DIM], int MineMapLabel[][DIM], int x, int y) {	
	int count = 0;
	for (int yy = y - 1; yy <= y + 1; yy++)
		for (int xx = x - 1; xx <= x + 1; xx++)
			if (isValid(xx, yy) && label(MineMapLabel, xx, yy) == Bomb)   
            //인수로 넘겨받은 x,y값의 위아래 바로 주변부 MineMapLabel요소에 폭탄이 있는 동시에 xx,yy값이 정상 범주에 있으면 count++를 수행한다.
				count++;
	return count;
}
void init(int MineMapMask[][DIM], int MineMapLabel[][DIM], int total = 9) {
	srand((unsigned int)time(NULL));    //랜덤함수를 설정한다.
	for (int y = 0; y < ny; y++)
		for (int x = 0; x < nx; x++) {			
			mask(MineMapMask, x, y) = Hide;          //MineMapMask배열의 모든 요소를 HIDE상태로 설정한다. 
			label(MineMapLabel, x, y) = 0;            //MineMapLabel배열의 모든 요소를 0으로 초기화한다.
		}
	nBomb = total;                      
	for (int i = 0; i < nBomb; i++) {	
		int x, y;
		do {
			x = rand() % nx;            
			y = rand() % ny;            //x,y값을 임의로 설정한다. (%의 이유는 x,y값이 9보다 작아야하기 때문)
		} while (label(MineMapLabel, x, y) != Empty); //MineMapLabel[y][x]의 요소가 Empty일 때 까지 해당 화일문을 돌리면서 x,y값을 랜덤으로 설정한다.
		label(MineMapLabel, x, y) = Bomb;             //MineMapLabel[y][x]에 폭탄을 설정한다. Bomb = 9
	}
	for (int y = 0; y < ny; y++)			
		for (int x = 0; x < nx; x++)
			if (label(MineMapLabel, x, y) == Empty)               
				label(MineMapLabel, x, y) = countNbrBombs(MineMapMask, MineMapLabel, x, y); 
                 //MineMapLabel[y][x]의 요소에 폭탄이 설정되어있지 않으면 즉, Empty상태이면 countNbrBombs함수를 호출하여 리턴값인 count를 넣는다.
}
bool getPos(int& x, int& y) {		
	printf("\n지뢰(P)행(A-I)열(1-9)\n      입력 --> ");
	bool isBomb = false;
	y = toupper(_getch()) - 'A';			//열을 입력받는다.
	if (y == 'P' - 'A') {                   //입력받은 값이 지뢰P가 함께 들어왔다면 isbomb를 true로 변경한다.
		isBomb = true;                  
		y = toupper(_getche()) - 'A';		//y값을 입력받은 열의 값으로 변경한다.
	}
	x = _getch() - '1';					    //x값을 입력받은 행의 값으로 변경한다.
	return isBomb;
}
int checkDone(int MineMapMask[][DIM], int MineMapLabel[][DIM]) {				
	int count = 0;
	for (int y = 0; y < ny; y++)
		for (int x = 0; x < nx; x++) {
			if (mask(MineMapMask, x, y) != Open) count++;
			else if (isBomb(MineMapLabel, x, y)) return -1;       //만약 Bomb가 있는 MapMineLabel요소가 open되어있다면 -1을 반환한다.
		}
	return (count == nBomb) ? 1 : 0;                //전체 MapMineMask요소를 검사하여 폭탄의 개수와 아직 오픈되지 않은 요소의 개수가 동일하다면 1을 반환한다.
}
void playMineSweeper(int MineMapMask[][DIM], int MineMapLabel[][DIM], int total) {		
	int x, y, status;
	init(MineMapMask, MineMapLabel, total);					//사용자가 설정한 지뢰의 개수만큼 인수를 넘기면서 init함수를 호출한다.
	do {
		print(MineMapMask, MineMapLabel);                    //Print함수를 호출한다.
		bool isBomb = getPos(x, y);	//사용자가 지뢰를 탐색하는지 입력받는다.
		if (isBomb) mark(MineMapMask, x, y);		//사용자로부터 입력받은 x,y값에 있는 요소를 Flag상태로 변환한다.
		else		  dig(MineMapMask, MineMapLabel, x, y);    //지뢰를 탐색하는게 아니라면 해당 요소를 오픈한다.
		status = checkDone(MineMapMask, MineMapLabel);		//checkDone함수를 호출하여 status에 1,0,-1을 대입한다.
	} while (status == 0);			//지뢰를 모두 찾으면 status에 1이 대입되므로 모두 찾을때 까지 반복한다.
	print(MineMapMask, MineMapLabel);
	if (status < 0) 				//status값에 따라 출력을 바꾼다.
		printf("\n실패: 지뢰 폭발!!!\n\n");
	else	printf("\n성공: 탐색 성공!!!\n\n");
}
void main()
{
	int total;
    int MineMapMask[DIM][DIM];
    int MineMapLabel[DIM][DIM];
	printf(" <Mine Sweeper>\n");
	printf(" 매설할 총 지뢰의 개수 입력 : ");
	scanf("%d", &total);        //사용자로부터 지뢰의 개수를 입력받는다.
	playMineSweeper(MineMapMask, MineMapLabel, total);     //해당 함수의 인수로 지뢰의 개수를 넘긴다.
}