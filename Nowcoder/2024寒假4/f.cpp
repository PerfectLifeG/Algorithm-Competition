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
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    
    vector<int>dp(n+1);
    for(int i=1;i<=n;i++){

        vector<int>mx1(7,-INF),mn1(7,INF);
        mx1[1]=mn1[1]=a[i];

        for(int j=i+1;j<=n;j++){
            vector<int>mx=mx1,mn=mn1;

            mx[1]=max(a[j],mx[1]);
            mn[1]=min(a[j],mn[1]);

            if(mx1[1]!=-INF)mx[2]=max(mx1[1]-a[j],mx[2]);
            if(mn1[1]!=INF)mn[2]=min(mn1[1]-a[j],mn[2]);

            if(mx1[2]!=-INF)mx[3]=max(mx1[2]*a[j],mx[3]);
            if(mn1[2]!=INF)mx[3]=max(mn1[2]*a[j],mx[3]);
            if(mx1[2]!=-INF)mn[3]=min(mx1[2]*a[j],mn[3]);
            if(mn1[2]!=INF)mn[3]=min(mn1[2]*a[j],mn[3]);
            
            if(mx1[3]!=-INF)mx[4]=max(mx1[3]-a[j],mx[4]);
            if(mn1[3]!=INF)mn[4]=min(mn1[3]-a[j],mn[4]);

            if(mx1[4]!=-INF)mx[5]=max(mx1[4]*a[j],mx[5]);
            if(mn1[4]!=INF)mx[5]=max(mn1[4]*a[j],mx[5]);
            if(mx1[4]!=-INF)mn[5]=min(mx1[4]*a[j],mn[5]);
            if(mn1[4]!=INF)mn[5]=min(mn1[4]*a[j],mn[5]);
            
            if(mx1[5]!=-INF)mx[6]=max(mx1[5]-a[j],mx[6]);
            if(mn1[5]!=INF)mn[6]=min(mn1[5]-a[j],mn[6]);
            
            dp[j]=max(dp[i-1]+mx[6],dp[j]);
            
            mx1=mx;
            mn1=mn;
        }

    }

    cout<<dp[n]<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}