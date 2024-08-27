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
void solve(){
    int n;cin>>n;
    vector<int>v(n+1);
    for(int i=1;i<=n;i++){
        int a;cin>>a;
        v[i]=a;
    }
    vector<int>rs2(n+1);rs2[1]=1;rs2[n]=v[2]-v[1];
    vector<int>ls2(n+1);ls2[n-1]=1;ls2[1]=v[2]-v[1];
    for(int i=2;i<=n-1;i++){
        if(v[i]-v[i-1]>v[i+1]-v[i]){
            rs2[i]=1;
            if(!ls2[i])ls2[i]=v[i+1]-v[i];
            if(!ls2[i-1])ls2[i-1]=v[i]-v[i-1];
        }else {
            ls2[i-1]=1;
            if(!rs2[i-1])rs2[i-1]=v[i-1]-v[i];
            if(!rs2[i])rs2[i]=v[i+1]-v[i];
        }
    }
    for(int i=1;i<=n;i++){
        // cout<<i<<' '<<rs[i]<<' '<<rs2[i]<<' '<<ls[i]<<' '<<ls2[i]<<endl;
        rs2[i]+=rs2[i-1];
        ls2[i]+=ls2[i-1];
    }
    int m;cin>>m;
    while(m--){
        int a,b;cin>>a>>b;
        int t=abs(v[a]-v[b]);
        if(a<b){
            cout<<min(t,rs2[b-1]-rs2[a-1])<<endl;
        }else{
            cout<<min(t,ls2[a-1]-ls2[b-1])<<endl;
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