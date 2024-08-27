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
unordered_map<int,int>mp;
void solve()
{
    int s,k;cin>>s>>k;
    int mx=s*k;

    function<void(int,int)> f=[&](int s,int k){
        if(k<0)return;
        if(s%10==0){
            mx=max(mx,s*k);
        }else if(s%10==2){
            int x=max(0ll,k/2-s/10);
            for(int i=max(0ll,x-10);i<=x+10;i++){
                if(k>=i)
                mx=max(mx,(s+20*(i/4)+mp[i%4])*(k-i));
            }
        }else{
            mx=max(mx,s*k);
            f(s+s%10,k-1);
        }
    };
    f(s,k);
    cout<<mx<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    mp[0]=0;mp[1]=2,mp[2]=6,mp[3]=14;
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}