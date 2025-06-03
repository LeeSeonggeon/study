#include<iostream>
#include<cstdio>
#include <string>
using namespace std;

/*
������ �ڵ�
DFS�� ������
����� ������ ���� -> �����ؼ� ����� �°� ���� (sample 1~4���� Ȯ��)
				-> visit[y][x] = false �ϴ� Ÿ�̹��� ����(return ���� ���ִ� �κ��� �־���� ��)

*/

//��, ��, ��, �� ����
//�ϴ� ������ �»�ܿ��� ���ϴ��̾ �̷��� ��ġ��
int dx[4] = {1, 0, 0, -1};	
int dy[4] = {0, 1, -1, 0};	
int answer;	// �ּ� �۾� �ð�
int** arr;
bool** visit;

bool isvisited(int x, int y)
{
	if (visit[y][x] == true)
	{
		return true;
	}//�湮 ��� ����
	return false;	//�湮�� �� ����
}

bool isvalid(int x, int y, int N)
{
	if (x < 0 || x >= N)
	{
		return false;
	}//x ��ǥ ��ȿ�� Ȯ��
	if (y < 0 || y >= N)
	{
		return false;
	}//y��ǥ ��ȿ�� Ȯ��
	if (isvisited(x, y))
	{
		return false;
	}//�湮 ����� ������ false

	return true;
}

void solution(int** arr, int N, int x, int y, int result)
{
	visit[y][x] = true;
	if (x == N - 1 && y == N - 1)
	{
		answer = min(answer, result);
		visit[y][x] = false;
		return;
	}//Ż���� ��ǥ�̸� �񱳸� �����ؼ� ���� ���� ����


	if (answer < result)
	{
		visit[y][x] = false;
		return;
	}//���� �߿� answer ���� Ŀ���� �� �̻� ������ �ǹ̰� ����

	int nx;
	int ny;

	for (int i = 0; i < 4; i++)
	{
		nx = x + dx[i];
		ny = y + dy[i];

		if (!isvalid(nx, ny, N))
		{
			continue;
		}	//��ȿ���� ���� ��ġ�� �н�

		result += arr[ny][nx];
		
		solution(arr, N, nx, ny, result);
		result -= arr[ny][nx];
	}
	visit[y][x] = false;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int N;
	string input;
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
		answer = INT_MAX;
		cin >> N;
		arr = new int* [N];
		visit = new bool* [N];
		for (int i = 0; i < N; i++)
		{
			arr[i] = new int[N];
			visit[i] = new bool[N]();	//�⺻ false�� �����
		}

		for (int i = 0; i < N; i++)
		{
			cin >> input;
			for (int j = 0; j < N; j++)
			{
				arr[i][j] = input[j] - '0';
			}

		}

		solution(arr, N, 0, 0, arr[0][0]);

		for (int i = 0; i < N; i++)
		{
			delete[] arr[i];
			delete[] visit[i];
		}
		delete[] arr;
		delete[] visit;

		cout << "#" << test_case << " " << answer << endl;
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}