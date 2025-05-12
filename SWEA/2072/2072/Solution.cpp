#include <iostream>
#include <cstdio>

using namespace std;

/*
�� ���� 0 �̻� 10000 ������ ����

10���� ������ �־����� �ش� ���� �߿� Ȧ���� ���� ����Ѵ�.
��� ����: '#t sum'
*/

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int num;
	int sum;
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
	int result = freopen_s(&fp, "input.txt", "r", stdin);
	if (result != 0)
	{
		fprintf(stderr, "���� ���⿡ �����߽��ϴ�\n");
		return 1;
	}
	cin >> T;
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		sum = 0;
		for (int i = 0; i < 10; i++)
		{
			cin >> num;
			if (num < 0 || num > 100000)
			{
				cout << "���ڰ� ������ ���" << endl;
				return 1;
			}
			if (num % 2 == 1)
			{
				sum += num;
			}
		}
		cout << "#" << test_case << " " << sum << endl;
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.

}