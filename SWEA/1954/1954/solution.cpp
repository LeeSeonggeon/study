#include<iostream>
#include <cstdio>
using namespace std;

/*
생각

큰 네모부터 순서대로 그려나가기

ex)
N = 4

1. 
1 2 3 4
12 0 0 5
11 0 0 6
10 9 8 7

2.
1 2 3 4
12 13 14 5
11 16 15 6
10 9 8 7

이렇게 밖의 사각형 먼저 넣어주고 순서대로 작은 네모에 값을 넣어주기를 반복

각 네모의 크기에 따라 몇개의 숫자가 들어가는가?
4n-4개의 숫자가 들어갈 수 있음(n은 네모의 한 변의 길이)
N=4인 경우 첫 네모에 들어가는 숫자의 개수는 4*4-4 = 12개 
두 번째 네모에 들어가는 숫자의 개수는 4*2-4 = 4개

*/

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int N;

	int num;		//배열에 입력할 숫자
	int** arr;		//저장할 배열
	int num_count;	//네모에 몇개의 숫자가 필요한가
	int x;
	int y;
	int dir;
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };

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
		//준비
		cin >> N;

		x = 0;
		y = 0;
		dir = 0;
		arr = new int* [N];
		for (int i = 0; i < N; i++)
		{
			arr[i] = new int[N]();
		}//출력을 위한 공간 만들기

		//알고리즘
		/*
		//밖에 네모부터 그리고 안을 채워나가는 방식
		int num = 1;
		int start = 0;
		int end = N - 1;

		while (start <= end) {
			// 위쪽 가로
			for (int i = start; i <= end; i++)
				arr[start][i] = num++;

			// 오른쪽 세로
			for (int i = start + 1; i <= end; i++)
				arr[i][end] = num++;

			// 아래쪽 가로 (역방향)
			for (int i = end - 1; i >= start; i--)
				arr[end][i] = num++;

			// 왼쪽 세로 (역방향)
			for (int i = end - 1; i > start; i--)
				arr[i][start] = num++;

			start++;
			end--;
		}
		*/

		//회오리로 돌면서 그려나가는 방식
		for (num = 1; num <= N * N; num++)
		{
 			arr[y][x] = num;

			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N || arr[ny][nx] != 0) {
				dir = (dir + 1) % 4; // 방향 전환
				nx = x + dx[dir];
				ny = y + dy[dir];
			}

			x = nx;
			y = ny;
		}


		//출력
		cout << "#" << test_case << endl;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}

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