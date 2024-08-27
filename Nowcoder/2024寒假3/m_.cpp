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
int check(int t){
    int cnt=0;
    while(t){
        cnt++;
        t/=10;
    }
    return cnt;
}
void solve(){
    int n;cin>>n;
    unordered_map<int,int>mp[20];
    vector<int>v(n);
    for(int i=0;i<n;i++){
        int a;cin>>a;v[i]=a;
        int t=check(a);
        mp[t][a%36]++;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        int f=10ll;
        int p=check(v[i]);
        for(int j=1;j<=18;j++){
            // cout<<p<<' '<<v[i]<<endl;
            int t=(v[i]%36*(f%36)%36+36)%36;
            // cout<<t<<' '<<f<<' '<<v[i]<<endl;
            // cout<<v[i]<<' '<<j<<' '<<f<<' '<<t<<endl;
            if(mp[j].count(((36-t)+36)%36))ans+=mp[j][((36-t)+36)%36];
            if(mp[j].count(((36-t)+36)%36)&&p==j&&(v[i]%36)==((36-t)+36)%36)ans--;
            // if(mp[j][((36-t)+36)%36])cout<<t<<endl;
            f*=10;
        }
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}