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
int dir[4][2]={0,1,1,0,0,-1,-1,0};
void solve(){
    int T;cin>>T;
    int m;int n;
    for(int i=1;i<=T/i;i++){
        if(T%i==0){
            m=i,n=T/i;
        }
    }
    vector<int>v;
    for(int i=0;i<T;i++){
        int a;cin>>a;
        v.push_back(a);
    }
    sort(all(v),greater<>());
    vector<vector<int>> ans(n,vector<int>(m,-1));
    int tx=0,ty=-1;
    int flag=0;
    for(int i=0;i<T;i++){
        int a=tx+dir[flag][0],b=ty+dir[flag][1];
        if(a<0||b<0||a>=n||b>=m||ans[a][b]!=-1){flag++;flag%=4;}
        tx+=dir[flag][0],ty+=dir[flag][1];
        ans[tx][ty]=v[i];
    }
    for(int i=0;i<n;i++){
        cout<<ans[i][0];
        for(int j=1;j<m;j++){
            cout<<' '<<ans[i][j];
        }cout<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}