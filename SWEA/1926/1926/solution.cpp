#include<iostream>
#include <cstdio>
#include <string>
using namespace std;


/*
369����

369 �� '-'�� ǥ��
369�� �� ���ڸ�ŭ '-'
���� 36 �̸� '--'


*/
int main(int argc, char** argv)
{

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
	//FILE* fp;
	//freopen_s(&fp, "input.txt", "r", stdin);
	cin >> T;

	string str;
	for (int i = 1; i <= T; i++)
	{
		if (i != 1) { cout << " "; }
		str = to_string(i);
		int count = 0;
		for (int j = 0; j < str.length(); j++)
		{
			if (str[j] == '3' || str[j] == '6' || str[j] == '9')
			{
				count++;
			}
		}

		if (count != 0)
		{
			for (int j = 0; j < count; j++)
			{
				cout << '-';
			}
		}
		else {
			cout << i;
		}

	}



	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}