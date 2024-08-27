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
    int n,m;cin>>n>>m;
    char g[n][m];
    for(int i=0;i<n;i++){
        string s;cin>>s;
        for(int j=0;j<m;j++){
            g[i][j]=s[j];
        }
    }
    if(g[0][0]=='B'){
        int f1=0,f2=0;
        for(int i=0;i<n;i++){
            if(g[i][m-1]=='B'){f1=1;break;}
        }
        if(f1)
        for(int j=0;j<m;j++){
            if(g[n-1][j]=='B'){f2=1;break;}
        }
        if(f2){yes;return;}
    }
    if(g[n-1][m-1]=='B'){
        int f1=0,f2=0;
        for(int i=0;i<n;i++){
            if(g[i][0]=='B'){f1=1;break;}
        }
        if(f1)
        for(int j=0;j<m;j++){
            if(g[0][j]=='B'){f2=1;break;}
        }
        if(f2){yes;return;}
    }
    if(g[n-1][m-1]=='W'){
        int f1=0,f2=0;
        for(int i=0;i<n;i++){
            if(g[i][0]=='W'){f1=1;break;}
        }
        if(f1)
        for(int j=0;j<m;j++){
            if(g[0][j]=='W'){f2=1;break;}
        }
        if(f2){yes;return;}
    }
    if(g[0][0]=='W'){
        int f1=0,f2=0;
        for(int i=0;i<n;i++){
            if(g[i][m-1]=='W'){f1=1;break;}
        }
        if(f1)
        for(int j=0;j<m;j++){
            if(g[n-1][j]=='W'){f2=1;break;}
        }
        if(f2){yes;return;}
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