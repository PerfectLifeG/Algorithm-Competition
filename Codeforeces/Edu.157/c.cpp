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
    map<PII,int>mp;
    vector<string>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    sort(all(v),[&](string &a,string &b){
        return a.size()<b.size();
    });
    int ans=n;
    for(int i=0;i<n;i++){
        string s=v[i];
        int t=s.size();
        for(int j=t+1;j<=t*2;j++){
            if(j%2==0){
                int x1=0,x2=0;
                for(int k=0;k<j/2;k++)x1+=s[k]-'0';
                for(int k=j/2;k<t;k++)x2+=s[k]-'0';
                ans+=mp[{j-t,x1-x2}];
                x1=0,x2=0;
                for(int k=0;k<t-j/2;k++)x1+=s[k]-'0';
                for(int k=t-j/2;k<t;k++)x2+=s[k]-'0';
                ans+=mp[{j-t,x2-x1}];
            }
        }
        int ret=0;
        for(auto x:s)ret+=x-'0';
        mp[{t,ret}]++;
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}