#include <iostream>

using namespace std;

const int MAX = 500;
int cow_bowling[MAX][MAX + 1];

int main()
{
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			cin >> cow_bowling[i][j];

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0) {
				cow_bowling[i][j] += cow_bowling[i - 1][j];
			}
			else {
				if (cow_bowling[i - 1][j - 1] < cow_bowling[i - 1][j]) {
					cow_bowling[i][j] += cow_bowling[i - 1][j];
				}
				else {
					cow_bowling[i][j] += cow_bowling[i - 1][j - 1];
				}
			}
		}
	}

	int max = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			if (cow_bowling[i][j] > max)
				max = cow_bowling[i][j];

	cout << max;

	return 0;
}