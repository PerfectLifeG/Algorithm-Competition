#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=10010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
struct Node{
    int id;
    int area;
    int house;
    int cnt;
    bool operator<(const Node& n)const
    {
        if(area*n.cnt==n.area*cnt)
            return id<n.id;
        return area*n.cnt>n.area*cnt;
    }
};
vector<int>v[N];
int area[N];
int house[N];
int book[N];
int cnt,val1,val2,mn;
void dfs(int t,int fa){
    val1+=house[t],val2+=area[t];mn=min(mn,t);cnt++;
    book[t]=1;
    for(auto j:v[t]){
        if(j==fa||book[j])continue;
        dfs(j,t);
    }
}
void solve(){
    int n;cin>>n;
    vector<int>id(n);
    for(int i=0;i<n;i++){
        cin>>id[i];
        int fa,ma;cin>>fa>>ma;
        if(fa!=-1)v[id[i]].push_back(fa),v[fa].push_back(id[i]);
        if(ma!=-1)v[id[i]].push_back(ma),v[ma].push_back(id[i]);
        int m;cin>>m;
        for(int j=0;j<m;j++){
            int son;cin>>son;
            v[son].push_back(id[i]);
            v[id[i]].push_back(son);
        }
        int a,b;cin>>a>>b;
        house[id[i]]+=a;area[id[i]]+=b;
    }
    vector<Node>ans;
    for(int i=0;i<n;i++){
        if(book[id[i]])continue;
        val2=val1=cnt=0;mn=INF;
        dfs(id[i],id[i]);
        ans.push_back({mn,val2,val1,cnt});
    }
    sort(all(ans));
    printf("%d\n",ans.size());
    for(auto i:ans){
    	printf("%04d %d %.3lf %.3lf\n",i.id,i.cnt,1.0*i.house/i.cnt,1.0*i.area/i.cnt);
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
