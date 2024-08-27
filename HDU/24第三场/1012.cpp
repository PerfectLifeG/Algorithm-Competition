#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin()+1,x.end()
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
    int n,L,D;cin>>n>>L>>D;
    vector<int>a(n);
    int c1=0,c2=0;
    int x;cin>>x;
    for(int i=1;i<n;i++){
        cin>>a[i];
    }
    sort(all(a));
    if(x<L){
        int c=0;
        int mx=0,mn=1e9;
        for(int i=1;i<n;i++){
            if(a[i]<L){c++;mx=max(mx,a[i]);mn=min(mn,a[i]);}
        }
        if(c<2){no;return;}
        mx=max(mx,a[n-1]);
        mx=max(mx,x);
        mn=min(mn,x);
        if(mx-mn>D){
            yes;
        }else no;
    }else{
        int c=0;
        int mx=0,mn=1e9;
        for(int i=1;i<n;i++){
            if(a[i]<L){c++;mx=max(mx,a[i]);mn=min(mn,a[i]);}
        }
        if(c<3){no;return;}
        mx=max(mx,x);
        mn=min(mn,x);
        if(mx-mn>D){
            yes;
        }else no;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}