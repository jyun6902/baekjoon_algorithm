#include <iostream>
using namespace std;

int main()
{
	int K = 0, N=0;	//폭탄을 들고 있는 사람의 번호, 질문의 갯수
	int sec = 0;	//소요되는 시간
	cin >> K >> N;
	for (int i = 1; i <= N; i++)
	{
		int T = 0;//질문을 대답하기까지 걸린시간
		char Z;	//플레이어의 대답 (T, N ,P)

		cin >> T >> Z;
		sec += T;

		if (sec >= 210)	//3분 30초
		{
			cout << K<<endl;
			return 0;
		}

		if (Z == 'T')
		{
			K =  (K + 1) % 8;
			if (K == 0)			//k=7대입하면 8나와야 하는데 0으로 나오므로
				K = 8;
		}
	}
	return 0;
}