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
const int N=524288;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
int nx[30*N][2],val[30*N],idx=1;
void solve(){
    int n,q;cin>>n>>q;
    vector<int>a(n+1);
    auto insert=[&](int x,int v){
        int t=0;
        for(int i=29;i>=0;i--){
            int j=x>>i&1;
            if(!nx[t][j])nx[t][j]=idx++;
            t=nx[t][j];
            val[t]+=v;
        }
    };

    int X;
    auto query=[&](int x){//查询x^k<=X的和
        int t=0;
        int res=0;
        for(int i=29;i>=0;i--){
            int j=x>>i&1;
            if(X>>i&1){
                if(nx[t][j])res+=val[nx[t][j]];
                if(!nx[t][j^1]) return res;
                else t=nx[t][j^1];
            }else{
                if(!nx[t][j]) return res;
                else t=nx[t][j];
            }
        }
        res+=val[t];
        return res;
    };

    for(int i=0;i<n;i++){
        cin>>a[i];
        insert(i,a[i]);
    }
    while(q--){
        int op,i;cin>>op>>i>>X;
        if(op==1){
            insert(i,X-a[i]);
            a[i]=X;
        }else{
            cout<<query(i)<<endl;
        }

    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}