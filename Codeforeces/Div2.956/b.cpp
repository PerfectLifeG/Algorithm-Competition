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
    int a[n+2][m+2]={};
    int b[n+2][m+2]={};
    for(int i=0;i<n;i++){
        string s;cin>>s;
        for(int j=0;j<m;j++){
            a[i][j]=s[j]-'0';
        }
    }
    for(int i=0;i<n;i++){
        string s;cin>>s;
        for(int j=0;j<m;j++){
            b[i][j]=s[j]-'0';
        }
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m-1;j++){
            if((a[i][j]+1)%3==b[i][j]){
                a[i][j]=(a[i][j]+1)%3;a[i][j+1]=(a[i][j+1]+2)%3;
                a[i+1][j]=(a[i+1][j]+2)%3;a[i+1][j+1]=(a[i+1][j+1]+1)%3;
            }else if((a[i][j]+2)%3==b[i][j]){
                a[i][j]=(a[i][j]+2)%3;a[i][j+1]=(a[i][j+1]+1)%3;
                a[i+1][j]=(a[i+1][j]+1)%3;a[i+1][j+1]=(a[i+1][j+1]+2)%3;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]!=b[i][j]){no;return;}
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