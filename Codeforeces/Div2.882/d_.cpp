#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    int n,m,q;cin>>n>>m>>q;
    string s;
    cin>>s;
    s=' '+s;
    vector<int>id;id.push_back(-1);
    unordered_map<int,int>mp;//优先级
    set<int>st;
    for(int i=1;i<=n;i++)st.insert(i);
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        for(auto j=st.lower_bound(l);j!=st.end()&&*j<=r;j=st.erase(j)){
            mp[*j]=id.size();
            id.push_back(*j);
        }
    }
    int cnt=count(all(s),'1');
    int tot=id.size()-1;
    int ans=0;
    for(int i=1;i<=min(cnt,tot);i++){
        if(s[id[i]]=='0')ans++;
    }
    while(q--){
        int x;cin>>x;
        if(s[x]=='1'){
            if(cnt<=tot&&s[id[cnt]]=='0')ans--;
            cnt--;
            if(mp[x]!=0&&mp[x]<=cnt)ans++;
            s[x]='0';
        }else{
            if(mp[x]!=0&&mp[x]<=cnt)ans--;
            cnt++;
            s[x]='1';
            if(cnt<=tot&&s[id[cnt]]=='0')ans++;
        }
        cout<<ans<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    // cin>>_;
    while(_--)solve();
    return 0;
}