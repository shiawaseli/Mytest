#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 20
#define WIDTH 2

char digit[10][5][3] = {
	{{' ', '-', ' '}, {'|', ' ', '|'}, {' ', ' ', ' '}, {'|', ' ', '|'}, {' ', '-', ' '}},//0
	{{' ', ' ', ' '}, {' ', ' ', '|'}, {' ', ' ', ' '}, {' ', ' ', '|'}, {' ', ' ', ' '}},//1
	{{' ', '-', ' '}, {' ', ' ', '|'}, {' ', '-', ' '}, {'|', ' ', ' '}, {' ', '-', ' '}},//2
	{{' ', '-', ' '}, {' ', ' ', '|'}, {' ', '-', ' '}, {' ', ' ', '|'}, {' ', '-', ' '}},//3
	{{' ', ' ', ' '}, {'|', ' ', '|'}, {' ', '-', ' '}, {' ', ' ', '|'}, {' ', ' ', ' '}},//4
	{{' ', '-', ' '}, {'|', ' ', ' '}, {' ', '-', ' '}, {' ', ' ', '|'}, {' ', '-', ' '}},//5
	{{' ', '-', ' '}, {'|', ' ', ' '}, {' ', '-', ' '}, {'|', ' ', '|'}, {' ', '-', ' '}},//6
	{{' ', '-', ' '}, {' ', ' ', '|'}, {' ', ' ', ' '}, {' ', ' ', '|'}, {' ', ' ', ' '}},//7
	{{' ', '-', ' '}, {'|', ' ', '|'}, {' ', '-', ' '}, {'|', ' ', '|'}, {' ', '-', ' '}},//8
	{{' ', '-', ' '}, {'|', ' ', '|'}, {' ', '-', ' '}, {' ', ' ', '|'}, {' ', '-', ' '}}//9
};

int main2()
{
	char ch;//ch用于处理剩余字符。
	int n[MAX], num = 0;//n[MAX]用于存放输入值；num为存放的个数。
	int height, width, flag = 0;//height管理输出数字的高度；width用于管理数字的宽度；flag用于高度的重置。
	int i, j, k;//i用于选择输出的数字；j用于控制输出行；k用于控制输出列。

	printf("请输入要打印的数字(包括空格最多%d个)：", MAX);
	while(num != MAX && ((n[num] = getchar() - '0') != '\n' - '0'))
	{
		num++;
	}
	while (num == MAX && (ch = getchar()) != '\n')//处理剩余字符
	{
		printf("丢弃%c\n", ch);
	}

	for (j = 0; j < 5; j++)
	{
	begin:
		for (i = 0; i < num; i++)
		{
			//数字的分隔
			if (n[i] == ' ' - '0')
			{
				printf("     ");
				continue;
			}
			for (k = 0; k < 3; k++)
			{
				putchar(digit[n[i]][j][k]);
				//调整宽度
				for (width = WIDTH; width != 1 && k == 1; )
				{
					width--;
					putchar(digit[n[i]][j][k]);
				}
			}
			putchar(' ');
		}
		putchar('\n');
		//调整高度
		if (flag == 0)
		{
			height = WIDTH;
		}
		while(j % 2 == 1 && height != 1)
		{
			height--;
			flag = 1;//1表示正在调整高度，0表示调整结束。
			goto begin;
		}
		flag = 0;
	}

	system("pause");
	return 0;
}
