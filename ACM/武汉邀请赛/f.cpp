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
const int INF=0x3f3f3f3f3f3f3f3f;
int n,k;
int check(int mid){
    int cnt=0;
    int x=n,y=1;
    while(x>=1&&y<=n){
        cout<<'?'<<' '<<x<<' '<<y<<' '<<mid<<endl;
        int op;cin>>op;
        if(op==1){
            cnt+=x;
            y++;
        }else{
            x--;
        }
    }
    // cout<<cnt<<endl;
    return cnt;
}
void solve(){
    cin>>n>>k;
    int l=0,r=n*n+1;
    while(l+1!=r){
        int mid=l+r>>1;
        // cout<<l<<' '<<r<<' '<<n-k+1<<endl;
        if(check(mid)>=n*n-k+1)r=mid;
        else l=mid;
        // cout<<l<<' '<<r<<endl;
    }
    cout<<"! "<<r<<endl;
}
signed main(){
    // ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}