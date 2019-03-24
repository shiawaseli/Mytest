#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#define HEIGHT 1

void PrintWidth();
void PrintHeight();

int main()
{
	int i, j;//iΪ��ӡ�ĸ�����jΪ��ӡ�Ĵ�����
	int floor;//floorΪһ���е�������
	int row, nrow;//rowΪ��ǰ������nrowΪ��������
	int layer, nlayer;//layerΪ��ǰ���ڵ�������nlayerΪ��ǰ������
	printf("��������������һ���е�������");
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
			//��ӡ�ָ��Ŀո񣬵�����ӡ���Ŀո�
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
	int width;//widthΪһ����*��*�ļ����

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