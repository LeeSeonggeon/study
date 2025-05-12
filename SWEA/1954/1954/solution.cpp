#include<iostream>
#include <cstdio>
using namespace std;

/*
����

ū �׸���� ������� �׷�������

ex)
N = 4

1. 
1 2 3 4
12 0 0 5
11 0 0 6
10 9 8 7

2.
1 2 3 4
12 13 14 5
11 16 15 6
10 9 8 7

�̷��� ���� �簢�� ���� �־��ְ� ������� ���� �׸� ���� �־��ֱ⸦ �ݺ�

�� �׸��� ũ�⿡ ���� ��� ���ڰ� ���°�?
4n-4���� ���ڰ� �� �� ����(n�� �׸��� �� ���� ����)
N=4�� ��� ù �׸� ���� ������ ������ 4*4-4 = 12�� 
�� ��° �׸� ���� ������ ������ 4*2-4 = 4��

*/

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int N;

	int num;		//�迭�� �Է��� ����
	int** arr;		//������ �迭
	int num_count;	//�׸� ��� ���ڰ� �ʿ��Ѱ�
	int x;
	int y;
	int dir;
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };

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
		//�غ�
		cin >> N;

		x = 0;
		y = 0;
		dir = 0;
		arr = new int* [N];
		for (int i = 0; i < N; i++)
		{
			arr[i] = new int[N]();
		}//����� ���� ���� �����

		//�˰���
		/*
		//�ۿ� �׸���� �׸��� ���� ä�������� ���
		int num = 1;
		int start = 0;
		int end = N - 1;

		while (start <= end) {
			// ���� ����
			for (int i = start; i <= end; i++)
				arr[start][i] = num++;

			// ������ ����
			for (int i = start + 1; i <= end; i++)
				arr[i][end] = num++;

			// �Ʒ��� ���� (������)
			for (int i = end - 1; i >= start; i--)
				arr[end][i] = num++;

			// ���� ���� (������)
			for (int i = end - 1; i > start; i--)
				arr[i][start] = num++;

			start++;
			end--;
		}
		*/

		//ȸ������ ���鼭 �׷������� ���
		for (num = 1; num <= N * N; num++)
		{
 			arr[y][x] = num;

			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N || arr[ny][nx] != 0) {
				dir = (dir + 1) % 4; // ���� ��ȯ
				nx = x + dx[dir];
				ny = y + dy[dir];
			}

			x = nx;
			y = ny;
		}


		//���
		cout << "#" << test_case << endl;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}

		for (int i = 0; i < N; i++)
		{
			delete[] arr[i];
		}
		delete[] arr;
	}

	if (fp != nullptr)
	{
		fclose(fp);
	}

	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}