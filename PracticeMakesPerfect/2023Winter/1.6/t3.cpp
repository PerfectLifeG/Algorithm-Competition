#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
typedef long long LL;
LL book[N];
inline LL read()
{
	LL x = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch))
	{
		if (ch == '-') 
			f = -1;
		ch = getchar();
	}
	while (isdigit(ch))
	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)book[i]=i-1;
    while(k--){
        LL a,b;
        a=read();b=read();
        if(a==1){
            book[b+1]=book[b];
        }
        else{
            printf("%lld\n",book[b]);
        }
    }
    return 0;
}