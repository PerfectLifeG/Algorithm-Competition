#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
char ans[3*1<<10][3*1<<10];
void solve(){
    int n;cin>>n;
    // string s[0]={};
    // string s[1]=;
    if(n&1)
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            ans[i][j]='*';
        }
    }
    else 
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            ans[i][j]='.';
        }
    }
    int l1=0,l2=0,r1=3,r2=3;
    for(int i=0;i<n;i++){
        for(int j=l1;j<r1;j++){
            for(int k=l2+r2-l2;k<r2+r2-l2;k++){
                ans[j][k]=ans[j-l1][k-(l2+r2-l2)];
                // cout<<j<<' '<<k<<endl;
            }
        }
        // cout<<endl;
        for(int j=l1+r1-l1;j<r1+r1-l1;j++){
            for(int k=l2;k<r2;k++){
                ans[j][k]=ans[j-(l1+r1-l1)][k-l2];
                // cout<<j<<' '<<k;
                // cout<<j-l1+r1-l1<<' '<<k-l2<<endl;
            }
        }
        // cout<<endl;
        // int a,b;
        for(int j=l1+r1-l1;j<r1+r1-l1;j++){
            int k=l2+r2-l2;
            for(;k<r2+r2-l2;k++){
                if(ans[j-(l1+r1-l1)][k-(l2+r2-l2)]=='*')
                ans[j][k]='.';
                else ans[j][k]='*';
                // cout<<j<<' '<<k<<endl;
            }
        }
        r1=r1+r1-l1;
        r2=r2+r2-l2;
        // cout<<r1<<' '<<r2<<endl;
    }
    for(int i=0;i<3*(1<<n);i++){
        for(int j=0;j<3*(1<<n);j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    while(T--){
        solve();
    }
    return 0;
}