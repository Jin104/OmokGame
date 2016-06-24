#pragma once
#include <stdio.h>
#include <conio.h>
#include <Windows.h>

#define Height 15
#define Width 15

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ESC 27
#define SPACE 32
#define BACKSPACE 8

void go();
void menu();
void input(int *p);
void map();
int check(int *p);

void gotoxy(int x, int y);