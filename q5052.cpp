#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
#define NUM 10

struct node {
	bool is_end;
	int prefix_cnt;
	struct node* child[NUM];
}*head;

void init()
{
	head = new node();
	head->is_end = 0;
	head->prefix_cnt = 0;
}

void insert(int buf_size, string buf)
{
	node *current = head;
	current->prefix_cnt++;

	for (int i = 0; i < buf_size; i++)
	{
		int letter = (int)(buf[i] - '0');
		if (current->child[letter] == NULL)
			current->child[letter] = new node();

		current->child[letter]->prefix_cnt++;
		current = current->child[letter];
	}
	current->is_end = true;
}

bool get_prefix(int buf_size, string buf)
{
	node* current = head;

	for (int i = 0; i < buf_size; i++)
	{
		int letter = (int)(buf[i] - '0');
		if (current->child[letter] == NULL)
			return true;//겹치는 것 없음

		if (current->is_end == true)
			return false;
		current = current->child[letter];
	}

	if (current->prefix_cnt >= 2)
		return false;
	else
		return true;
}

int main()
{
	int t = 0;
	scanf("%d", &t);
	for (int t_c = 0; t_c < t; t_c++)
	{
		init();
		int n = 0;
		scanf("%d", &n);
		int flag = 0;
		for (int i = 0; i < n; i++)
		{
			string s;
			cin >> s;

			insert(s.size(), s);
			if (get_prefix(s.size(), s) == 0)
				flag = 1;

		}

		if (flag == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}//for t_c

	return 0;
}