#include<iostream>
#include<cstdio>
#include <algorithm>

using namespace std;

/*
��Ḷ�� ���� ������ Į�θ��� ���� (P, K)
������ Į�θ� ������ ���� �߿� ���� ���ִ� �ܹ��Ÿ� ����
���� ��� �ߺ� �Ұ�

����� �� N, ���� Į�θ� L
�� ����, Į�θ�

Time Out
mask�� �̿����� �����
������ ��� ���� �ؾ���
A -> B�� �̹� �ߴµ�
B -> A �� �ϰ� ��
�̸� �ذ��ؾ� ��
*/
int Result = 0;	// �� ����
int cal = 0;
int answer;	//�� ����
int N;
int L;
bool* mask;


void DNF(int* P, int* K, int idx)
{
	if (cal > L) return;
	answer = max(answer, Result);
	//Į�θ� ���� �ѱ� ���� �����ؾ� ��
	//�ٸ� ���� ������ �ִ°�? ����
	for (int i =idx+1 ; i< N; i++)
	{
		if (mask[i] == true)// �̹� ����� ���� ����
		{
			continue;
		}
		//������� ���� ��
		mask[i] = true;

		Result += P[i];
		cal += K[i];

		DNF(P, K, i+1);

		Result -= P[i];
		cal -= K[i];

		mask[i] = false;//DNF�� �������� ������� ���� ������ ������ֱ�
	}

}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	int* P;
	int* K;
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
	freopen_s(&fp,"input.txt", "r", stdin);
	cin >> T;
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		Result = 0;
		cal = 0;
		cin >> N >> L;

		P = new int[N];
		K = new int[N];
		mask = new bool[N]();
		for (int i = 0; i < N; i++)
		{
			cin >> P[i] >> K[i];
		}

		DNF(P, K, -1);

		cout << "#" << test_case << " " << answer << endl;

		delete[] P;
		delete[] K;
		delete[] mask;
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}


/*
#include <iostream>
#include <algorithm>
using namespace std;

int N, L;
int answer;

void DFS(int idx, int taste, int cal, int* P, int* K) {
	if (cal > L) return;

	answer = max(answer, taste);

	for (int i = idx; i < N; i++) {
		DFS(i + 1, taste + P[i], cal + K[i], P, K);
	}
}

int main() {
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case) {
		cin >> N >> L;
		int* P = new int[N];
		int* K = new int[N];
		answer = 0;

		for (int i = 0; i < N; i++) {
			cin >> P[i] >> K[i];
		}

		DFS(0, 0, 0, P, K);

		cout << "#" << test_case << " " << answer << endl;

		delete[] P;
		delete[] K;
	}

	return 0;
} 
*/