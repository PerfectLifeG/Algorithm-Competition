#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    int n,k;cin>>n>>k;
    k%=(n+1);
    vector<int>a(n+1);
    vector<int>book(n+1);
    for(int i=1;i<=n;i++){
        // int b;cin>>b;
        // a.push_back(b);
        cin>>a[i];
        book[a[i]]++;
    }
    int t=0;
    for(int i=0;i<=n;i++)if(!book[i]){t=i;break;}
    // a.insert(a.begin(),t);
    a[0]=t;
    // if(k>n){
    //         for(auto i:a)cout<<i<<' ';cout<<endl;
    //             return;}
    for(int i=1;i<=n;i++){
        cout<<a[(i-k+n+1)%(n+1)]<<' ';
    }cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}