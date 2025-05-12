#include <iostream>
#include <cstdio>
#include <deque>

using namespace std;

int answer = 0;

struct Point
{
	int x;
	int y;
};

bool QA(int y1, int x1, int y2, int x2)
{
	if (x1 == x2)
	{
		return true;
	} // 같은 열 공격 성공
	if (y1 == y2)
	{
		return true;
	} // 같은 행 공격 성공
	if ((double)(y2 - y1) / (x2 - x1) == 1.0 || (double)(y2 - y1) / (x2 - x1) == -1.0)
	{
		return true;
	} // 대각선 공격 성공
	return false; // 공격 실패
}

void DNF (deque<Point> Queen, int y, int N)
{
	if (!Queen.empty() && Queen.size() != 1)
	{
		int x1, y1;
		int x2, y2;
		for (int i = 0; i < Queen.size() - 1; i++)
		{
			x1 = Queen.at(i).x;
			y1 = Queen.at(i).y;

			x2 = Queen.at(Queen.size() - 1).x;
			y2 = Queen.at(Queen.size() - 1).y;

			if (QA(y1, x1, y2, x2) == true)
			{
				return;
			}
		}
	}

	if (y == N)
	{
		answer++;
		return;
	}

	Point point;
	for (int i = 0; i < N; i++)
	{
		point.x = i;
		point.y = y;
		Queen.push_back(point);
		DNF(Queen, y + 1, N);
		Queen.pop_back();
	}
	return;
}

int main(int** argv, int* argc)
{
	int test_case;
	int T;
	int N;

	//FILE* fp;
	//freopen_s(&fp, "input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; test_case++)
	{
		answer = 0;
		cin >> N;	//보드의 크기, 퀸의 개수
		deque<Point> Queen;

		/*
		1. 하나의 줄에는 하나의 퀸만 올라갈 수 있다.
		2. 마찬가지로 하나의 열에는 하나의 퀸만 올라간다.

		3. DNF의 사용?

		
		*/

		DNF(Queen, 0, N);

		cout << "#" << test_case << " " << answer << endl;
	}
	
}

/*
deque 사용보다 배열을 이용하는게 일반적인 풀이법
배열의 인덱스는 행번호, value는 열 번호로 매칭해서 저장하는 방식
백트레킹때 열이 겹치는 경우의 처리가 미흡함
이미 사용된 x값도 넣어서 비교할 필요가 없음
이를 넣어주면 시간도 줄어들 수 있음

*/