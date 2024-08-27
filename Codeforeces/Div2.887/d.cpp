#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    int n;cin>>n;
    vector<PII>v(n+1);
    for(int i=1;i<=n;i++){
        int a;cin>>a;
        v[i]={a,i};
    }
    sort(v.begin()+1,v.end(),[&](PII a,PII b){
        return a.first>b.first;
    });
    int l=1,r=n;
    int x=n;
    vector<int>ans(n+1);
    // for(int i=1;i<=n;i++){
    //     cout<<v[i].first<<' '<<v[i].second<<endl;
    // }
    while(l<=r){
        if(v[l].first==r){
            ans[v[l].second]=x;
            l++;
            x--;
        }else if(v[r].first==l-1){
            ans[v[r].second]=-x;
            r--;
            x--;
        }else{
            no;
            return;
        }
    }
    yes;
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}