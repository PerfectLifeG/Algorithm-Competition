#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,m;
int find(int x){
    //if(x==k)return 1;
    int sum=0;
    int cnt=1;
    int l=x*k+1;
    while(l<=n-1){
        cnt*=k;
        l=l*k+1;
    }
    sum=(cnt-1)/(k-1);
    if((l-1)/k+cnt-1<=n-1)sum+=cnt;
    else sum+=n-(l-1)/k;
    return sum;
}
signed main(){
    int t;cin>>t;
    while(t--){
        scanf("%lld%lld%lld",&n,&k,&m);
        for(int i=0;i<m;i++){
            int a;scanf("%lld",&a);
            if(k==1)printf("%lld\n",n-a);
            else printf("%lld\n",find(a));
        }
    }
    return 0;
}