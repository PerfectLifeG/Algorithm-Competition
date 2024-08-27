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
    for(int i=0;i<n;i++)cin>>a[i];
    
    vector<int>book(n);
    vector<PII>ans;
    unordered_map<int,int>mp;
    for(int i=n-1;i>=1;i--){
        vector<int>p(n,-1);
        for(int j=0;j<n;j++){
            if(book[j])continue;
            // if(i==1)cout<<i<<' '<<a[j]<<' '<<book[j]<<' '<<p[a[j]%i]<<' '<<book[p[a[j]%i]]<<endl;
            int x=(max(p[a[j]%i],j)<<30)|min(p[a[j]%i],j);
            if(p[a[j]%i]!=-1&&!mp.count(x)){
                // book[j]=1;
                // book[p[a[j]%i]]=1;
                mp[x]=1;
                book[min(p[a[j]%i],j)]=1;
                // cout<<p[a[j]%i]<<' '<<j<<endl;
                ans.push_back({p[a[j]%i]+1,j+1});
                break;
            }else {
                // cout<<'!'<<a[j]<<' '<<i<<' '<<(a[j]%i)<<' '<<j<<endl;
                p[a[j]%i]=j;
            }
        }
    }
    yes;
    reverse(all(ans));
    // int t=1;
    for(auto &[i,j]:ans){
        cout<<i<<' '<<j<<endl;
        // cout<<a[i-1]%t<<' '<<a[j-1]%t<<endl;
        // t++;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}