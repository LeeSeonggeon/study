#include<iostream>
#include <cstdio>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	double sum;
	int count = 10;
	double result;
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
		int temp;
		sum = 0;
		for (int i = 0; i < count; i++)
		{
			cin >> temp;
			sum += temp;
		}
		
		result = sum / count;
		double temp2 = result - (int)result;
		if (temp2 >= 0.5)
		{
			result = (int)result + 1;
		}
		else
		{
			result = (int)result;
		}
		/*
		//���� ����� �ε��Ҽ��� ������ ���� ������ ���� �� �� �ִ�.
		//���� ¥�� �Ѵٸ� ������ ����
		result = result +0.5
		result = (int)result;
		//�ݿø��� ���ִ� �Լ��� �̹� ����. �̸� ����ϸ�
		result = round(result);
		
		*/

		cout << "#" << test_case << " " << result << endl;
	}

	if (fp != nullptr)
	{
		fclose(fp);
	}

	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}