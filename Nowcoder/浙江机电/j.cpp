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
int k,n;
int x;
int ksm(int a,int b){
    __int128 ret=1ll;
    while(b){
        if(b&1)ret=ret*a;
        a=a*a;
        if((ret-1)/(k-1)>=x)return -1;
        b>>=1;
    }
    return ret;
}
int check(int mid){
    int t=ksm(k,mid);
    if(t==-1)return 1;
    if((t-1)/(k-1)>=x)return 1;
    else return 0;
}
void solve(){
    cin>>k>>n;
    while(n--){
        cin>>x;
        if(x==1){
            cout<<0<<endl;
            continue;
        }
        if(k==1){
            cout<<x-1<<endl;
            continue;
        }
        int l=0,r=63;
        while(l+1!=r){
            int mid=l+r>>1;
            if(check(mid))r=mid;
            else l=mid;
        }
        cout<<r-1<<endl;
    }    
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}