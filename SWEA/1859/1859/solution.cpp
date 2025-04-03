#include <iostream>
#include <cstdio>

using namespace std;
/*
25년 간의 수행 끝에 원재는 미래를 보는 능력을 갖게 되었다. 이 능력으로 원재는 사재기를 하려고 한다.

다만 당국의 감시가 심해 한 번에 많은 양을 사재기 할 수 없다.

다음과 같은 조건 하에서 사재기를 하여 최대한의 이득을 얻도록 도와주자.

    1. 원재는 연속된 N일 동안의 물건의 매매가를 예측하여 알고 있다.
    2. 당국의 감시망에 걸리지 않기 위해 하루에 최대 1만큼 구입할 수 있다.
    3. 판매는 얼마든지 할 수 있다.

예를 들어 3일 동안의 매매가가 1, 2, 3 이라면 처음 두 날에 원료를 구매하여 마지막 날에 팔면 3의 이익을 얻을 수 있다.

[입력]

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스 별로 첫 줄에는 자연수 N(2 ≤ N ≤ 1,000,000)이 주어지고,

둘째 줄에는 각 날의 매매가를 나타내는 N개의 자연수들이 공백으로 구분되어 순서대로 주어진다.

각 날의 매매가는 10,000이하이다.

각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고, 최대 이익을 출력한다.
*/
int main(int argc, char** argv)
{
	int test_case;
	int T;			//테스트 케이스 수
	int N;			//예측한 날의 수
	int* arr;
	long long result;		//이익	//int 로 하니까 오버플로가 발생하네? output확인 제대로 하자 자료형 범위 내인지
							//1. double로 변경 -> 출력형태가  e+n 형태로 출력이 되어서 낮은 자리수의 숫자가 생략되어 표시되고, output.txt와도 다른 형태임
							//2. long long 자료형을 사용 -> 통과
	int max = 0;
	int max_num = -1;
	int count = 0;	//구매한 물건의 개수
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
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		result = 0;
		cin >> N;	//N입력 받기
		arr = new int[N];
		for (int i = 0; i < N; i++)// 예측한 값 가져오기
		{
			cin >> arr[i];
			if (arr[i] > max)//Max 값 찾기
			{
				max = arr[i];
				max_num = i;
			}
		}

		for (int i = 0; i <= max_num; i++)
		{
			if (i < max_num)
			{
				count++;
				result -= arr[i];
			}
			else
			{
				result += arr[i] * count;
				count = 0;
			}

			if (i==max_num && max_num != N - 1)
			{
				max = 0;
				for (int j = i+1; j < N; j++)
				{
					
					if (arr[j] > max)//Max 값 찾기
					{
						max = arr[j];
						max_num = j;
					}
				}
			}
		}

		cout << "#" << test_case << " " << result << endl;
		result = 0;
		count = 0;
		delete[] arr;
	}

	if(fp != nullptr)
	{
		fclose(fp);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}