#include "start.h"


int a[Width + 2][Height + 2];
int x = 1, y = 1, k = 1;

void main()
{
	system("mode con:cols=30 lines=15");
	menu();
	system("pause>null");
	system("mode con:cols=60 lines=20");
	go();
}

void go()
{
	while (1)
	{
		map();
		input(&k);
		check(&k);
		if (check(&k) == 1)break;

		if (k == 1)
		{
			k = 2;
		}
		else
		{
			k = 1;
		}
	}
	map();
	gotoxy(2 * Width + 5, 16);
	printf("플레이어 %d 승리\n", k);
	system("pause");
}

void menu()
{
	printf("\n");
	printf("  □□□□□□□□□□□□□\n");
	printf("  □□□■□□□□■■■□□\n");
	printf("  □□■□■□□□■□■□□\n");
	printf("  □□■□■□□□■■■□□\n");
	printf("  □□□■□□□□□■□□□\n");
	printf("  □□□□□□□□■■■□□\n");
	printf("  □□□■□□□□□□□□□\n");
	printf("  □□□■□□□□■■■□□\n");
	printf("  □□■■■□□□□□■□□\n");
	printf("  □□□□□□□□□□□□□\n");
	printf("            2plyaer\n");
	printf("        press the ENTER\n");
}
void input(int *p)
{
	int key;

	key = getch();
	if (key == 244)
	{
		key = getch();
	}

	switch (key)
	{
	case LEFT:
		if (x>0)
		{
			x--;
		}
		break;

	case RIGHT:
		if (x<Width - 1)
		{
			x++;
		}
		break;

	case UP:
		if (y>0)
		{
			y--;
		}
		break;

	case DOWN:
		if (y<Height - 1)
		{
			y++;
		}
		break;

	case SPACE:
		if (a[y][x] != 0)
		{
			input(&k);
		}
		else if (*p == 1)
		{
			a[y][x] = 1;
		}
		else if (*p == 2)
		{
			a[y][x] = 2;
		}
		break;

		/*case BACKSPACE :
		if(a[y][x]!=0)
		{
		a[y][x]=0;
		}
		break;*/
	}
}

void map()
{
	int i, j;
	system("cls");

	for (i = 0; i<Height; i++)
	{
		for (j = 0; j<Width; j++)
		{
			if (a[i][j] == 0)
			{
				printf("┼");
			}
			else if (a[i][j] == 1)
			{
				printf("○");
			}
			else if (a[i][j] == 2)
			{
				printf("●");
			}
		}
		printf("\n");
	}

	gotoxy(2 * Width + 5, 5);
	printf("게임 방법");
	gotoxy(2 * Width + 5, 6);
	printf("조작 : 방향키");
	gotoxy(2 * Width + 5, 7);
	printf("돌 놓기 : SPACE");
	//gotoxy(2*Width+5,8);
	//printf("무르기 : BACKSPACE");
	gotoxy(2 * x, y);
}

int check(int *p)
{
	int i, sum = 0;

	for (i = -5; i <= 5; i++)
	{
		if (a[y][x + i] == *p)
		{
			sum++;
			if (sum == 5)
			{
				return 1;
			}
		}
		else
		{
			sum = 0;
		}
	}

	for (i = -5; i <= 5; i++)
	{
		if (a[y + i][x] == *p)
		{
			sum++;
			if (sum == 5)
			{
				return 1;
			}
		}
		else
		{
			sum = 0;
		}
	}

	for (i = -5; i<5; i++)
	{
		if (a[y + i][x + i] == *p)
		{
			sum++;
			if (sum == 5)
			{
				return 1;
			}
		}
		else
		{
			sum = 0;
		}
	}

	for (i = -5; i<5; i++)
	{
		if (a[y + i][x - i] == *p)
		{
			sum++;
			if (sum == 5)
			{
				return 1;
			}
		}
		else
		{
			sum = 0;
		}
	}
}

void gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}