#include <iostream>
#include <cstdio>

using namespace std;

/*
N x N 배열 안의 숫자는 해당 영역에 존재하는 파리의 개수를 의미한다.	(5<=N<=15)
M x M 크기의 파리채를 한 번 내리쳐 최대한 많은 파리를 죽이고자 한다. (2 <= M <= N)
죽은 파리의 개수를 구하라 (영역의 파리 개수 K <= 30)

입력
1. test_case의 개수
2. N M
3. N x N 배열

출력
#t (잡은 파리 개수)

*/

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


	int N = 0;
	int M = 0;
	int** arr;


	int dead_fly;

	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		dead_fly = 0;

		cin >> N;
		cin >> M;
		arr = new int* [N];
		for (int i = 0; i < N; i++)
		{
			arr[i] = new int[N]();
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> arr[i][j];
			}
		}
		int max = 0;
		for (int i = 0; i <= N - M; i++)
		{
			for (int j = 0; j <= N - M; j++)
			{
				for (int k = 0; k < M; k++)
				{
					for (int t = 0; t < M; t++)
					{
						dead_fly += arr[i+k][j+t];
						if (dead_fly >= max)
						{
							max = dead_fly;
						}
					}
				}
				dead_fly = 0;
			}
		}

		cout << "#" << test_case << " " << max << endl;

		for (int i = 0; i < N; i++)
		{
			delete[] arr[i];
		}
		delete[] arr;


	}

	if (fp != nullptr)
	{
		fclose(fp);
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}