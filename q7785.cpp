#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <set>
using namespace std;
//endl 시간초과될때는 '\n' 로 바꾸기
/*
map보다 set이 속도 더 빠름

- map
key, value 한쌍임
트리구조임
맵은 자동 정렬이 됨
검색속도가 일렬 방식(list, vector)보다 빠름
단점으로는 삽입 삭제가 빈번하면 안됨!!!(할때마다 정렬하고 있음.)

-set
map과 같은 기능 이지만 map과는 다르게 key만 저장(고로... 트리 구조?)
key를 신속하게 찾고, 또 key가 정렬되기를 원할때 사용됨.
*/
int main()
{
	int n = 0;
	string name;
	string el;//e=enter ; l=leave
	set <string> s;
	set<string>::reverse_iterator iter;
	cin >> n;

	while (n--)
	{
		cin >> name >> el;
		if (el == "enter")
			s.insert(name);

		else //el == "leave"
			s.erase(name);//s.erase(s.find(name));
	}
	
	for (iter = s.rbegin(); iter != s.rend(); iter++)
			cout << (*iter) <<'\n';

	return 0;
}