#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

string Number;
int max_changeCount;

int result;

int findDuplication()
{
	for (int i = 0; i < Number.length() - 1; i++)
	{
		if (Number[i] == Number[i + 1])
		{
			return i;
		}
	}


	return -1;
}

void dfs(int idx, int changeCount)
{
	if (changeCount == max_changeCount)
	{
		result = max(result, stoi(Number));
		return;
	}

	if (is_sorted(Number.begin(), Number.end(), greater<char>()))	//���� ������������ ���ĵǾ� �ִٸ� ���� Ƚ������ Number.length()-1, Number.length()-2 �ε��� swap ���� �����ؼ� ���ϰ� return ���༭ �ð� ����
	{
		
		int duplicationIdx = findDuplication();
		if (duplicationIdx != -1)		//�ߺ��Ǵ� ���ڰ� �ִ� ���, �ߺ� ���ڰ� ������ �ش� ��ġ�� ��� ��ȯ�ϴ� ������ ó���� �� �����ϱ�
		{								//�ߺ� ������ �ε����� ã�� �ش� ��ġ�� ���ڸ� ��ȯ�Ѵ�.
			if ((max_changeCount - changeCount) % 2 == 1)	//���� Ƚ���� Ȧ���̸�
			{
				swap(Number[duplicationIdx], Number[duplicationIdx+1]);
				result = max(result, stoi(Number));
				swap(Number[duplicationIdx], Number[duplicationIdx+1]);

				return;
			}
			else
			{
				result = max(result, stoi(Number));
				return;
			}
		}
		else
		{								//�ߺ��� �����Ƿ� ������ 2����  ��ȯ�Ѵ�.
			int temp = Number.length() - 1;
			if ((max_changeCount - changeCount) % 2 == 1)	//���� Ƚ���� Ȧ���̸�
			{
				swap(Number[temp - 1], Number[temp]);
				result = max(result, stoi(Number));
				swap(Number[temp - 1], Number[temp]);

				return;
			}
			else
			{
				result = max(result, stoi(Number));
				return;
			}
		}

	}

	for (int i = idx; i < Number.length() - 1; i++)
	{
		for (int j = i + 1; j < Number.length(); j++)
		{
			if (Number[i] <= Number[j])			//�ڿ� ���� ���ڰ� �� ū ��쿡�� ����
			{
				swap(Number[i], Number[j]);		//����
				dfs(idx + 1, changeCount + 1);	//���
				swap(Number[i], Number[j]);		//����
			}
			
		}
	}

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
	freopen_s(&fp, "input.txt", "r", stdin);
	cin >> T;


	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> Number;
		cin >> max_changeCount;

		dfs(0, 0);

		cout << "#" << test_case << " " << result << endl;
		result = 0;
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}