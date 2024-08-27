#include<bits/stdc++.h>
using namespace std;
#define int long long
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
vector<int>v;
int getroot(int l,int r){
    if(l>r)return -1;
    int cnt=0;
    int t=2,sum=1;
    int n=r-l+1;
    while(sum+t<=n){
        cnt++;
        sum+=t;
        t*=2;
    }
    int left=min(n-sum,1ll<<cnt);
    int root=sum/2+left+l;
    return root;
}
int first=1;
void level(int l,int r){
    queue<PII>q;
    q.push({l,r});
    while(q.size()){
        auto t=q.front();
        q.pop();
        int root=getroot(t.x,t.y);
        if(root!=-1){
            if(first){cout<<v[root];first=0;}
            else cout<<' '<<v[root];
        }
        if(t.x<=root-1){
            q.push({t.x,root-1});
        }
        if(root+1<=t.y){
            q.push({root+1,t.y});
        }
    }
}
void solve(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        v.push_back(a);
    }
    sort(all(v));
    level(0,n-1);
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}