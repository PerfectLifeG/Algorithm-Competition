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
struct Node{
    int ge,gi;
    int id;
    bool operator<(const Node& n)const{
        if(ge+gi!=n.ge+n.gi){
            return ge+gi>n.ge+n.gi;
        }
        if(ge!=n.ge)return ge>n.ge;
        return id<n.id;
    }
};
void solve(){
    int n,m,k;cin>>n>>m>>k;
    vector<int>quota(m);
    for(int i=0;i<m;i++){
        cin>>quota[i];
    }
    vector<Node>rank;
    vector<int>prefer[n];
    vector<Node>stu(n);
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        for(int j=0;j<k;j++){
            int x;cin>>x;
            prefer[i].push_back(x);
        }
        stu[i]={a,b,i};
        rank.push_back({a,b,i});
    }
    sort(all(rank));
    vector<int>ans[m];
    for(int i=0;i<n;i++){
        int t=rank[i].id;
        for(auto j:prefer[t]){
            if(ans[j].size()<quota[j]){
                ans[j].push_back(t);
                break;
            }else if(stu[ans[j].back()].ge+stu[ans[j].back()].gi==stu[t].ge+stu[t].gi&&stu[ans[j].back()].ge==stu[t].ge){
                ans[j].push_back(t);
                break;
            }
        }
    }

    for(int i=0;i<m;i++){
        sort(all(ans[i]));
        if(ans[i].size())cout<<ans[i][0];
        for(int j=1;j<ans[i].size();j++){
            cout<<' '<<ans[i][j];
        }
        cout<<endl;
    }

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}