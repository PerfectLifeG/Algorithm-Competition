#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define lowbit(x) x&-x
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int tr[N];
int n;
void add(int t,int x){
    for(int i=t;i<=n;i+=lowbit(i)){
        tr[i]+=x;
    }
}
int query(int t){
    int r=0;
    for(int i=t;i;i-=lowbit(i)){
        r+=tr[i];
    }
    return r;
}
void solve()
{
    int m,q;cin>>n>>m>>q;
    string s;
    cin>>s;
    s=' '+s;
    unordered_map<int,int>mp;//优先级
    int idx=1;
    set<int>st;
    for(int i=1;i<=n;i++)st.insert(i);
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        for(auto j=st.lower_bound(l);j!=st.end()&&*j<=r;j=st.erase(j)){
            if(s[*j]=='1')add(idx,1);
            mp[*j]=idx++;
        }
    }
    int tot=mp.size();
    int cnt=count(all(s),'1');
    while(q--){
        int x;cin>>x;
        if(mp[x]){
            if(s[x]=='1'){
                cnt--;
                add(mp[x],-1);
            }else{
                cnt++;
                add(mp[x],1);
            }
        }else{
            if(s[x]=='1'){
                cnt--;
            }else{
                cnt++;
            }
        }
        s[x]^=1;
        if(cnt>=tot)cout<<tot-query(tot)<<endl;
        else cout<<cnt-query(cnt)<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    // cin>>_;
    while(_--)solve();
    return 0;
}