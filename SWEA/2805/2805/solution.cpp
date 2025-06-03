#include<iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int N;
	string line;
	int** arr;
	int half_idx;

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
		int answer = 0;
		cin >> N;
		half_idx = N / 2;
		arr = new int*[N];
		for (int i = 0; i < N; i++)
		{
			arr[i] = new int[N]();
		}

		//�Է�
		for (int i = 0; i < N; i++)
		{
			cin >> line;

			for (int j = 0; j < N; j++)
			{
				arr[i][j] = line[j] - '0';
			}
		}

		//�˰���
		int left = half_idx;
		int right = half_idx;
		for (int i = 0; i < N; i++)
		{
			for (int j = left; j <= right; j++)
			{
				answer += arr[i][j];
			}
			
			if (i < half_idx)
			{
				left -= 1;
				right += 1;
			}
			else
			{
				left += 1;
				right -= 1;
			}
		}
		
		//���
		cout << "#" << test_case << " " << answer << endl;
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}