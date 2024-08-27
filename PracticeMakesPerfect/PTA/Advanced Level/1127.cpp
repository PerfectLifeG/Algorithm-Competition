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
const int N=100;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
int in[N];
int post[N];
struct Node{
    int val;
    Node* left;
    Node* right;
};
Node* build(int root,int l,int r){
    if(l>r)return NULL;
    // cout<<root<<' '<<l<<' '<<r<<endl;
    int i=l;
    while(i<=r&&post[root]!=in[i])i++;
    Node* t=new Node();
    t->val=post[root];
    t->left=build(root-r+i-1,l,i-1);
    t->right=build(root-1,i+1,r);
    return t;
}
void solve(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    for(int i=0;i<n;i++){
        cin>>post[i];
    }
    Node* t=new Node();
    t=build(n-1,0,n-1);

    vector<int>ans;
    queue<Node*>q;
    q.push(t);
    int flag=0;
    while(q.size()){
        int n=q.size();
        vector<int>tmp;
        for(int i=0;i<n;i++){
            auto t=q.front();
            tmp.push_back(t->val);
            if(t->left){
                q.push(t->left);
            }
            if(t->right){
                q.push(t->right);
            }
            q.pop();
        }
        if(flag){
            ans.insert(ans.end(),tmp.begin(),tmp.end());
        }else ans.insert(ans.end(),tmp.rbegin(),tmp.rend());
        flag^=1;
    }
    cout<<ans[0];
    for(int i=1;i<ans.size();i++)cout<<' '<<ans[i];
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}