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
const int INF=0x3f3f3f3f;
struct Node{
    int score;
    string num;
    bool operator<(const Node &n)const{
        if(score!=n.score){
            return score>n.score;
        }else return num<n.num;
    }
};
void solve(){
    int n;cin>>n;
    vector<Node>ans;
    unordered_map<string,PII>mp;
    for(int i=1;i<=n;i++){
        int m;cin>>m;
        vector<Node>v;
        for(int j=1;j<=m;j++){
            string a;int b;cin>>a>>b;
            v.push_back({b,a});
            ans.push_back({b,a});
        }
        sort(all(v));
        int rank=1;
        mp[v[0].num]={i,rank};
        for(int j=1;j<v.size();j++){
            if(v[j].score!=v[j-1].score)rank=j+1;
            mp[v[j].num]={i,rank};
        }
    }
    sort(all(ans));
    cout<<ans.size()<<endl;
    int rank=1;
    cout<<ans[0].num;
    printf(" %lld %lld %lld\n",rank,mp[ans[0].num].first,mp[ans[0].num].second);
    for(int i=1;i<ans.size();i++){
        if(ans[i].score!=ans[i-1].score)rank=i+1;
        cout<<ans[i].num;
        printf(" %lld %lld %lld\n",rank,mp[ans[i].num].first,mp[ans[i].num].second);
    }

}
signed main(){
    // ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}