#include<iostream>
#include <cstdio>
#include <string>
using namespace std;

enum month {
	JAN = 31,

};

int main(int argc, char** argv)
{
	int test_case;
	int T;
	string YMD;

	//������ ���� ���ε� �������� ������ �ʿ�� ������ ��
	int* arr = new int[12];
	arr[0] = 31;
	arr[1] = 28;
	arr[2] = 31;
	arr[3] = 30; 
	arr[4] = 31;
	arr[5] = 30; 
	arr[6] = 31;
	arr[7] = 31;
	arr[8] = 30;
	arr[9] = 31;
	arr[10] = 30;
	arr[11] = 31; 
	

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
		cin >> YMD;
		int M = 0;
		int D = 0;

		string temp = "";
		for (int i = 4; i < 6; i++)
		{
			temp += YMD[i];
		}
		M = stoi(temp);

		temp = "";
		for (int i = 6; i < YMD.length(); i++)
		{
			temp += YMD[i];
		}
		D = stoi(temp);

		if (arr[M - 1] < D)
		{
			cout << "#" << test_case << " -1"  << endl;
		}
		else
		{
			
			YMD.insert(4, "/");
			YMD.insert(7, "/");

			cout << "#" << test_case << " " << YMD << endl;
			
		}


	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}