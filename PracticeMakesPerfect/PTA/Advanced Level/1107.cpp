#include<bits/stdc++.h>
using namespace std;
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
int root[N];
int siz[N];
int find(int a){
    if(root[a]==a)return a;
    return root[a]=find(root[a]);
}
void merge(int a,int b){
    int ra=find(a),rb=find(b);
    root[rb]=ra;
}
void solve(){
    int n;cin>>n;
    for(int i=1;i<=N;i++)root[i]=i;
    vector<int>v(n+1);
    for(int i=1;i<=n;i++){
        int m;scanf("%d: ",&m);
        int a;cin>>a;
        v[i]=a;
        for(int j=1;j<m;j++){
            int b;cin>>b;
            merge(a,b);
        }
    }
    vector<int>ans;
    for(int i=1;i<=n;i++){
        siz[find(v[i])]++;
    }
    for(int i=1;i<=n;i++){
        if(siz[find(v[i])])ans.push_back(siz[find(v[i])]);
        siz[find(v[i])]=0;
    }
    cout<<ans.size()<<endl;
    sort(all(ans),greater<>());
    cout<<ans[0];
    for(int i=1;i<ans.size();i++){
        cout<<' '<<ans[i];
    }
}
signed main(){
    int _=1;
    while(_--)solve();
    return 0;
}