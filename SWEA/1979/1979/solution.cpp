#include<iostream>
#include <cstdio>
using namespace std;

bool isUpWall(int **arr, int y, int x)
{
	if (arr[y][x] == 0)
	{
		return false;
	}

	if (y == 0 || arr[y - 1][x] == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}//���� ��ġ���� ���� ���� �ִ°�? �׸��� �Ʒ��� �� �� �ִ°�?

bool isLeftWall(int** arr, int y, int x)
{
	if (arr[y][x] == 0)
	{
		return false;
	}

	if (x == 0 || arr[y][x - 1] == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}//���� ��ġ���� ������ ���� �ִ°�?

bool isDownWall(int** arr, int y, int x, int N)
{
	if (arr[y][x] == 0)
	{
		return false;
	}

	if (y == N-1  || arr[y + 1][x] == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}//���� ��ġ���� �Ʒ��� ���� �ִ°�?

bool isRightWall(int** arr, int y, int x, int N)
{
	if (arr[y][x] == 0)
	{
		return false;
	}

	if (x == N-1 || arr[y][x + 1] == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}//���� ��ġ���� �������� ���� �ִ°�?


int solution(int** arr, int y, int x, int N, int K)
{
	int count = 0;
	if (isUpWall(arr, y, x))
	{
		bool check = true;
		if (y + K - 1 >= N) //���� ������ �������� ������ ��Ȳ�̸� ó������� �Ѵ�.
		{
			check = false;
		}
		else if (isDownWall(arr, y + K - 1, x, N))
		{
			for (int i = y; i <= y + K - 1; i++)
			{
				if (arr[i][x] == 0)
				{
					check = false;
					break;
				}
			}
			if (check == true) count++;
		}
	}//�������� ���Ȯ��

	if (isLeftWall(arr, y, x)) 
	{
		
		bool check = true;
		if (x + K - 1 >= N) //���� ������ �������� ������ ��Ȳ�̸� ó������� �Ѵ�.
		{
			check = false;
		}
		else if (isRightWall(arr, y, x + K - 1, N))
		{
			for (int i = x; i <= x + K - 1; i++)
			{
				if (arr[y][i] == 0)
				{
					check = false;
					break;
				}
			}
			if (check == true) count++;
		}
	}//���������� ���� ���

	return count;
}


int main(int argc, char** argv)
{
	int test_case;
	int T;
	int** arr;
	int N;
	int K;

	int K_count = 0;
	/*
	   �Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
	   ������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   //�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
	   freopen �Լ��� �̿��ϸ� ���� cin �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
	   ���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
	   freopen �Լ��� ����ϱ� ���ؼ��� #include <cstdio>, Ȥ�� #include <stdio.h> �� �ʿ��մϴ�.
	   ��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
	*/
	FILE* fp;
	freopen_s(&fp, "input.txt", "r", stdin);
	cin >> T;
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		K_count = 0;
		cin >> N >> K;
		arr = new int* [N];
		for (int i = 0; i < N; i++)
		{
			arr[i] = new int[N]();
			for (int j = 0; j < N; j++)
			{
				cin >> arr[i][j];
			}
		}
		
		/*
		0 0 1 1 1
		1 1 1 1 0
		0 0 1 0 0
		0 1 1 1 1
		1 1 1 0 1

		K= 2
		3, 3
		N = 5
		N-K = 3
		
		�ܾ��� ��������:
		1. �Ʒ��� �������� ��� -> ������ ���� ����
		2. ���������� ���� ��� -> ������ ���� ���� 

		�ܾ��� ������:
		1. �Ʒ��� �������� ��� -> �Ʒ��� ���� ����
		2. ���������� ���� ��� -> �������� ���� ����
		*/

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				K_count += solution(arr, i, j, N, K);
			}
		}

		
		for (int i = 0; i < N; i++)
		{
			delete[] arr[i];
		}
		delete[] arr;

		cout << "#" << test_case << " " << K_count << endl;
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}