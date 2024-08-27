#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int l,r,cnt;cin>>l>>r>>cnt;
    l--,r++;
    int x=1;
    while(l+1!=r){
        int mid=l+r>>1;
        if(x==cnt){
            cout<<mid<<endl;
            return;
        }
        if(r-mid>l-mid)l=mid;
        else r=mid;
        x++;
    }
    cout<<-1<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}