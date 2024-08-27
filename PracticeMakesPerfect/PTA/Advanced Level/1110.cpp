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
    vector<int>L(n,-1);
    vector<int>R(n,-1);
    vector<int>book(n);
    for(int i=0;i<n;i++){
        string a,b;cin>>a>>b;
        int t;
        if(a!="-"){
            t=stoi(a);
            L[i]=t;
            book[t]=1;
        }
        if(b!="-"){
            t=stoi(b);
            R[i]=t;
            book[t]=1;
        }
    }
    int root;
    for(int i=0;i<n;i++)if(!book[i]){root=i;break;}
    
    vector<int>ans(n);
    function<bool(int,int)> dfs=[&](int t,int idx)->bool{
        ans[idx]=t;
        if(L[t]!=-1){
            if(idx*2+1>=n)return 0;
            if(!dfs(L[t],idx*2+1))return 0;
        }
        if(R[t]!=-1){
            if(idx*2+2>=n)return 0;
            if(!dfs(R[t],idx*2+2))return 0;
        }
        return 1;
    };

    if(!dfs(root,0)){
        cout<<"NO"<<' '<<root<<endl;
    }else cout<<"YES"<<' '<<ans[n-1]<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}