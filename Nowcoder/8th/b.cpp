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
    vector<int>v(n+1,0);
    deque<int>lst[n+1];
    int idx=0;
    // vector<int>book[N];
    // vector<int>cnt(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    vector<int>f(n+1,0);
    // unordered_map<int,int>mp;
    for(int i=1;i<=n;i++){
        // cout<<v[i]<<' ';
        if(v[i]!=1){
            if(!lst[v[i]-1].empty()){
                while(lst[v[i]-1].size()&&lst[v[i]-1].back()<=idx)lst[v[i]-1].pop_back();
                if(lst[v[i]-1].empty()){
                    idx=i;
                    continue;
                }
                f[i]=min(f[lst[v[i]-1].back()],f[i-1]);
                // if(!lst[v[i]].empty()&&lst[v[i]].top()>lst[v[i]-1].top()){
                //     lst[v[i]].pop();
                //     lst[v[i]].push(i);
                // }
                if(v[i]-1>1)
                    lst[v[i]-1].pop_front();
                else lst[v[i]-1].pop_back();
            }
            else
            {
                idx=i;
            }
        }else{
            f[i]=f[i-1]+1;
        }
        lst[v[i]].push_back(i);
        // cnt[v[i]]++;
    }
    int ans=0;
    for(auto i:f){cout<<i<<endl;ans+=i;}
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}