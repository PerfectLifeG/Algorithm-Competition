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
    int n,k;cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(all(v));
    int a=0,b=0;
    int idx=0;
    for(int i=0;i<n;i++){
        if(v[i]==idx){idx++;continue;}
        if(idx&1){
            b+=(v[i]-idx+1)/2;
            a+=(v[i]-idx)/2;
        }else{
            b+=(v[i]-idx)/2;
            a+=(v[i]-idx+1)/2;
        }
        idx=v[i]+1;
    }
    if(v[0]&1){
        0 1 2 3 4 6 8 9
    }
    if(v[n-1]){

    }
    a-=k,b-=k;
    if(a>b){
        cout<<"Bob"<<endl;
        continue;
    }else if(a<b){
        cout<<"Alice"<<endl;
        continue;
    }
    if(a[n-1]&1){
        if()
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}