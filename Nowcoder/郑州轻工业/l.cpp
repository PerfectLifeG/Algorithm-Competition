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
    vector<int>a(n);
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        int res=0;
        cin>>a[i];
        for(int j=0;j<60;j++){
            if(a[i]>>j&1){
                res+=1ll<<j;
                j++;
                res+=(int)(!(a[i]>>j&1))<<j;
            }
        }
        if(mp.count(res)){cout<<i+1<<' '<<mp[res]<<endl;return;}
        mp[a[i]]=i+1;
    }
    cout<<-1<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}