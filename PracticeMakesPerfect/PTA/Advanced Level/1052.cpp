#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
#define x first
#define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int n,m;cin>>n>>m;
    unordered_map<int,PII>mp;
    for(int i=0;i<n;i++){
        int a,b,c;cin>>a>>b>>c;
        mp[a]={b,c};
    }
    vector<PII>ans;
    while(m!=-1){
        ans.push_back({mp[m].x,m});
        m=mp[m].y;
    }
    sort(all(ans));
    cout<<ans.size()<<' ';
    if(!ans.size())cout<<-1<<endl;
    else printf("%05d\n",ans[0].y);
    for(int i=0;i<ans.size();i++){
        if(i+1<ans.size())printf("%05d %d %05d\n",ans[i].y,ans[i].x,ans[i+1].y);
        else printf("%05d %d -1\n",ans[i].y,ans[i].x);
    }
}
signed main(){
    int _=1;
    while(_--)solve();
    return 0;
}