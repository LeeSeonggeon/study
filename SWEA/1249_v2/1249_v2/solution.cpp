#include<iostream>
#include<cstdio>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

#undef INT_MAX
#define INT_MAX 999999999

int** Maze; // 미로
int** dist;
int** cost;

struct Point {
	int x;
	int y;

	void insert(int x1, int y1)
	{
		x = x1;
		y = y1;
	}
};

bool isValid(Point point, int N)
{
	if (point.x < 0 || point.x >= N)
	{
		return false;
	}
	if (point.y < 0 || point.y >= N)
	{
		return false;
	}

	return true;
}

bool sort_cost(Point a, Point b)
{
	return Maze[a.y][a.x] < Maze[b.y][b.x];
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int N; //미로 크기
	string line;


	int answer;


	FILE* fp;
	freopen_s(&fp, "input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		answer = INT_MAX;
		cin >> N;
		Maze = new int* [N];
		dist = new int* [N];
		cost = new int* [N];
		for (int i = 0; i < N; i++)
		{
			Maze[i] = new int[N];
			dist[i] = new int[N]();
			cost[i] = new int[N]();
		}

		for (int i = 0; i < N; i++)
		{
			cin >> line;
			for (int j = 0; j < N; j++)
			{
				Maze[i][j] = line[j] - '0';
			}
		}

		int x = 0;
		int y = 0;
		int order = 1;	//순서
		int before_cost = 0;	//이전 단계에서의 걸린 시간
		int dx[4] = { 1, 0, -1 ,0 };
		int dy[4] = { 0, 1, 0, -1 };

		queue<Point> points;
		queue<int> orders;
		queue<int> costs;

		Point point;
		point.insert(x, y);
		points.push(point);

		orders.push(order);
		costs.push(before_cost);

		queue<Point> sortP;


		while (true)
		{
			//변수 꺼내기
			point = points.front(); points.pop();
			x = point.x; y = point.y;
			order = orders.front(); orders.pop();
			before_cost = costs.front(); costs.pop();


			if (x == N - 1 && y == N - 1)
			{
				break;
			}
			if (dist[y][x] != 0)
			{
				continue;
			}//이미 방분한 곳은 패스

			//방문한 적 없는 곳
			
			dist[y][x] = order;
			cost[y][x] = before_cost + Maze[y][x];

			//현재 위치의  사방위 위치 값 저장
			int nx;
			int ny;
			for (int i = 0; i < 4; i++)
			{
				nx = x + dx[i];
				ny = y + dy[i];

				Point temp = { nx, ny };
				if (isValid(temp, N))
				{
					sortP.push(temp);
				}

			}
			//저장한 위치값에서의 보수 시간으로 오름차순 정렬 진행
			for (int i = 0; i < sortP.size()-1; i++)
			{
				if(sort_cost(sortP., sortP[i + 1]))

			}

		}



		cout << "#" << test_case << " " << answer << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}