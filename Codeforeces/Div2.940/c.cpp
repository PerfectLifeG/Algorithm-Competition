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
const int N=3e5+10;
const int mod=1e9+7;
const int INF=0x3f3f3f3f3f3f3f3f;
int a[N];
void solve(){
    int n,k;cin>>n>>k;
    vector<int>book(n+1);
    for(int i=0;i<k;i++){
        int a,b;cin>>a>>b;
        book[a]=1;
        book[b]=1;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(!book[i])ans++;
    }
    cout<<a[ans]<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    a[0]=1;
    a[1]=1;
    a[2]=3;
    for(int i=3;i<N;i++){
        a[i]=a[i-1]+2*(i-1)*a[i-2];
        a[i]%=mod;
    }
    while(_--)solve();
    return 0;
}