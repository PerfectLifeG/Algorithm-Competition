#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=1e4+10;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n,m;cin>>n>>m;
    vector<int>v[n+1];
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    vector<int>col(n+1);
    int flag=0;col[1]=1;
    function<void(int,int)> dfs=[&](int t,int fa){
        if(flag)return;
        for(auto j:v[t]){
            if(j==fa)continue;
            if(!col[j]){
                col[j]=-col[t];
                dfs(j,t);
            }else if(col[j]==col[t])flag=1;
         }
    };
    dfs(1,1);

    if(flag){
        cout<<"Alice"<<endl;
        for(int i=0;i<n;i++){
            cout<<"1 2"<<endl;
            int a,b;cin>>a>>b;
        }
    }else{
        vector<int>v1,v2;
        for(int i=1;i<=n;i++){
            if(col[i]==-1)v1.push_back(i);
            else v2.push_back(i);
        }
        cout<<"Bob"<<endl;
        for(int i=0;i<n;i++){
            int a,b;cin>>a>>b;
            if((a==1||b==1)&&v1.size()){
                cout<<v1.back()<<' '<<1<<endl;
                v1.pop_back();
            }
            else if((a==2||b==2)&&v2.size()){
                cout<<v2.back()<<' '<<2<<endl;
                v2.pop_back();
            }else{
                if(v1.size()){
                    cout<<v1.back()<<' '<<3<<endl;
                    v1.pop_back();
                }else{
                    cout<<v2.back()<<' '<<3<<endl;
                    v2.pop_back();
                }
            }
        }
    }
}
signed main(){
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}