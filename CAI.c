// Copyright (c) Penyo. All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define POINT_SINGLE 1 // Define single question score
#define POINT_LEVELUP 4 // Define the qualifying score
#define MOUNT_UPPER 5 // Define the number of questions per level

struct state {
	char mode[128 - 4 * 4]; // User selected mode
	int level, score, mount, chance; // Level, the level score, this question wrong times and the number of questions answered
}player;

void Menu(), NumGenerator(), Interactor(int a, int b);
int Calc(int a, int b);

int main()
{
	player.level = 1, player.score = 0;
	Menu();
}

void Menu() // Main interface
{
	system("cls");
	printf("\n\
                      你好！欢迎游玩 算术游戏\n\
  ----------------------------------------------------------------\n\
          你可以选择加、减、乘和除四则运算中的任一种运算进行挑\n\
      战。游戏开始，屏幕上随机出现两个数（一位数），你需要给出\n\
      正确的答案，若答错了可重新输入，但每道题只有最多 5 次的尝\n\
      试机会，机会用完后直接进入下一题。\n\
          每题 %d 分，总共 %d 题，达到 %d 分后可晋级，即进行两位\n\
      数计算的挑战。再次达到 %d 分即挑战成功。\n\
  ----------------------------------------------------------------\n\
                        输入 1 进入加法模式\n\
                        输入 2 进入减法模式\n\
                        输入 3 进入乘法模式\n\
                        输入 4 进入除法模式\n\n\
                            ___________\b\b\b\b\b", POINT_SINGLE, MOUNT_UPPER, POINT_LEVELUP, POINT_LEVELUP);
	scanf("%s", player.mode);
	while ((player.mode[1] = getchar()) != '\n'); // Clear cache
	NumGenerator();
}

void NumGenerator() // Generation module
{
	int a, b; // Operand
	system("cls");
	srand(time(NULL));
	if (player.level == 1) // Level verification
		a = rand() % 10, b = rand() % 10;
	else if (player.level == 2)
		a = rand() % 90 + 10, b = rand() % 90 + 10;
	else
	{
		printf("挑战成功了！\n");
		system("pause");
		exit(0);
	}
	if ((player.mode[0] == '2' && a - b < 0) || (player.mode[0] == '4' && a % b != 0)) // Validity verification
		NumGenerator();
	Interactor(a, b);
}

void Interactor(int a, int b) // Interactive module
{
	char chOrigin[128]; // Unprocessed user input result
	int ch = EOF; // Processed user input results
	system("cls");
	if (player.score >= POINT_LEVELUP) // Promotion verification
	{
		player.level++, player.score = 0, player.mount = 0;
		NumGenerator();
	}
	if (player.score < POINT_LEVELUP && player.mount >= MOUNT_UPPER) // Failure verification
	{
		printf("好好学习吧！\n");
		system("pause");
		exit(0);
	}
	if (player.chance >= 5) // Error count verification
	{
		player.mount++, player.chance = 0;
		NumGenerator();
	}
	printf("\n\
                       你现在正处于：模式 %c\n\
  ----------------------------------------------------------------\n\n\
                       当前成绩：%d 级 %d 分\n\
                   本级已答 %d 题，本题已错 %d 次\n\n\
  ----------------------------------------------------------------\n\
                            ", player.mode[0], player.level, player.score, player.mount, player.chance);
	switch (player.mode[0])
	{
	case '1':printf("%d + %d = ", a, b); break;
	case '2':printf("%d - %d = ", a, b); break;
	case '3':printf("%d x %d = ", a, b); break;
	case '4':printf("%d ÷ %d = ", a, b); break;
	case 'i':system("cls"); printf("Copyright (c) Penyo. All rights reserved.\n"); system("pause"); main(); break;
	default:Menu();
	}
	gets(chOrigin);
	if (atof(chOrigin) >= 0 && atof(chOrigin) <= 99 * 99)
		ch = atof(chOrigin);
	if (Calc(a, b) == ch) // Extra points or retest verification
	{
		player.score += POINT_SINGLE, player.mount++, player.chance = 0;
		NumGenerator();
	}
	else
	{
		player.chance++;
		Interactor(a, b);
	}
}

int Calc(int a, int b) // Calculation module
{
	switch (player.mode[0])
	{
	case '1':return a + b; break;
	case '2':return a - b; break;
	case '3':return a * b; break;
	case '4':return a / b;
	}
}
