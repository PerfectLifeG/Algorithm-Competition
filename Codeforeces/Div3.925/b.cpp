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
    vector<int>v(n);
    int s=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        s+=v[i];
    }
    int t=s/n;
    int c=0;
    for(int i=n-1;i>=0;i--){
        if(v[i]>t){
            if(v[i]-t>c){
                no;
                return;
            }else c-=(v[i]-t);
        }else c+=t-v[i]; 
    }
    yes;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}