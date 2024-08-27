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
unordered_map<int,int>mp;
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    int t=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        t+=a[i];
    }
    if(t%n){
        no;
        return;
    }
    t/=n;
    // cout<<t<<endl;
    unordered_map<int,int>ru,chu;
    for(int i=0;i<n;i++){
        int d=1;
        int f=0;
        for(int j=0;j<32;j++){
            // cout<<a[i]<<' '<<d<<' '<<d-(t-a[i])<<endl;
            if(mp.count(d-(t-a[i]))){f=1;ru[j]++,chu[mp[d-(t-a[i])]]++;break;}
            d*=2;
        }
        if(!f){
            no;
            return;
        }
    }
    for(auto i:ru){if(i.y!=chu[i.x]){no;return;}}
    // for(auto i:chu){cout<<i.x<<' '<<i.y<<endl;if(i.y&1){no;return;}}
        yes;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    int d=1;
    for(int i=0;i<32;i++){mp[d]=i;d*=2;}
    while(_--)solve();
    return 0;
}