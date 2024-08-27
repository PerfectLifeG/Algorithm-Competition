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
const int INF=0x3f3f3f3f;
void solve(){
    int n;cin>>n;
    int a,b;cin>>a>>b;
    char q,w;
    if(b<=n/2){
        q='L';
    }else q='R';
    if(a<=n/2){
        w='U';
    }else w='D';
    for(int i=0;i<n-1;i++){
        cout<<q;
    }
    for(int i=0;i<n-1;i++){
        cout<<w;
    }
    for(int i=0;i<min(a-1,n-a);i++){
        if(w=='U')cout<<'D';
        else cout<<'U';
    }
    for(int i=0;i<min(b-1,n-b);i++){
        if(q=='R')cout<<'L';
        else cout<<'R';
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}