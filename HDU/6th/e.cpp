#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=310;
const int mod=998244353;
const int INF=0x3f3f3f3f;
vector<int>mp;
unordered_map<int,int>book;
void solve()
{
    int n;cin>>n;
    vector<int>a(N);
    vector<int>s(N);
    vector<vector<int>>v(N,vector<int>(N*N));
    vector<vector<int>>v2(N,vector<int>(N*N));
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    int all=0;
    for(int l=1;l<=n;l++){
        for(int r=l;r<=n;r++){
            if(book.count(s[r]-s[l-1]))all++;
            for(int i=l;i<=r;i++){
                v[i][s[r]-s[l-1]]++;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int t=all;
        for(auto q:mp){
            if(q>n*n)break;
            t-=v[i][q];
        }
        for(int j=1;j<=300;j++){
            int cnt=0;
            int tt=t;
            for(auto k:mp){
                if(k>n*n)break;
                if(k-j+a[i]>=0)tt+=v[i][k-j+a[i]];
            }
            ans=max(ans,tt);
        }
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    for(int i=1;i<=300;i++){
        mp.push_back(i*i);
        book[i*i]=1;
    }
    while(_--)solve();
    return 0;
}