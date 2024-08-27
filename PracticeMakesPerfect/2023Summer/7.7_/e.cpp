#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
set<int>s;
void solve()
{
    int n;cin>>n;
    if(s.find(n)!=s.end())yes;
    else no;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int _=1;
    cin>>_;
    for(int i=2;i*i+i+1<=1e18;i++){
        int t=i;
        int a=i;
        while(t+1<=1e18){
            t+=a*i;
            a=a*i;
            s.insert(t+1);
        }
        00111111111
        
    }
    while(_--)solve();
    return 0;
}