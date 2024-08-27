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
    string a,b;cin>>a>>b;
    int n=a.size();
    if(a[0]!=b[0]||a[n-1]!=b[n-1]){
        no;
        return;
    }
    int i0=-1,i1=-1;
    for(int i=0;i<n-1;i++){
        if(a[i]==b[i]&&a[i]==a[0]&&b[i+1]==a[i+1]&&b[i+1]==b[n-1]){
            yes;
            return;
        }
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