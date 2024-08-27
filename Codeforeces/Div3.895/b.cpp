#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define x first
#define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int a[N];
int n;
int check(int mid){

    for(int i=1;i<mid;i++){
        if(2*(mid-i)>=a[i]){return 0;}
    }
    return 1;
}
void solve(){
    cin>>n;
    for(int i=0;i<=400;i++)a[i]=1e9;
    for(int i=0;i<n;i++){
        int c,b;cin>>c>>b;
        a[c]=min(a[c],b);
    }
    int l=1,r=n+1;
    for(int i=400;i>=1;i--){
        if(check(i)){
            cout<<i<<endl;return;
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}