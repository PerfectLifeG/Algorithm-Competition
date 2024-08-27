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
const int N=1100;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
unordered_map<string,int>mp;
unordered_map<int,string>mp2;
int idx;
void solve(){
    int n,k;cin>>n>>k;
    vector<int>v(n);
    string s;cin>>s;
    mp2[idx]=s;mp[s]=idx++;
    vector<vector<int>>g(n,vector<int>(n,INF));
    for(int i=0;i<n-1;i++){
        string s;cin>>s;
        int a;cin>>a;
        mp[s]=idx;mp2[idx]=s;
        v[idx++]=a;
    }
    for(int i=0;i<k;i++){
        string a,b;cin>>a>>b;
        int ia=mp[a],ib=mp[b];
        int x;cin>>x;
        g[ia][ib]=x;
        g[ib][ia]=x;
    }
    int st=mp[s],ed=mp["ROM"];
    
    vector<int>d(n,INF);d[st]=0;
    vector<int>book(n);
    auto Dijkstra=[&](){
        for(int k=0;k<n;k++){
            int t=0,mn=INF;
            for(int i=0;i<n;i++){
                if(!book[i]&&mn>=d[i]){
                    mn=d[i];
                    t=i;
                }
            }
            book[t]=1;
            for(int j=0;j<n;j++){
                if(d[j]>g[t][j]+d[t]){
                    d[j]=g[t][j]+d[t];
                }
            }
        }
    };

    Dijkstra();
    // for(int i=0;i<n;i++)cout<<d[i]<<' ';cout<<endl;
    // return;

    int cnt=0;int sum=0;
    vector<int>ans;
    vector<int>tmp;
    function<void(int,int,int)> dfs=[&](int t,int now,int heal){
        if(now>d[t])return;
        if(t==ed){
            cnt++;
            if(heal>sum||heal==sum&&heal*(ans.size()-1)>sum*(tmp.size()-1)){
                sum=heal;
                ans=tmp;
            }
            return;
        }
        for(int i=0;i<n;i++){
            tmp.push_back(i);
            dfs(i,now+g[t][i],heal+v[i]);
            tmp.pop_back();
        }
    };

    dfs(st,0,v[st]);
    cout<<cnt<<' '<<d[ed]<<' '<<sum<<' '<<sum/ans.size()<<endl;
    cout<<s;
    for(int i=0;i<ans.size();i++){
        cout<<"->"<<mp2[ans[i]];
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}