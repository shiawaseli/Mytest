#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i, j;//i为打印的个数，j为打印的次数
	int floor;//floor为一阶中的行数
	int nrow, row;//row为当前行数，nrow为总行数
	int layer, nlayer;//layer为当前阶数,nlayer为总阶数
	printf("请输入总行数和一阶中的行数：");
	scanf("%d%d", &nrow, &floor);

	for (row = 0; row < nrow; row++)
	{
		nlayer = row / floor + 1;
		for (i = 1; i < nrow - row; i++)
		{
			putchar(' ');
		}
		for (j = 1; j <= nlayer; j++)
		{
			layer = row % floor + 1;
			for (i = 1; i <= 2 * layer - 1; i++)
			{
				putchar('*');
			}
			for (i = 1; i <= 2 * floor - 2 * layer + 1; i++)
			{
				putchar(' ');
			}
		}
		putchar('\n');
	}

	system("pause");
	return 0;
}
