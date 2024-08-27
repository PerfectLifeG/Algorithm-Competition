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
void solve(){
    int n;cin>>n;
    int cnt1=0,cnt2=0;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a&1)cnt1++;
        else cnt2++;
    }
    if(cnt1>=cnt2){
        cnt1-=cnt2;
        cnt2=0;
    }else{
        cnt2-=cnt1;
        cnt1=0;
    }
    cnt1%=2;
    cout<<cnt1+cnt2<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}