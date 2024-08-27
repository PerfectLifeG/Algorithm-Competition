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
    int n;
    while(cin>>n){
        int cnt=0;
        vector<int>a(n);
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        mp[0]=1;
        for(int i=0;i<n;i++){
            cnt+=a[i]/9-mp[a[i]%9];
            mp[a[i]%9]++;
        }
        if(cnt&1){
            cout<<"A\n";   
        }else cout<<"B\n";
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}