#include <iostream>
#include <cstdio>

using namespace std;

/*
N x N �迭 ���� ���ڴ� �ش� ������ �����ϴ� �ĸ��� ������ �ǹ��Ѵ�.	(5<=N<=15)
M x M ũ���� �ĸ�ä�� �� �� ������ �ִ��� ���� �ĸ��� ���̰��� �Ѵ�. (2 <= M <= N)
���� �ĸ��� ������ ���϶� (������ �ĸ� ���� K <= 30)

�Է�
1. test_case�� ����
2. N M
3. N x N �迭

���
#t (���� �ĸ� ����)

*/

int main(int argc, char** argv)
{
	int test_case;
	int T;
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


	int N = 0;
	int M = 0;
	int** arr;


	int dead_fly;

	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		dead_fly = 0;

		cin >> N;
		cin >> M;
		arr = new int* [N];
		for (int i = 0; i < N; i++)
		{
			arr[i] = new int[N]();
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> arr[i][j];
			}
		}
		int max = 0;
		for (int i = 0; i <= N - M; i++)
		{
			for (int j = 0; j <= N - M; j++)
			{
				for (int k = 0; k < M; k++)
				{
					for (int t = 0; t < M; t++)
					{
						dead_fly += arr[i+k][j+t];
						if (dead_fly >= max)
						{
							max = dead_fly;
						}
					}
				}
				dead_fly = 0;
			}
		}

		cout << "#" << test_case << " " << max << endl;

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