#include<iostream>
#include<cstdio>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

#undef INT_MAX
#define INT_MAX 999999999

int** Maze; // �̷�
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
	int N; //�̷� ũ��
	string line;


	int answer;


	FILE* fp;
	freopen_s(&fp, "input.txt", "r", stdin);
	cin >> T;
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
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
		int order = 1;	//����
		int before_cost = 0;	//���� �ܰ迡���� �ɸ� �ð�
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
			//���� ������
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
			}//�̹� ����� ���� �н�

			//�湮�� �� ���� ��
			
			dist[y][x] = order;
			cost[y][x] = before_cost + Maze[y][x];

			//���� ��ġ��  ����� ��ġ �� ����
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
			//������ ��ġ�������� ���� �ð����� �������� ���� ����
			for (int i = 0; i < sortP.size()-1; i++)
			{
				if(sort_cost(sortP., sortP[i + 1]))

			}

		}



		cout << "#" << test_case << " " << answer << endl;
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}