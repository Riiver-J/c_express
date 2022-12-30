#include<stdio.h>	// ǥ�� ����� ���̺귯��
#include<windows.h>	// �ý��� �ܼ� ���
#include<stdlib.h>	// ��������
#include<time.h>	// rand�Լ� ���
#include<conio.h>	// getch()�Լ� ����� ���� ���

void gotoxy(int x, int y);

#define randomize() srand((unsigned)time(NULL)	// �ڵ����� �����߻��� �ʱ�ȭ, ��ũ���Լ�
#define random(n) (rand()%(n))	// ������ ������ �ʱ�ȭ, ��ũ���Լ�
#define MAXFLOWER 2000
#define delay(n) Sleep(n)

typedef struct // ����ü ����
{
	BOOL exist;	// ���� ���� ����
	char ch;	// ����� ����
	int x, y;	// ���� ��ǥ
	int distance;	//�̵��� �Ÿ�
	int nFrame;	// �ӵ�
	int nStay;	// �ӵ� ����
} Flower;	// ����ü ����

Flower F[MAXFLOWER];	// ����ü �迭

void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main()	// main�Լ�
{
	int lotto = 2;	// �������� �� ����Ȯ��, �ʱ�ȭ
	int frame = 200;
	int i;

	randomize();

	system("mode con cols=120 lines=20"); //cols = ĭ/�� (����)  lines = ��/�� (����)

	while (1) 
	{
		if (random(lotto) == 0)	// Ȯ������ �� ����
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
			if (F[i].exist == FALSE)	// ���� �������� ������
				continue;	// �ٽ� ���ư���
			if (--F[i].nStay == 0)	// �ֱⰡ 0�� �Ǹ�
			{
				F[i].nStay = F[i].nFrame;	// ��ġ�� �������� �����
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