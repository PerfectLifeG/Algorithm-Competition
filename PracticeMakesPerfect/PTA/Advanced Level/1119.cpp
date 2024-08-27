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
void solve(){
    int n;cin>>n;
    vector<int>pre(n);
    vector<int>post(n);
    for(int i=0;i<n;i++){
        cin>>pre[i];
    }
    for(int i=0;i<n;i++){
        cin>>post[i];
    }

    int flag=1;
    vector<int>ans;
    function<void(int,int,int,int)> getin=[&](int l1,int r1,int l2,int r2){
        if(l1>r1)return;
        if(l2>r2)return;
        if(pre[l1+1]==post[r2-1])flag=0;
        int i=l1+1;
        while(i<=r1&&pre[i]!=post[r2-1])i++;
        getin(l1+1,i-1,l2,l2+i-l1-2);
        ans.push_back(pre[l1]);
        getin(i,r1,l2+i-l1-1,r2-1);
    };
    getin(0,n-1,0,n-1);
    if(flag)yes;
    else no;
    cout<<ans[0];
    for(int i=1;i<ans.size();i++)cout<<' '<<ans[i];
    cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}