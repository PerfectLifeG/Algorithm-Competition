#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=101;
const int mod=1e9+7;
int a[N][N];
int w[N];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    int s=0;
    for(int i=1;i<=n;i++){
	    a[i][i]=1;
        a[i][1]=1;
    }
    for(int i=3;i<=n;i++)
        for(int j=2;j<=i-1;j++)
        a[i][j]=a[i-1][j-1]+a[i-1][j];
    int t=1;
    for(int i=1;i<=n/2;i++){
        w[i]=t;
        w[n-i+1]=t+1;
        t+=2;
    }
    if(n&1)w[n/2+1]=n;
    for(int i=1;i<=n;i++){
        s+=w[i]*a[n][i];
    }
    cout<<s<<endl;
    for(int i=1;i<=n;i++){
        cout<<w[i]<<' ';
    }
    return 0;
}