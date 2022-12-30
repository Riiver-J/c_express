#include<stdio.h>	// 표준 입출력 라이브러리
#include<windows.h>	// 시스템 콘솔 헤더
#include<stdlib.h>	// 난수생성
#include<time.h>	// rand함수 사용
#include<conio.h>	// getch()함수 사용을 위한 헤더

void gotoxy(int x, int y);

#define randomize() srand((unsigned)time(NULL)	// 자동으로 난수발생기 초기화, 매크로함수
#define random(n) (rand()%(n))	// 난수의 범위를 초기화, 매크로함수
#define MAXFLOWER 2000
#define delay(n) Sleep(n)

typedef struct // 구조체 정의
{
	BOOL exist;	// 존재 여부 설정
	char ch;	// 출력할 문자
	int x, y;	// 현재 좌표
	int distance;	//이동할 거리
	int nFrame;	// 속도
	int nStay;	// 속도 통제
} Flower;	// 구조체 정의

Flower F[MAXFLOWER];	// 구조체 배열

void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main()	// main함수
{
	int lotto = 2;	// 랜덤으로 꽃 생성확률, 초기화
	int frame = 200;
	int i;

	randomize();

	system("mode con cols=120 lines=20"); //cols = 칸/행 (가로)  lines = 줄/열 (세로)

	while (1) 
	{
		if (random(lotto) == 0)	// 확률마다 꽃 생성
		{
			for (i = 0; i < MAXFLOWER; i++)
			{
				if (F[i].exist == FALSE)
				{
					F[i].exist = TRUE;
					F[i].ch = '@';
					F[i].x = random(120);
					F[i].y = random(20);
					F[i].distance = random(8) + 5;
					F[i].nFrame = F[i].nStay = random(15) + 5;
					break;
				}
			}
		}

		for (i = 0; i < MAXFLOWER; i++)
		{
			if (F[i].exist == FALSE)	// 꽃이 존재하지 않으면
				continue;	// 다시 돌아간다
			if (--F[i].nStay == 0)	// 주기가 0이 되면
			{
				F[i].nStay = F[i].nFrame;	// 위치를 공백으로 지운다
				gotoxy(F[i].x, F[i].y);	
				_putch('  ');
				
				if (++F[i].y < F[i].distance)
				{
					if (random(2) == 0)
					{
						++F[i].x;
					}
					else
					{
						--F[i].x;
					}

					gotoxy(F[i].x, F[i].y);
					_putch(F[i].ch);
				}
				else
				{
					F[i].exist = FALSE;
				}
			}
		}
		delay(1000 / frame);
	}

	_getch();
	return 0;
	
}