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
vector<int>in;
vector<int>pre;
vector<int>post;
void getpost(int root,int l,int r){
    if(l>r)return;
    int i=l;
    while(i<=r&&in[i]!=pre[root])i++;
    getpost(root+1,l,i-1);
    getpost(root+i-l+1,i+1,r);
    post.push_back(pre[root]);
}
void solve(){
    int n;cin>>n;
    stack<int>st;
    for(int i=0;i<2*n;i++){
        string op;cin>>op;
        if(op=="Push"){
            int x;cin>>x;
            st.push(x);
            pre.push_back(x);
        }else{
            in.push_back(st.top());
            st.pop();
        }
    }
    getpost(0,0,n-1);
    cout<<post[0];
    for(int i=1;i<post.size();i++){
        cout<<' '<<post[i];
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}