#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
int exgcd(int a,int b,int &x,int &y){
    if(b==0)return x=1,y=0,a;
    int ret=exgcd(b,a%b,y,x);//经过这步返回的是x2,y2，然后求x1,y1
    y-=a/b*x;
    return ret;
}
int w[N];
void solve()
{
    int n,p,a,q,b;
    cin>>n>>p>>a>>q>>b;
    b=-b;
    
    int x,y,x1,y1;
    int s=0;
    for(int i=0;i<n;i++){
        cin>>w[i];
        s+=w[i];
    }
    if(s%n==0){
        cout<<0<<endl;
        return;
    }
    int ans=1e18;
    int f1=-(s%n),f2=n-s%n;
    
    swap(a,b);
    int c,d,flag;
    for(int k=0;k<1e6;k++){
        c=f2+k*n;
        flag=1;
        exgcd(a,b,x,y);
        d=__gcd(a,b);
        if(c % d != 0)flag=0;
        else
        {
            int b1 = b / d;
            if(b1<0)b1=-b1;
            x1 = (x + b1) * (c / d);
            x1 = (x1 % b1 + b1) % b1;
            y1 = (c - a*x1) / b;
            // cout<<x1<<' '<<y1<<endl;
        }
        if(flag)ans=min(ans,q*x1+p*y1);
    }
    

    // c=f2+n;
    // exgcd(a,b,x,y);
    // d=__gcd(a,b);
    // flag=1;
    // if(c % d != 0)flag=0;
    // else
    // {
    //     int b1 = b / d;
    //     if(b1<0)b1=-b1;
    //     x1 = (x + b1) * (c / d);
    //     x1 = (x1 % b1 + b1) % b1;
    //     y1 = (c - a*x1) / b;
    //     // cout<<x1<<' '<<y1<<endl;
    // }
    // if(flag)ans=min(ans,q*x1+p*y1);

    swap(a,b);
    for(int k=0;k<1e6;k++){
        c=f1-k*n;
        exgcd(a,b,x,y);
        d=__gcd(a,b);
        flag=1;
        if(c % d != 0)flag=0;
        else
        {
            int b1 = b / d;
            if(b1<0)b1=-b1;
            x1 = (x + b1) * (c / d);
            x1 = (x1 % b1 + b1) % b1;
            y1 = (c - a*x1) / b;
            // cout<<x1<<' '<<y1<<endl;
        }
        if(flag)ans=min(ans,p*x1+q*y1);
    }

    // c=f1-n;
    // exgcd(a,b,x,y);
    // d=__gcd(a,b);
    // flag=1;
    // if(c % d != 0)flag=0;
    // else
    // {
    //     int b1 = b / d;
    //     if(b1<0)b1=-b1;
    //     x1 = (x + b1) * (c / d);
    //     x1 = (x1 % b1 + b1) % b1;
    //     y1 = (c - a*x1) / b;
    //     // cout<<x1<<' '<<y1<<endl;
    // }
    // if(flag)ans=min(ans,p*x1+q*y1);

    if(ans==1e18)cout<<-1;
    else cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}