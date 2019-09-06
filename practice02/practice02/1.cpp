#include<iostream>
using namespace std;

const int MAX = 99999;

int main()
{
	int i, j, m = 10, n = 20;
	int *data;
	int f[100][100] = { 0 };

	cin >> n >> m;
	data = new int[n];
	for (i = 0; i < n; i++)
	{
		cin >> data[i];
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= m; j++)
		{
			f[i][j] = MAX;
		}
		for (j = 0; j <= (i + 1) / 2; j++)
		{
			if (i - 2 >= 0 && j - 1 >= 0 && data[i] - data[i - 1] > 0)
			{
				int tmp = f[i - 2][j - 1] + (int)pow(data[i] - data[i - 1], 4);
				f[i][j] = tmp < f[i - 1][j] ? tmp : f[i - 1][j];
			}
			else if (i - 1 >= 0 && j == 1 && data[i] - data[i - 1] > 0)
			{
				f[i][j] = (int)pow(data[i] - data[i - 1], 4);
			}
			else if (i - 1 >= 0)
			{
				f[i][j] = f[i - 1][j];
			}
			else
			{
				f[i][j] = 0;
			}
		}
	}
	cout << "output: " << f[i - 1][j - 1] << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= m; j++)
		{
			cout.width(3);
			if (f[i][j] == MAX)
			{
				cout << "MAX" << "   ";
				continue;
			}
			cout << f[i][j] << "   ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}