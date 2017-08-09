#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string S, S_rever;
	cin >> S;
	int len = S.length();
	int cnt = 0;

	while (1)
	{
		S_rever= S;
		reverse(S_rever.begin(), S_rever.end());//문자열 뒤집기
		if (S.compare(S_rever) == 0)			//문자열이 같을 경우
			break;

		else									//다를 경우
		{
			S.erase(len, len + cnt);				//추가했던 만큼 삭제
			string cp = S_rever.substr(S_rever.length()-cnt-1, S_rever.length());	//추가할 부분 (뒤집은 배열의 끝에서 하나씩 증가)
			S.insert(len, cp);					//추가
		}
		cnt++;
	}

	cout << S.length() << endl;
	return 0;
}