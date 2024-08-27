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
const int N=500010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
int a[N];
int n,L,R;
int check(int mid){
    int res=0;
    for(int i=1;i<=n;i++){
        res+=min(a[i],mid);
    }
    return res>=L*mid;
}
void solve(){
    cin>>n>>L>>R;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]=(a[i]-1)/2;
    }

    int l=0,r=1e9;
    while(l+1!=r){
        int mid=l+r>>1;
        if(check(mid))l=mid;
        else r=mid;
    }
    if(R+l*(R-L)>=n)yes;
    else no;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}