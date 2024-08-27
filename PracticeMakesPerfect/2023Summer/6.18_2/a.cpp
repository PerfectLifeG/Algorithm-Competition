#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
int book[N];
void solve(){
    int n;cin>>n;
    memset(book,0,sizeof(book));
    int mx=0;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        mx=max(mx,a);
        book[a]++;
    }
    for(int i=1;i<=mx;i++){
        // cout<<i<<' '<<book[i]<<endl;
        if(book[i]>book[i-1]){
            no;
            return;
        }
    }
    yes;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}