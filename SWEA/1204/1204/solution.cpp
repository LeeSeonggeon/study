#include<iostream>
#include <cstdio>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int N;
	int num;
	int* arr;
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
		cin >> N;
		arr = new int[101]();
		
		for (int i = 0; i < 1000; i++)
		{
			cin >> num;
			arr[num]++;
		}
		int max_idx = -1;
		int max = 0;
		for (int i = 0; i < 101; i++)
		{
			/*
			//���� �� ���
			if (arr[i] > max)
			{
				max_idx = i;
				max = arr[i];
			}
			else if (arr[i] == max)
			{
				if (max_idx < i)
				{
					max_idx = i;
					max = arr[i];
				}
			}
			*/
			//���ǹ� ����ȭ
			if (arr[i] >= max)
			{
				max_idx = i;
				max = arr[i];
			}
		}

		cout << "#" << N << " " << max_idx << endl;

		delete[] arr;
	}

	if (fp != nullptr)
	{
		fclose(fp);
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}