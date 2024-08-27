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
    char g[5][10]={};
    int t=0;
    for(int i=0;i<5;i++){
        string s;
        getline(cin,s);
        for(int j=0;j<10;j++){
            g[i][j]=s[j];
        }
    }
    int a=g[1][0]-'0';
    int b=g[3][0]-'0';
    cout<<a<<' '<<b<<endl;
    if(g[2][5]=='&'){
        cout<<(a&b)<<endl;
    }else 
    if(g[2][5]=='1'){
        cout<<!(g[2][0]-'0')<<endl;
    }
    else cout<<(a|b)<<endl;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}