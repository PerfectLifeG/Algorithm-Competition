#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=400;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
vector<int>v;
int ret=0;
void dfs(int t){
    if(t==16){v.push_back(ret);return;}
    ret+=1<<(t+10);
    dfs(t+1);
    ret-=1<<(t+10);
    dfs(t+1);
}
int f[N][2];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    dfs(0);
    int T;cin>>T;
    while(T--){
        int n,m;cin>>n>>m;
        cout<<n*m<<endl;
        int idx=0;
        for(int i=0;i<n;i++){
            int t=v[idx];
            cout<<t<<' ';
            for(int j=1;j<m;j++){
                if(j&1){cout<<t+1<<' ';t+=1;}
                else {cout<<t+3<<' ';t+=3;}
            }
            cout<<endl;
            i++;if(i>=n)break;
            t=v[idx++]+2;
            cout<<t<<' ';
            for(int j=1;j<m;j++){
                if(j&1){cout<<t+1<<' ';t+=1;}
                else {cout<<t+3<<' ';t+=3;}
            }
            cout<<endl;
        }
    }
    return 0;
}