#include<iostream>
#include <cstdio>
using namespace std;

bool isUpWall(int **arr, int y, int x)
{
	if (arr[y][x] == 0)
	{
		return false;
	}

	if (y == 0 || arr[y - 1][x] == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}//현재 위치에서 위로 막혀 있는가? 그리고 아래로 갈 수 있는가?

bool isLeftWall(int** arr, int y, int x)
{
	if (arr[y][x] == 0)
	{
		return false;
	}

	if (x == 0 || arr[y][x - 1] == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}//현재 위치에서 왼쪽이 막혀 있는가?

bool isDownWall(int** arr, int y, int x, int N)
{
	if (arr[y][x] == 0)
	{
		return false;
	}

	if (y == N-1  || arr[y + 1][x] == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}//현재 위치에서 아래로 막혀 있는가?

bool isRightWall(int** arr, int y, int x, int N)
{
	if (arr[y][x] == 0)
	{
		return false;
	}

	if (x == N-1 || arr[y][x + 1] == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}//현재 위치에서 오른쪽이 막혀 있는가?


int solution(int** arr, int y, int x, int N, int K)
{
	int count = 0;
	if (isUpWall(arr, y, x))
	{
		bool check = true;
		if (y + K - 1 >= N) //남은 공간이 왼쪽으로 못가는 상황이면 처리해줘야 한다.
		{
			check = false;
		}
		else if (isDownWall(arr, y + K - 1, x, N))
		{
			for (int i = y; i <= y + K - 1; i++)
			{
				if (arr[i][x] == 0)
				{
					check = false;
					break;
				}
			}
			if (check == true) count++;
		}
	}//내려가는 경우확인

	if (isLeftWall(arr, y, x)) 
	{
		
		bool check = true;
		if (x + K - 1 >= N) //남은 공간이 왼쪽으로 못가는 상황이면 처리해줘야 한다.
		{
			check = false;
		}
		else if (isRightWall(arr, y, x + K - 1, N))
		{
			for (int i = x; i <= x + K - 1; i++)
			{
				if (arr[y][i] == 0)
				{
					check = false;
					break;
				}
			}
			if (check == true) count++;
		}
	}//오른쪽으로 가는 경우

	return count;
}


int main(int argc, char** argv)
{
	int test_case;
	int T;
	int** arr;
	int N;
	int K;

	int K_count = 0;
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
		K_count = 0;
		cin >> N >> K;
		arr = new int* [N];
		for (int i = 0; i < N; i++)
		{
			arr[i] = new int[N]();
			for (int j = 0; j < N; j++)
			{
				cin >> arr[i][j];
			}
		}
		
		/*
		0 0 1 1 1
		1 1 1 1 0
		0 0 1 0 0
		0 1 1 1 1
		1 1 1 0 1

		K= 2
		3, 3
		N = 5
		N-K = 3
		
		단어의 시작지점:
		1. 아래로 내려가는 경우 -> 위에가 막혀 있음
		2. 오른쪽으로 가는 경우 -> 왼쪽이 막혀 있음 

		단어의 끝지점:
		1. 아래로 내려가는 경우 -> 아래가 막혀 있음
		2. 오른쪽으로 가는 경우 -> 오른쪽이 막혀 있음
		*/

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				K_count += solution(arr, i, j, N, K);
			}
		}

		
		for (int i = 0; i < N; i++)
		{
			delete[] arr[i];
		}
		delete[] arr;

		cout << "#" << test_case << " " << K_count << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}