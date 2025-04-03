#include <iostream>
#include <cstdio>

using namespace std;

/*
각 수는 0 이상 10000 이하의 정수

10개의 정수가 주어지면 해당 정수 중에 홀수만 더해 출력한다.
출력 형태: '#t sum'
*/

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int num;
	int sum;
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
	int result = freopen_s(&fp, "input.txt", "r", stdin);
	if (result != 0)
	{
		fprintf(stderr, "파일 열기에 실패했습니다\n");
		return 1;
	}
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		sum = 0;
		for (int i = 0; i < 10; i++)
		{
			cin >> num;
			if (num < 0 || num > 100000)
			{
				cout << "숫자가 범위를 벗어남" << endl;
				return 1;
			}
			if (num % 2 == 1)
			{
				sum += num;
			}
		}
		cout << "#" << test_case << " " << sum << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.

}