#include <iostream>
#include <cstdio>

using namespace std;
#define INT_MAX 9999
/*
A와 B로 표시된 세대의 경우는 왼쪽 조망은 2칸 이상 확보가 되었지만 오른쪽 조망은 한 칸 밖에 확보가 되지 않으므로 조망권을 확보하지 못하였다.

C의 경우는 반대로 오른쪽 조망은 2칸이 확보가 되었지만 왼쪽 조망이 한 칸 밖에 확보되지 않았다.

[제약 사항]

가로 길이는 항상 1000이하로 주어진다.

맨 왼쪽 두 칸과 맨 오른쪽 두 칸에는 건물이 지어지지 않는다. (예시에서 빨간색 땅 부분)

각 빌딩의 높이는 최대 255이다.

[입력]

총 10개의 테스트케이스가 주어진다.

각 테스트케이스의 첫 번째 줄에는 건물의 개수 N이 주어진다. (4 ≤ N ≤ 1000)

그 다음 줄에는 N개의 건물의 높이가 주어진다. (0 ≤ 각 건물의 높이 ≤ 255)

맨 왼쪽 두 칸과 맨 오른쪽 두 칸에 있는 건물은 항상 높이가 0이다. (예시에서 빨간색 땅 부분)

[출력]

#부호와 함께 테스트케이스의 번호를 출력하고, 공백 문자 후 조망권이 확보된 세대의 수를 출력한다.
*/

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int N;		//건물의 개수	(양 끝 빈칸 2개 포함하는 개수 -> 가로의 길이로 생각)
	int* arr;	//각 건물의 높이
	int temp[] = { 0,0,0,0 };	//건물 높이를 비교하기 위한 변수	-2 / -1 / +1 / +2 과 비교
	int result = 0;	//조망권이 확보된 건물의 개수
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
	freopen_s(&fp,"input.txt", "r", stdin);

	//cin >> T;

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		cin >> N;

		//
		// cout << "N: " << N << endl; // 1
		
		arr = new int[N];
		for (int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		
		for (int i = 0; i < N; i++)
		{
			if (arr[i] == 0)	// 건물 높이가 0 -> 건물이 없다. -> 측정할 필요 없음
			{
				continue;
			}
			else
			{
				temp[0] = arr[i] - arr[i - 2];
				temp[1] = arr[i] - arr[i - 1];
				temp[2] = arr[i] - arr[i + 1];	//범위를 벗어날 수 있다고 밑줄 표시 -> 하지만 마지막 2개는 0이므로 범위를 벗어나기 전에 이미 위의 if문에서 걸러질 것
				temp[3] = arr[i] - arr[i + 2];
			
				//cout << temp[0] << " " << temp[1] << " " << temp[2] << " " << temp[3] << endl; //2
			}

			for (int j = 0; j < 4; j++)
			{
				if (temp[j] < min)
				{
					min = temp[j];
				}
			}
			if (min > 0)
			{
				result += min;
			}
			min = INT_MAX;
		}
		cout << "#" << test_case << " " << result << endl;
		delete[] arr;
		result = 0;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}