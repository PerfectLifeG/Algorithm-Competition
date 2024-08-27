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
    int val;
    Node* left;
    Node* right;
};
void solve(){
    int n;cin>>n;
    vector<int>pre;
    vector<int>in;
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        if(a<0)mp[abs(a)]=1;
        pre.emplace_back(abs(a));
        in.emplace_back(abs(a));
    }
    sort(all(in));

    function<Node*(int,int,int)> build=[&](int root,int l,int r)->Node*{
        if(l>r)return NULL;
        int i=l;
        while(i<=r&&in[i]!=pre[root])i++;
        Node* t=new Node();
        t->val=pre[root];
        t->left=build(root+1,l,i-1);
        t->right=build(root+i-l+1,i+1,r);
        return t;
    };

    Node* tr=new Node();
    tr=build(0,0,n-1);

    int flag=1;
    function<int(Node*)> dfs=[&](Node* t)->int{
        if(!flag)return 0;
        int cnt=0;
        if(t->left){
            if(mp[t->val]&&mp[t->left->val]){flag=0;return 0;}
            cnt=dfs(t->left);
        }else{
            cnt=1;
        }
        if(t->right){
            if(mp[t->val]&&mp[t->right->val]){flag=0;return 0;}
            int p=dfs(t->right);
            if(cnt!=p){flag=0;return 0;}
        }else{
            if(cnt!=1){flag=0;return 0;}
        }
        if(!mp[t->val]){
            return cnt+1;
        }
        return cnt;
    };

    if(mp[tr->val])flag=0;
    dfs(tr);
    if(flag)yes;
    else no;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}