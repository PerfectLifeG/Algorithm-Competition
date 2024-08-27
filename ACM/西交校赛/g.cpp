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
    vector<int>v;
    for(int i=1;i<=(n+1)*(n+1)/4;i++)v.push_back(i);
    sort(all(v),greater<>());
    vector<int>ans(n+1);
    unordered_map<int,int>mp;
    vector<int>pre(n+1);
    for(int i=1;i<=n-1;i++){
        for(int j=v.size()-1;j>=0;j--){
            int f=1;
            int sum=0;
            for(int k=i-1;k>=1;k--){
                if(mp.count(v[j]+sum)){
                    v.pop_back();f=0;
                    break;
                }
                sum+=ans[k];
            }
            if(f){
                ans[i]=v[j];
                int sum=v[j];
                for(int k=i;k>=1;k--){
                    mp[sum]=1;
                    sum+=ans[k-1];
                }
                v.pop_back();
                break;
            }
        }
        pre[i]=pre[i-1]+ans[i];
    }
    cout<<n-1<<endl;
    for(int i=1;i<=n-1;i++)cout<<i<<' '<<i+1<<' '<<ans[i]<<endl;

    // set<int>st;
    // for(int i=1;i<=n-1;i++){
    //     for(int j=i+1;j<=n-1;j++){
    //         if(st.count(pre[j]-pre[i-1])){
    //             cout<<"NO\n";
    //             return;
    //         }
    //         st.insert(pre[j]-pre[i-1]);
    //     }
    // }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}