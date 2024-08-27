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
    int n;cin>>n;
    vector<int>a;
    vector<int>book(n+1);
    // int book[n+1]={};
    for(int i=1;i<=n;i++){
        if(book[i])continue;
        for(int j=i;j<=n;j*=2){
            if(!book[j])
            a.push_back(j);
            book[j]=1;
        }
    }
    for(auto i:a){
        cout<<i<<' ';
    }
    cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}