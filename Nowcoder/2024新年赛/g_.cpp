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
const int N=1000010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int root[N];
int find(int a){
    if(a==root[a])return a;
    return root[a]=find(root[a]);
}
void merge(int a,int b){
    int ra=find(a),rb=find(b);
    if(ra>rb)swap(ra,rb);
    root[ra]=rb;
}
void solve(){
    int n,m;cin>>n>>m;
    vector<int>v(n+1);
    for(int i=1;i<=n;i++){
        int a;cin>>a;
        v[i]=a;
        root[i]=i;
    }
    while(m--){
        int op;cin>>op;
        if(op==1){
            int a,b;cin>>a>>b;
            if(v[a]<=b){
                v[a]=0;
                root[a]=find(a+1);
            }else v[a]-=b;
        }else{
            int a;cin>>a;
            cout<<find(a)<<endl;
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}