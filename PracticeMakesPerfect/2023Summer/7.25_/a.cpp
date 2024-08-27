#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
// int a[N];
void solve()
{
    int n,m,k,h;cin>>n>>m>>k>>h;
    int cnt=0;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        if(abs(a-h)%k==0&&((abs(a-h)/k)<m)&&a!=h){
            cnt++;
        }
    }
    cout<<cnt<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}