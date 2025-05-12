#include<iostream>
#include<cstdio>
#include <string>
using namespace std;

/*
실패한 코드
DFS로 진행함
결과가 맞지도 않음 -> 수정해서 결과는 맞게 나옴 (sample 1~4까지 확인)
				-> visit[y][x] = false 하는 타이밍의 문제(return 전에 해주는 부분이 있었어야 함)

*/

//우, 하, 상, 좌 순서
//일단 방향이 좌상단에서 우하단이어서 이렇게 배치함
int dx[4] = {1, 0, 0, -1};	
int dy[4] = {0, 1, -1, 0};	
int answer;	// 최소 작업 시간
int** arr;
bool** visit;

bool isvisited(int x, int y)
{
	if (visit[y][x] == true)
	{
		return true;
	}//방문 경력 있음
	return false;	//방문한 적 없음
}

bool isvalid(int x, int y, int N)
{
	if (x < 0 || x >= N)
	{
		return false;
	}//x 좌표 유효성 확인
	if (y < 0 || y >= N)
	{
		return false;
	}//y좌표 유효성 확인
	if (isvisited(x, y))
	{
		return false;
	}//방문 기록이 있으면 false

	return true;
}

void solution(int** arr, int N, int x, int y, int result)
{
	visit[y][x] = true;
	if (x == N - 1 && y == N - 1)
	{
		answer = min(answer, result);
		visit[y][x] = false;
		return;
	}//탈출지 좌표이면 비교를 진행해서 작은 값을 저장


	if (answer < result)
	{
		visit[y][x] = false;
		return;
	}//진행 중에 answer 보다 커지면 더 이상 진행할 의미가 없음

	int nx;
	int ny;

	for (int i = 0; i < 4; i++)
	{
		nx = x + dx[i];
		ny = y + dy[i];

		if (!isvalid(nx, ny, N))
		{
			continue;
		}	//유효하지 않은 위치는 패스

		result += arr[ny][nx];
		
		solution(arr, N, nx, ny, result);
		result -= arr[ny][nx];
	}
	visit[y][x] = false;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int N;
	string input;
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
		answer = INT_MAX;
		cin >> N;
		arr = new int* [N];
		visit = new bool* [N];
		for (int i = 0; i < N; i++)
		{
			arr[i] = new int[N];
			visit[i] = new bool[N]();	//기본 false로 만들기
		}

		for (int i = 0; i < N; i++)
		{
			cin >> input;
			for (int j = 0; j < N; j++)
			{
				arr[i][j] = input[j] - '0';
			}

		}

		solution(arr, N, 0, 0, arr[0][0]);

		for (int i = 0; i < N; i++)
		{
			delete[] arr[i];
			delete[] visit[i];
		}
		delete[] arr;
		delete[] visit;

		cout << "#" << test_case << " " << answer << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}