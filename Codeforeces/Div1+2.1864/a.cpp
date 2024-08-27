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
    int x,y,n;cin>>x>>y>>n;
    vector<int>ans;
    ans.push_back(y);
    int t=1;
    while(1){
        if(ans.size()==n)break;
        ans.push_back(y-t);
        y=y-t;
        t++;
    }
    sort(all(ans));
    if(ans[0]<x){
        cout<<-1<<endl;
        return;
    }
    ans[0]=x;
    if(ans.size()==n){
        for(auto i:ans)cout<<i<<' ';cout<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}