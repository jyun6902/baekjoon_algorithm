#include <iostream>
#include <cstring>
using namespace std;
int N=0, M=0;
int map[505][505];
int m_case[19][4][2] = {
	{ {0,0},{0,1},{0,2},{0,3}},	
	/*1
	しししし	*/
	{ { 0,0 },{ 1,0 },{ 2,0 },{ 3,0 } },
	/*2
	し
	し
	し
	し
	*/
	{{0,0}, {1,0} , {2,0}, {2, 1} },
	/*3
	し
	し
	しし
	*/
	{ { 0,1 },{ 1,1 } ,{ 2,1 },{ 2, 0 } },
	/*4
	  し
	  し
	しし
	*/
	{ {0,0}, { 0,1 },{ 1,1 } ,{ 2,1 } },
	/*5
	しし
	  し
	  し
	*/
	{ {0,0}, {1,0} ,{2,0} , {0,1}},
	/*6
	しし
	し
	し
	*/
	{{0,0}, {1,0}, {1,1}, {1,2}},
	/*7
	し
	ししし
	*/
	{{1,0}, {1,1}, {1,2}, {0,2}},
	/*8
		し
	ししし
	*/
	{{0,0},{0,1},{0,2},{1,0}},
	/*9
	ししし
	し
	*/
	{{0,0}, {0,1}, {0,2}, {1,2}},
	/*10
	ししし
		し
	*/
	{{0,0}, {1,0}, {2,0}, {1,1}},
	/*11
	し
	しし
	し
	*/
	{ { 0,1 },{ 1,1 },{ 2,1 },{ 1,0 } },
	/*12
	  し
	しし
	  し
	*/
	{ { 0,1 },{ 1,1 },{ 1,2 },{ 1,0 } },
	/*13
	  し
	ししし
	*/
	{ { 0,0 },{ 0,1 },{ 0,2 },{ 1,1 } },
	/*14
	ししし
	  し
	*/
	{ { 0,0 },{ 1,0 },{ 1,1 },{ 2,1 } },
	/*15
	し
	しし
	  し
	*/
	{ { 0,1 },{ 1,0 },{ 1,1 },{ 2,0 } },
	/*16
	  し
	しし
	し
	*/
	{ { 0,0 },{ 0,1 },{ 1,1 },{ 1,2 } },
	/*17
	しし
	  しし
	*/
	{ { 0,1 },{ 0,2 },{ 1,0 },{ 1,1 } },
	/*18
	  しし
	しし
	*/
	{ { 0,0 },{ 0,1 },{ 1,0 },{ 1,1 } },
	/*19
	しし
	しし
	*/
};
int main()
{
	memset(map, 0, sizeof(map));
	int max_result =0, result = 0;
	cin >> N >> M;


	for (int i  = 0 ;i< N ; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i< N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < 19; k++)
			{
				int ok = 0;
				for (int l = 0; l < 4; l++)
				{
					if (i+m_case[k][l][0] >= 0 && i+m_case[k][l][0] < N && j+m_case[k][l][1] >= 0 && j+m_case[k][l][1] < M)
						ok++;
				}

				if ( ok == 4)
				{
					result = 0;
					for (int l = 0; l < 4; l++)
					{
						result += map[i + m_case[k][l][0]][j + m_case[k][l][1]];
					}
					if (max_result < result)
						max_result = result;
				}

			}
		}
	}

	cout << max_result;
	return 0;
}