#include <iostream>
#include <cstdio>

using namespace std;

//알고리즘이 생각이 안나는데... 난이도를 낮춰서 하다 다음에 다시하자

/*
첫 입력: 테스트 케이스 개수
두 번째 입력: 막대의 개수 (1 ≤ N ≤ 50)
세 번째 입력: 각 막대의 길이 (1 ≤ ai ≤ 10^9 = 10억)

1. 막대 길이 2 이상의 막대를 선택
2. 선택된 막대의 길이를 반으로 자름(자를 때는 내림 연산을 진행)
3. 잘라서 생긴 두개의 막대 중 하나를 선택하고 나머지는 버린다.
4. 1~3을 반복해 모든 막대의 길이를 동일하게 만든다.

위의 과정의 최소 연산 횟수는?
*/

int main(int argc, char** argv)
{
	int test_case;
	int T;					// 테스트 케이스의 개수
	int N;					// 막대의 개수
	int *stick;				// 막대 길이
	bool isDone = false;	// 모두 같아졌는지 확인
	unsigned int cutCount = 0;// 막대를 자른 횟수
	int min = INT_MAX;
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
		//막대의 개수 받기
		cin >> N;
		stick = new int[N];
		//막대 길이 받기
		for (int i = 0; i < N; i++)
		{
			cin >> stick[i];
		}

		//알고리즘
		while (!isDone)
		{
			//1. min 값 찾기
			for (int i = 0; i < N; i++)
			{
				if (stick[i] <= min) 
				{
					min = stick[i]; 
				}
			}
			//2. 다른 값들이 min값으로 갈 수 있는지 확인하기 및 자르기


		}

		//해당 테스트 케이스 계산이 끝난 이 후 메모리 해제를 통한 누수 막기
		delete[] stick;
		stick = nullptr;
		cutCount = 0;
	}
	if (fp != nullptr)
	{
		fclose(fp);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}