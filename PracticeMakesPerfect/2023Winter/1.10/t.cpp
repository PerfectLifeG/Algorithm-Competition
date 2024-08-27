#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sc(n) scanf("%lld",&n)
int er[100];
inline int Log2(double x){
	if(x==1)return 0;
	return ((*(unsigned long long*)&x>>52)&1023)+1;
}
signed main(){
    int t;cin>>t;
    er[0]=1;
    for(int i=1;i<64;i++){
        er[i]=er[i-1]*2;
    }
    while(t--){
        int n;sc(n);
        int x;sc(x);
        if(x>n)puts("-1");
        else if(x==n)printf("%lld\n",n);
        else{
            printf("%lld\n",min(((~x)&n)+n, er[Log2(n)+1]));
        }
    }
    return 0;
}