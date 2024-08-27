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
vector<int>v[10];
int book[10];
int f;
void dfs(int t,int x){
    if(t==10){
        // cout<<x<<endl;
        v[f].push_back(x);
        return;
    }
    for(int i=1;i<=9;i++){
        if(book[i]==2)continue;
        if(book[i]&&f!=i)continue;
        book[i]++;
        dfs(t+1,x*10+i);
        book[i]--;
    }
}
void solve(){
    int n,d;cin>>n>>d;
    int x=12345678*10+d;
    int cnt=0;
    while(n){
        cnt++;
        n/=10;
    }
    
}
signed main(){
    // ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}