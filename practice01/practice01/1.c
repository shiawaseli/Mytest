#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i, j;//iΪ��ӡ�ĸ�����jΪ��ӡ�Ĵ���
	int floor;//floorΪһ���е�����
	int nrow, row;//rowΪ��ǰ������nrowΪ������
	int layer, nlayer;//layerΪ��ǰ����,nlayerΪ�ܽ���
	printf("��������������һ���е�������");
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
