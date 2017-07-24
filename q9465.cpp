#include <iostream>
#include <cstdio>
using namespace std;
long long sticker[100001][2];
long long d[100001][3];
int max(int a, int b)
{
	if ( a >b )
		return a;
	else 
		return  b;
}

int main()
{
	int T=0; //테스트 케이스 개수
	int n=0;
	scanf("%d", &T);

	while(T--)
    {
		cin >> n;        
		for ( int i = 1 ; i <=n ; i ++ )
		{
                scanf("%d", &sticker[i][0]);
		}
        
        for ( int i = 1 ; i <=n ; i ++ )
		{
                scanf("%d", &sticker[i][1]);
		}
        
		d[n+1][0] = 0;
		d[n+1][1] = 0;
		d[n+1][2]= 0;

		for ( int i = n ; i >= 1 ; i--)
		{
		    d[i][0] = max(max(d[i+1][0],d[i+1][2]),d[i+1][1]);
		    d[i][1] = max(d[i+1][0],d[i+1][2])+sticker[i][0];
		    d[i][2] = max(d[i+1][0],d[i+1][1])+sticker[i][1];
		}
        long long ans = 0;
        for (int i=n+1; i>=1; i--) 
        {
            ans = max(max(ans,d[i][0]),max(d[i][1],d[i][2]));
        }
		printf("%lld\n",ans);
	}
	return 0 ;
}