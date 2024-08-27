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
unordered_map<int,int>mp;
void solve(){
    int a,b,c;cin>>a>>b>>c;
    int sum=0;
    if(a==150)sum+=1;
    if(a==200)sum+=2;
    if(b>32&&b<=40)sum+=1;
    if(b==45)sum+=2;
    if(c>32&&c<=40)sum+=1;
    if(c==45)sum+=2;
    cout<<sum<<endl;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    mp[100]=0;mp[150]=1;mp[200]=2;
    mp[29]=0;mp[30]=0;mp[31]=0;mp[32]=0;

    while(_--)solve();
    return 0;
}