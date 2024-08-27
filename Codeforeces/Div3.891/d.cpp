#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
struct Node{
    int v;
    int id;
    bool operator<(const Node &n)const
    {
        return v<n.v;
    }
};
void solve()
{
    int n;cin>>n;
    vector<int>a(n+1),b(n+1);
    Node c[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        c[i].v=a[i]-b[i];
        c[i].id=i;
    }
    sort(c+1,c+1+n);
    vector<int>ans;
    for(int i=n;i>=1;i--){
        if(c[i].v==c[n].v){
            ans.push_back(c[i].id);
        }
    }
    cout<<ans.size()<<endl;
    sort(ans.begin(),ans.end());
    for(auto i:ans)cout<<i<<' ';
    cout<<endl;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}