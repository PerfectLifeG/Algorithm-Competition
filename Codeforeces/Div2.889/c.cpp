#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    int n;cin>>n;
    vector<int>a(n+1);
    int cnt=0;
    int f=0,mx=0;
    int flag=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>=2&&a[i]<a[i-1]&&!flag){flag=i;}
        if(a[i]>mx){f=i;mx=a[i];}
    }
    // cout<<flag<<endl;
    if(flag==0)flag=2;
    if(flag>f)flag=f;
    if(f){
        int t=6;
        cout<<8+2*(n-flag)<<endl;
        while(t--){
            cout<<f<<' '<<f<<endl;
            a[f]+=a[f];
        }
        cout<<flag<<' '<<f<<endl;
        cout<<flag<<' '<<f<<endl;
        a[flag]+=a[f];
        a[flag]+=a[f];
        for(int i=flag+1;i<=n;i++){
            cout<<i<<' '<<i-1<<endl;
            cout<<i<<' '<<i-1<<endl;
            a[i]+=a[i-1];
            a[i]+=a[i-1];
        }
    }else{
        int t=6;
        cout<<6+2*(n-1)<<endl;
        while(t--){
            cout<<n<<' '<<n<<endl;
            a[n]+=a[n];
        }
        for(int i=n-1;i>=1;i--){
            cout<<i<<' '<<i+1<<endl;
            cout<<i<<' '<<i+1<<endl;
            a[i]+=a[i+1];
            a[i]+=a[i+1];
        }
    }
    // cout<<endl;
    // for(int i=1;i<=n;i++){
    //     cout<<a[i]<<' ';
    // }
    // cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}