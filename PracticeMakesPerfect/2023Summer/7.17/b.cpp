#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int qk(int a,int b)
{
    int ans=1;
    while(b)
    {
        if(b&1)ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}
int inv(int a)
{
    return qk(a,mod-2);
}
signed main()
{
    int n,m;
    scanf("%lld%lld",&n,&m);
    int i;
    int j;
    int st=1;
    int ed=1;
    while(1){
        st*=2;//1 2 4 8 9
        if(n<(st-1))break;
    }
    st--;//31
    while(1){
        //1 2 4 8 16
        if(n+m<(ed*2-1))break;
        ed*=2;
    }
    ed--;//127
    int t=0;//项数n
    for(int i=st+1;i<ed+1;i*=2){
        t++;
    }
    int a=0;//31的次数 4
    int ss=st;
    while(ss){
        a++;
        ss/=2;//15 7 3 1 0
    }
    int ans=0;
    ans=(qk(2,t)-1)*a;//4*(1-2^2)
    int st1=a-1,ed1=a+t;//次数
    int a1=(st-n)*(qk(2,st1)-1)*inv(qk(2,st1));
    int a2=(n+m-ed)*(qk(2,ed1)-1)*inv(qk(2,ed1));

    cout<<st<<' '<<ed<<' '<<t<<' '<<ans<<endl;
    cout<<a<<' '<<st1<<' '<<ed1<<endl;
    
    ans=(ans+a1+a2)%mod;
    cout<<ans<<endl;
    return 0; 
}