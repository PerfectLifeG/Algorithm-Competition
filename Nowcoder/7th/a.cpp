#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
int s[11];
int p[11];
int sum[11];
void solve()
{
    int n;cin>>n;
    int cnt=0;
    int t=n;
    while(t>0){
        cnt++;
        t/=10;
    }
    cout<<(n-p[cnt]+1)*cnt+sum[cnt-1]<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    int a=9,b=1;
    for(int i=1;i<=10;i++){
        s[i]=(a-b+1)*i;
        a=a*10+9;
        b*=10;
    }
    p[1]=1;
    for(int i=2;i<=10;i++){
        p[i]=p[i-1]*10;
    }
    for(int i=1;i<=10;i++){
        sum[i]=sum[i-1]+s[i];
    }
    while(_--)solve();
    return 0;
}