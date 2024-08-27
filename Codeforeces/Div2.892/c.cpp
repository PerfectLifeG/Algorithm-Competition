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
    int mx=0;
    for(int i=1;i<=n;i++){
        // 1 2 9 8 7
        int t=0;
        int t2=0;
        // int a=1;
        // 1 2
        for(int j=1;j<i;j++){
            t+=j*j;
            t2=max(t2,j*j);
            // a++;
        }
        int a=i;
        for(int j=n;j>=i;j--){
            t+=j*a;
            t2=max(t2,j*a);
            a++;
        }
        mx=max(mx,t-t2);
    }
    cout<<mx<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}