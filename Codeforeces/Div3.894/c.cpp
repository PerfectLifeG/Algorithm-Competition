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
    vector<int>a(n+1);
    int flag=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int r=n;
    for(int i=1;r>=1&&i<=n;i++){
        while(r>=1&&a[r]<i)r--;
        if(a[i]!=r){
            no;
            return;
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