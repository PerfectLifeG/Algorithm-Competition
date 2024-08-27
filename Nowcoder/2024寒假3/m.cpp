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
        cnt+=t%10;
        t/=10;
    }
    return cnt;
}
int check2(int t){
    t%=100;
    return t%4;
}
void solve(){
    int n;cin>>n;
    unordered_map<int,int>mp;
    int t6=0,t2=0;
    int t3=0,t7=0;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        int a;cin>>a;v[i]=a;
        int t=check(a);
        mp[t%9]++;
        if(a%10==3)t3++;
        if(a%10==7)t7++;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(v[i]>10&&!check2(v[i])){
            int t=check(v[i]);
            // cout<<v[i]<<' '<<t<<endl;
            ans+=mp[(9-t)+9%9];
            if((9-t)+9%9==0)ans--;
        }else if(v[i]==2){
            ans+=t7;
        }else if(v[i]==6)ans+=t3;
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}