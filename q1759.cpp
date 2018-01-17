#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int L, C = 0;
vector <char> alpha;
bool check[25] = {};
void cal(int ja, int mo, int cnt,  string result, int now)
{
	if ( (ja < 2 || mo < 1 ) && cnt == L)
		return;

	if (cnt == L)
	{
		cout <<result << endl;
		return ;
	}
	for (int i = now; i < C; i++)
	{
		if (check[i] == true)
			continue;
	
	//	if (i > 0 && i <= L && alpha[i] >= alpha[i + 1] )
		//		continue;

		if (  alpha[i] == 'a' || alpha[i] == 'e' || alpha[i] == 'i' || alpha[i] == 'o' || alpha[i] == 'u')
		{
			check[i] = true;
			cal(ja, mo + 1, cnt + 1, result + alpha[i], i+1);
			check[i] = false;
		}
		else //if (check[i] == false)
		{
			check[i] = true;
			cal(ja + 1, mo, cnt + 1, result + alpha[i], i+1);
			check[i] = false;
		}
	}//for
}

int main()
{
	cin >> L >> C;//3≤L≤C≤15
	//서로 다른 L개의 알파벳 소문자들로 구성, 조교들이 암호로 사용했을 법한 문자의 종류는 C가지
	char c;
	for (int i = 0; i < C; i++)
	{
		cin >> c;
		alpha.push_back(c);
	}
	sort(alpha.begin(), alpha.end());
	cal(0, 0, 0, "", 0 );
	
	return 0;
}