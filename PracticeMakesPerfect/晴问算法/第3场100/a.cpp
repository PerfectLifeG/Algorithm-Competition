#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n;cin>>n;
    int l=-1e9,r=1e9;
    for(int i=0;i<n;i++){
        char op[2];int x;
        cin>>op;cin>>x;
        if(*op=='L'){r=min(r,x);
        }else 
            l=max(l,x);
    }
    if(l>r)cout<<-1<<endl;
    else cout<<r-l+1<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}