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
    vector<int>a(n+1);
    int cnt=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i])cnt++;
    }
    if(cnt&1){cout<<-1<<endl;return;}

    vector<PII>ans;
    for(int i=1;i<=n;i++){
        if(a[i]*a[i+1]==1){
            ans.push_back({i,i+1});
            i++;
        }else if(a[i]*a[i+1]==-1){
            ans.push_back({i,i});
            ans.push_back({i+1,i+1});
            i++;
        }else if(a[i]==0){
            ans.push_back({i,i});
        }else{
            ans.push_back({i,i});
            int now=a[i];
            int l=i;
            i++;
            while(a[i]==0)i++;
            if(a[i]==now){
                if(i-2>=l+1)ans.push_back({l+1,i-2});
                ans.push_back({i-1,i});
            }else{
                ans.push_back({l+1,i-1});
                ans.push_back({i,i});
            }
        }
    }

    cout<<ans.size()<<endl;
    for(auto &[i,j]:ans){
        cout<<i<<' '<<j<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}