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
vector<int>pre;
vector<int>in;
vector<int>post;
void get_post(int root,int l,int r){
    if(l>r)return;
    int i=l;
    while(i<=r&&pre[root]!=in[i])i++;
    get_post(root+1,l,i-1);
    get_post(root+i-l+1,i+1,r);
    post.push_back(pre[root]);
}
void solve(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        pre.push_back(a);
    }
    for(int i=0;i<n;i++){
        int a;cin>>a;
        in.push_back(a);
    }
    get_post(0,0,n-1);
    cout<<post[0];
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}