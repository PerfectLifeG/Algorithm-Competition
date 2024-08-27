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
int root[N];
int find(int a){
    if(root[a]==a)return a;
    return root[a]=find(root[a]);
}
void merge(int a,int b){
    root[find(a)]=root[find(b)];
}
void solve()
{
    int n,m,q;cin>>n>>m>>q;
    for(int i=1;i<=n+1;i++)root[i]=i;
    string s;
    cin>>s;
    s=' '+s;
    vector<int>id;id.push_back(-1);
    unordered_map<int,int>mp;//优先级
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        for(int j=find(l);j<=r;j=find(j)){
            mp[j]=id.size();
            id.push_back(j);
            merge(j,j+1);
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