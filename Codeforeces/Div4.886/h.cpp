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
    int n,m;cin>>n>>m;
    vector<vector<PII>>v(n);
    vector<int>book(n);
    vector<int>d(n);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        a--,b--;
        v[a].push_back({b,-c});
        v[b].push_back({a,c});
    }
    queue<int>q;
    for(int i=0;i<n;i++){
        if(!book[i]){
            q.push(i);
            while(q.size()){
                auto t=q.front();
                // cout<<t<<endl;
                q.pop();
                for(int i=0;i<v[t].size();i++){
                    int j=v[t][i].first;
                    if(!book[j])d[j]=d[t]+v[t][i].second;
                    else if(d[j]!=d[t]+v[t][i].second){no;return;}
                    if(!book[j])q.push(j);
                    book[j]=1;
                }
            }
        }
    }
    yes;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}