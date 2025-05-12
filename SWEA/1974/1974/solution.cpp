#include<iostream>
#include <cstdio>

using namespace std;

bool isWidth(int arr[][9], int rows)
{
	
	int idx = 0;
	for (int i = 0; i < 9; i++)
	{
		bool check[9] = { false };
		for (int j = 0; j < 9; j++)
		{
			idx = arr[i][j] - 1;
			if (check[idx] == false)
			{
				check[idx] = true;
			}
			else
			{
				return false;
			}
		}
	}

	return true;
}//가로 확인
bool isLength(int arr[][9], int rows)
{
	int idx = 0;
	for (int i = 0; i < 9; i++)
	{
		bool check[9] = { false };
		for (int j = 0; j < 9; j++)
		{
			idx = arr[j][i] - 1;
			if (check[idx] == false)
			{
				check[idx] = true;
			}
			else
			{
				return false;
			}
		}
	}

	return true;
}//세로 확인
bool isSquare(int arr[][9], int rows)
{
	int x = 0;
	int y = 0;
	int idx = 0;

	for (int i = 0; i < 3; i++)
	{
		y = 3 * i;
		for (int j = 0; j < 3; j++)
		{
			x = 3 * j;

			bool check[9] = { false };
			for (int k = y; k < y + 3; k++)
			{
				for (int t = x; t < x + 3; t++)
				{
					idx = arr[k][t] - 1;
					if (check[idx] == false)
					{
						check[idx] = true;
					}
					else
					{
						return false;
					}
				}
			}
		}
	}
	return true;
}//칸 확인


int main(int argc, char** argv)
{
	int test_case;
	int T;
	int arr[9][9];

	FILE* fp;
	freopen_s(&fp, "input.txt", "r", stdin);
	
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		//입력
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cin >> arr[i][j];
			}
		}

		if (!isWidth(arr, 9))
		{
			cout << "#" << test_case << " " << 0 << endl;
		}
		else if (!isLength(arr, 9))
		{
			cout << "#" << test_case << " " << 0 << endl;
		}
		else if (!isSquare(arr, 9))
		{
			cout << "#" << test_case << " " << 0 << endl;
		}
		else
		{
			cout << "#" << test_case << " " << 1 << endl;
		}

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}