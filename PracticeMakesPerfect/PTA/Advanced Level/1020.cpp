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
const int N=50;
const int mod=998244353;
const int INF=0x3f3f3f3f;
struct Node{
    int val;
    Node* left;
    Node* right;
}tr[N];
int post[N];
int in[N];
Node* build(int root,int l,int r){
    if(l>r)return NULL;
    int i=l;
    while(i<=r&&post[root]!=in[i])i++;
    Node* t=new Node();
    t->val=post[root];
    t->right=build(root-1,i+1,r);
    t->left=build(root-r+i-1,l,i-1);
    return t;
}
vector<int>ans;
void layer(Node* t){
    queue<Node*>q;
    q.push(t);
    while(q.size()){
        auto t=q.front();
        ans.push_back(t->val);
        q.pop();
        if(t->left){
            q.push(t->left);
        }
        if(t->right){
            q.push(t->right);
        }
    }
}
void solve(){
    int n;cin>>n;
    for(int i=0;i<n;i++)cin>>post[i];
    for(int i=0;i<n;i++)cin>>in[i];
    Node* root=new Node();
    root=build(n-1,0,n-1);
    layer(root);
    cout<<ans[0];
    for(int i=1;i<ans.size();i++)cout<<' '<<ans[i];
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}