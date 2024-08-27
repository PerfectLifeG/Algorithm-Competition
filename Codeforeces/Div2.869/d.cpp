#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define x first
#define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int n,m;cin>>n>>m;
    vector<int>v[n+1];
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<PII>ans;
    vector<int>book(n+1);
    int st;
    function<int(int)> dfs=[&](int t)->int{
        for(auto j:v[t]){
            if(book[j]==2||book[j]==3)continue;
            ans.push_back({t,j});
            if(t!=st&&book[j]==1){book[j]=2;ans.push_back({j,st});return 1;}
            book[j]=2;
            if(dfs(j))return 1;
            ans.pop_back();
            book[j]=3;
        }
        return 0;
    };
    for(int i=1;i<=n;i++){
        if(v[i].size()>=4){
            book.assign(book.size(),0);
            ans.clear();
            st=i;
            book[i]=2;
            for(auto j:v[i]){
                book[j]=1;
            }
            if(!dfs(i))continue;
            int c=0;
            for(auto j:v[i]){
                if(book[j]!=2){
                    ans.push_back({i,j});
                    c++;
                }
                if(c==2)break;
            }
            yes;
            cout<<ans.size()<<endl;
            for(auto i:ans){
                cout<<i.x<<' '<<i.y<<endl;
            }
            return;
        }
    }
    no;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}