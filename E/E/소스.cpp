#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

/*
2
5 5
S-###
-----
##---
E#---
---##
3 3
S#E
-#-
---


*/

int N, M;
int cnt;
int check[101][101];
int visit[101][101];
char map[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void BFS(int x, int y)
{

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			check[i][j] = 0;
			visit[i][j] = 0;
		}
	}

	visit[x][y] = 1;

	queue<pair<int, int> > q;
	q.push(make_pair(x, y));

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (0 <= next_x && next_x < N && 0 <= next_y && next_y < M)
			{

				if (map[next_x][next_y] == '-' && visit[next_x][next_y] == 0 || map[next_x][next_y] == 'E')
				{
					check[next_x][next_y] = check[x][y] + 1;
					visit[next_x][next_y] = 1;
					q.push(make_pair(next_x, next_y));
				}

			}

		}
	}
}

int main(void)
{
	cin >> cnt;
	while (cnt--) {
		cin >> N >> M;
		for (int i = 0; i < N; i++)
		{
			cin >> map[i];
		}

		int x = 0, y = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 'S') {
					x = i;
					y = j;
					break;
				}
			}
		}

		BFS(x, y);

		x = 0, y = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 'E') {
					x = i;
					y = j;
				}
			}
		}
		if (check[x][y] == 0) {
			cout << -1;
		}
		if (N == 1 && M == 1) {
			cout << 1;
		}
		else {
			printf("%d\n", check[x][y]);
		}
	}
}
