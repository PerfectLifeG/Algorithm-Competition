#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=500010;
const int mod=998244353;
int a[N];int p[N];
int book[N];
int nx[N];
void solve()
{
    int n;cin>>n;
    // unordered_map<int,PII>mp;
    unordered_map<int,int>book2;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(book[i])continue;
        unordered_map<int,PII>mp;
        book2[a[i]]=1;
        int cnt=1;
        while(!book[i]){
            book[i]=1;
            if(book2[a[i]]){
                ans=max(cnt-book2[a[i]],ans);
                // cout<<i<<' '<<cnt<<' '<<book2[a[i]]<<' '<<a[i]<<endl;
                book2[a[i]]=cnt;
            }
            if(!mp.count(a[i])){
                mp[a[i]].first=cnt;
                mp[a[i]].second=cnt;
            }else{
                mp[a[i]].first=min(mp[a[i]].first,cnt);
                mp[a[i]].second=max(mp[a[i]].second,cnt);
            }
            // cout<<mp[a[i]].first<<' '<<mp[a[i]].second<<endl;
            i=p[i];
            cnt++;
        }
        // cout<<cnt<<endl;
        for(auto q:mp){
            ans=max(ans,cnt-1-(q.second.second-q.second.first));
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