#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define D_NUM 10
using namespace std;
struct Trie
{
	bool finish;    //끝나는 지점을 표시해줌
	Trie* next[D_NUM];
	Trie() : finish(false)
	{
		memset(next, 0, sizeof(next));
	}
	~Trie()
	{
		for (int i = 0; i < D_NUM; i++)
			if (next[i] != NULL)
				delete next[i];
	}
	void insert(const char* key)
	{
		if (*key == 0)
			finish = true;    //문자열이 끝나는 지점일 경우 표시
		else
		{
			int curr = *key - '0';
			if (next[curr] == NULL)
				next[curr] = new Trie();    //탐색이 처음되는 지점일 경우 동적할당
			next[curr]->insert(key + 1);    //다음 문자 삽입

		}
	}

	bool find(const char* key)
	{
		if (*key == NULL)
		{
			/*for (int i = 0; i < 10; i++)//쓰면 시간초과
			{
				if (next[i] != NULL)
					return true;
			}*/
			return false;//문자열이 끝나는 위치를
		}

		if (finish == 1)
		{
			return true;
		}
		int curr = *key - '0';

		return next[curr]->find(key + 1); //다음 문자를 탐색
	}
};

int main()
{
	int N = 0, K = 0;
	scanf("%d", &N);
	for (int t_c = 0; t_c < N; t_c++)
	{
		scanf("%d", &K);
		Trie* ptn = new Trie();
		vector <string> v;
		int flag = 0;

		for (int i = 0; i < K; i++)
		{
			string s="";
			cin >> s;
			v.push_back(s);
		}
		sort(v.begin(), v.end());
		
		for (int i = 0; i < K; i++)//v.size()
		{
			char sen[10] = {};
			memset(sen, 0, sizeof(sen));
			for (int j = 0; j < v[i].size(); j++)
			{
				sen[j] = v[i][j];
			}
			ptn->insert(sen);
			if (ptn->find(sen))
			{
				flag = 1;
				printf("NO\n");
				break;
			}			
		}

		if (flag == 0)
			printf("YES\n");
	}//t_c

	return 0;
}