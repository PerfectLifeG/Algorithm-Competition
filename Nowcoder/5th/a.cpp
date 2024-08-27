#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int exgcd(int a,int b,int &x,int &y){
    if(b==0)return x=1,y=0,a;
    int d=exgcd(b,a%b,x,y);
    int t=x;
    x=y;
    y=t-(a/b)*y;
    return d;
}
void solve()
{
    int k,c,n;
    cin>>k>>c>>n;
    int x,y;
    int a=k,b=1;
    int d=exgcd(a,b,x,y);
    int ans=0,ans2=0;
    if(c%d!=0){
        cout<<0<<endl;
        return;
    }else{
        int b1=b/d;
        int x1=x*c/d;
        x1=(x1%b1+b1)%b1;//防止负数情况出现
        int y1=(c-a*x1)/b;
        cout<<x1<<' '<<c - a*x1<<endl;
        for(int i=0;i<=1e9;i++){//模b下通解
            int q=x1+i*b1,p=(c - a*(x1+i*b1)) / b;
            if(q==0){continue;}
            if(p<=0)break;
            if(c%p!=0||__gcd(q,p)<n){;continue;}
            cout<<q<<' '<<p<<' '<<__gcd(q,p)<<' '<<c%p<<endl;
            // 250000000
            //  50000000
            // 750000000
            //  25000000
            //  12500000
            //  10000000
            //   6250000
            ans++;
            // i++;
        }
        // cout<<
        // b=c-ak
        // ak>c
        // ans++;
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}