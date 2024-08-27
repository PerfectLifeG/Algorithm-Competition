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
const int N=1100;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int post[N];
int pre[N];
int n;
struct Node{
    int val;
    Node* left;
    Node* right;
};
int flag=0;
int flag2=0;
Node* build1(int l,int r){
    if(l>r)return NULL;
    int i=l+1;
    while(i<=r&&pre[i]<pre[l])i++;
    if(!flag)for(int j=i;j<=r;j++){
        if(pre[j]<pre[l]){
            flag=1;
            break;
        }
    }
    Node* t=new Node();
    t->val=pre[l];
    t->left=build1(l+1,i-1);
    t->right=build1(i,r);
    return t;
}
Node* build2(int l,int r){
    if(l>r)return NULL;
    int i=l+1;
    while(i<=r&&pre[i]>=pre[l])i++;
    if(!flag2)for(int j=i;j<=r;j++){
        if(pre[j]>=pre[l]){
            flag2=1;
            break;
        }
    }
    Node* t=new Node();
    t->val=pre[l];
    t->left=build2(l+1,i-1);
    t->right=build2(i,r);
    return t;
}
int first=1;
void check(Node* t){
    if(t->left)check(t->left);
    if(t->right)check(t->right);
    if(first){cout<<t->val;first=0;}
    else cout<<' '<<t->val;
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>pre[i];
    Node* t=build1(0,n-1);
    if(flag){
        t=build2(0,n-1);
    }
    if(flag2){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    check(t);
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}