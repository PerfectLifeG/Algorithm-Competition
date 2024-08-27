#include<bits/stdc++.h>
using namespace std;
const int N=10010;
const int mod=998244353;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
inline int Log2(double x){
	if(x==1)return 0;
	return ((*(unsigned long long*)&x>>52)&1023)+1;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        int l,r;cin>>l>>r;
        int ans=0,cnt=0;
        int mx=Log2(r);
        while(l*(1<<mx)>r)mx--;
        int t=1<<mx;
        int mx3=0;
        if(t/2*3<(1<<(mx+1))&&l*t/2*3<=r)mx3=1;
        // for(int i=l;i*t<=r;i++){
        //     cnt++;cnt%=mod;
        //     if(mx3&&i*t/2*3<=r)cnt+=mx;cnt%=mod;
        // }
        int a=l-1,b=r+1;
        while(a+1!=b){
            int mid=a+b>>1;
            if(mid*t/2*3<=r)a=mid;
            else b=mid;
        }
        cnt=cnt+mx*(a-l+1);
        cout<<mx+1<<' '<<cnt%mod<<endl;
    }
    return 0;
}