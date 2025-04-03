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

	if (is_sorted(Number.begin(), Number.end(), greater<char>()))	//만약 내림차순으로 정렬되어 있다면 남은 횟수보고 Number.length()-1, Number.length()-2 인덱스 swap 여부 결정해서 비교하고 return 해줘서 시간 단축
	{
		
		int duplicationIdx = findDuplication();
		if (duplicationIdx != -1)		//중복되는 숫자가 있는 경우, 중복 숫자가 있으면 해당 위치만 계속 교환하는 것으로 처리할 수 있으니까
		{								//중복 숫자의 인덱스를 찾고 해당 위치의 숫자만 교환한다.
			if ((max_changeCount - changeCount) % 2 == 1)	//남은 횟수가 홀수이면
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
		{								//중복이 없으므로 마지막 2개를  교환한다.
			int temp = Number.length() - 1;
			if ((max_changeCount - changeCount) % 2 == 1)	//남은 횟수가 홀수이면
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
			if (Number[i] <= Number[j])			//뒤에 오는 숫자가 더 큰 경우에만 실행
			{
				swap(Number[i], Number[j]);		//변경
				dfs(idx + 1, changeCount + 1);	//재귀
				swap(Number[i], Number[j]);		//원복
			}
			
		}
	}

}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
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
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}