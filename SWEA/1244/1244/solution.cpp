#include <iostream>
#include <cstdio>
#include <deque>
#include <set>
using namespace std;


deque<int> decomposition(int num)	//자리수 분해
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
	}//값을 자릿수 별로 분해
	return dq;
}
int mixture(deque<int>& dq) {	//분해된 자리수 합치기
	int sum = 0;
	for (int i = 0; i < dq.size(); i++)
	{
		sum *= 10;
		sum += dq[i];
	}

	return sum;
}


int solution(int Number,int changeCount, int depth, int maxResult, set<int> visit[]) {	//숫자판 나열, 교환 가능횟수, 현재 깊이, 현재까지 찾은 Max 값
	if (depth == changeCount)	// 깊이를 초과하면 종료
	{
		//cout <<"깊이 초과: " << depth << " " << maxResult << endl;
		return max(Number, maxResult);
	}

	if (visit[depth].count(Number)) 
	{ 
		//cout << "이미 했던: " << depth << " " << maxResult << endl;
		return maxResult; 
	}	//이미 했던 조합은 패스한다.

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
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
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
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}