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
    string a,b;
    int x;
};
void solve()
{
    int n,m,q;cin>>n>>m>>q;
    vector<int>col(m+1);
    vector<int>row(n+1);
    int ans=0;
    Node node[q+1];
    for(int i=0;i<q;i++){
        string a;int x;string b;
        cin>>a>>x>>b;
        node[i].a=a;node[i].b=b;node[i].x=x;
    }
    int r=m,c=n;
    for(int i=q-1;i>=0;i--){
        string a;int x;string b;
        a=node[i].a;b=node[i].b;x=node[i].x;
        if(a=="row"&&b=="on"){
            if(row[x])continue;
            ans+=r;
            row[x]=1;
            c--;
        }
        else if(a=="column"&&b=="on"){
            if(col[x])continue;
            ans+=c;
            col[x]=1;
            r--;
        }
        else if(a=="column"&&b=="off"){
            if(col[x])continue;
            col[x]=1;
            r--;
        }
        else {
            if(row[x])continue;
            row[x]=1;
            c--;
        }
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    // cin>>_;
    while(_--)solve();
    return 0;
}