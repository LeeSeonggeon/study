#include<iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*
���� ���� ��� �ڽ��� �׿� ����

�ڽ��� ���� ���̸� ���̴� ��źȭ �۾��� �����Ϸ� �Ѵ�.
��źȭ �۾��� ��� �����ϸ�, max�� min�� ���̰� �ִ� 1�� �ȴ�.

��źȭ �۾��� �ű�� Ƚ���� ������ �ɷ�����
���ѵ� Ƚ����ŭ �Ű��� �� max-min�� ��ȯ�ϴ� ���α׷�

���� ���̴� �׻� 100
������ ���̴� 1�̻� 100����
�ű�� Ƚ���� 1�̻� 1000����
�ű�� Ƚ�� ��� ������ max-min ��ȯ

�Է�:
�� 10���� �׽�Ʈ ���̽��� �־���
1. �ű�� Ƚ��
2. �� ��ġ�� ���� ���̰�

���:
#test_case max-min


*/

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

	int dump_count;
	int arr[100];
	
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
	//cin >> T;
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> dump_count;
		for (int i = 0; i < 100; i++)
		{
			cin >> arr[i];
		}
		
		for (int i = 0; i < dump_count; i++)
		{
			sort(arr, arr + 100);	//���� ����
			if (arr[99] - arr[0] <= 1)
			{
				break;
			}
			arr[0] += 1;
			arr[99] -= 1;
		}
		sort(arr, arr + 100);	//���� ����
		cout << "#" << test_case << " " << arr[99] - arr[0] << endl;

	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}