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
	} // ���� �� ���� ����
	if (y1 == y2)
	{
		return true;
	} // ���� �� ���� ����
	if ((double)(y2 - y1) / (x2 - x1) == 1.0 || (double)(y2 - y1) / (x2 - x1) == -1.0)
	{
		return true;
	} // �밢�� ���� ����
	return false; // ���� ����
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
		cin >> N;	//������ ũ��, ���� ����
		deque<Point> Queen;

		/*
		1. �ϳ��� �ٿ��� �ϳ��� ���� �ö� �� �ִ�.
		2. ���������� �ϳ��� ������ �ϳ��� ���� �ö󰣴�.

		3. DNF�� ���?

		
		*/

		DNF(Queen, 0, N);

		cout << "#" << test_case << " " << answer << endl;
	}
	
}

/*
deque ��뺸�� �迭�� �̿��ϴ°� �Ϲ����� Ǯ�̹�
�迭�� �ε����� ���ȣ, value�� �� ��ȣ�� ��Ī�ؼ� �����ϴ� ���
��Ʈ��ŷ�� ���� ��ġ�� ����� ó���� ������
�̹� ���� x���� �־ ���� �ʿ䰡 ����
�̸� �־��ָ� �ð��� �پ�� �� ����

*/