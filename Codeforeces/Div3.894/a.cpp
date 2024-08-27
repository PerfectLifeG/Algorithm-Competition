#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    int n,m;cin>>n>>m;
    char c[n][m];
    for(int i=0;i<n;i++){
        string s;cin>>s;
        for(int j=0;j<m;j++){
            c[i][j]=s[j];
        }
    }
    char mp[4]={'v','i','k','a'};
    int f=0;
    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++){
            if(c[i][j]==mp[f]){
                f++;break;
            }
        }
    }
    if(f==4){
        yes;
    }else no;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}