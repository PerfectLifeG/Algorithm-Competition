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

    int t=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(v[i]>n-1){
            t+=(v[i]-(n-1))/(n-1);
            v[i]-=t*(n-1);
            v[i]--;
        }
    }
    int flag=1;
    for(int i=0;i<n;i++){
        v[i]+=t;
    }
    sort(all(v));
    t=n-1;
    for(int i=v.size()-1;i>=0;i--){
        if(v[i]>=t){
            t--;
        }else{
            flag=0;
            break;
        }
    }
    if(flag)cout<<"Recurrent"<<endl;
    else{

    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}