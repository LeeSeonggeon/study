#include <iostream>
#include <cstdio>
#include <deque>
#include <set>
using namespace std;


deque<int> decomposition(int num)	//�ڸ��� ����
{
	deque<int> dq;
	while (true)
	{
		dq.push_front(num % 10);
		num /= 10;
		if (num == 0)
		{
			break;
		}
	}//���� �ڸ��� ���� ����
	return dq;
}
int mixture(deque<int>& dq) {	//���ص� �ڸ��� ��ġ��
	int sum = 0;
	for (int i = 0; i < dq.size(); i++)
	{
		sum *= 10;
		sum += dq[i];
	}

	return sum;
}


int solution(int Number,int changeCount, int depth, int maxResult, set<int> visit[]) {	//������ ����, ��ȯ ����Ƚ��, ���� ����, ������� ã�� Max ��
	if (depth == changeCount)	// ���̸� �ʰ��ϸ� ����
	{
		//cout <<"���� �ʰ�: " << depth << " " << maxResult << endl;
		return max(Number, maxResult);
	}

	if (visit[depth].count(Number)) 
	{ 
		//cout << "�̹� �ߴ�: " << depth << " " << maxResult << endl;
		return maxResult; 
	}	//�̹� �ߴ� ������ �н��Ѵ�.

	visit[depth].insert(Number);

	deque<int> dq = decomposition(Number);
	
	for (int i = 0; i < dq.size() - 1; i++)
	{
		for (int j = i + 1; j < dq.size(); j++)
		{
			swap(dq[i], dq[j]);
			Number = mixture(dq);
			maxResult = solution(Number, changeCount, depth + 1, maxResult, visit);
			swap(dq[i], dq[j]);
		}
	}
	//cout << "return: " << depth << " " << maxResult << endl;
	return maxResult;
}



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
	freopen_s(&fp,"input.txt", "r", stdin);
	cin >> T;
	int result;
	int Number;
	int changeCount;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		//
		cin >> Number;
		cin >> changeCount;
		set<int> visit[11];

		result = solution(Number, changeCount, 0, Number, visit);//dfs
		cout << "#" << test_case << " " << result << endl;
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}