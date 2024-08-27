#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    int n,k;cin>>n>>k;
    int sum=0;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        sum+=a;k-=a*a;
    }
    k/=4;
    int l=0,r=1e9;
    while(l+1!=r){
        int w=l+r>>1;
        if(__int128(n)*w*w+__int128(sum)*w>=k){//不能先爆！
            r=w;
        }else l=w;
    }
    cout<<r<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}