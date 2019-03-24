#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#define HEIGHT 1

void PrintWidth();
void PrintHeight();

int main()
{
	int i, j;//i为打印的个数；j为打印的次数。
	int floor;//floor为一阶中的行数。
	int row, nrow;//row为当前行数；nrow为总行数。
	int layer, nlayer;//layer为当前阶内的行数；nlayer为当前阶数。
	printf("请输入总行数和一阶中的行数：");
	scanf("%d%d", &nrow, &floor);

	for (row = 0; row < nrow; row++)
	{
		nlayer = row / floor + 1;
		for (i = 1; i < nrow - row; i++)
		{
			putchar(' ');
			PrintWidth();
		}
		for (j = 1; j <= nlayer; j++)
		{
			layer = row % floor + 1;
			for (i = 1; i <= 2 * layer - 1; i++)
			{
				putchar('*');
				PrintWidth();
			}
			//打印分隔的空格，但不打印最后的空格
			if (j != nlayer)
			{
				for (i = 1; i <= 2 * floor - 2 * layer + 1; i++)
				{
					putchar(' ');
					PrintWidth();
				}
			}
		}
		putchar('\n');
		PrintHeight();
	}

	system("pause");
	return 0;
}

void PrintWidth()
{
	int width;//width为一层中*与*的间隔。

	for (width = 2 * HEIGHT; width != 0; width--)
	{
		putchar(' ');
	}
}

void PrintHeight()
{
	int height;

	for (height = HEIGHT; height != 0; height--)
	{
		putchar('\n');
	}
}