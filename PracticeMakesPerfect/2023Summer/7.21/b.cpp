#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int n;
int f[N],vis[N],sg[N];

int g(int x){
    int mex[1010];
    memset(mex,0,sizeof(mex));
    if(sg[x]!=-1)
        return sg[x];
    for(int i=x-1;i>=0;i--)
        mex[g(i)]=1;
    for(int i=1;i<=x/2;i++){
        int ans=0;
        ans^=g(i);
        ans^=g(x-i);
        mex[ans]=1;
    }
    for(int i=0;;i++)
        if(!mex[i])
            return sg[x]=i;
}
//
// 2 3 + 10
// 3 4 + 14
// 4 5 + 18  23
void solve()
{
    freopen("1001.out","w",stdout);
    // int n,k;cin>>k>>n;
    sg[0]=0;
    sg[1]=1;
    // sg[0]=1;
    sg[2]=1;
    // sg[0]=2;
    sg[3]=1;
    sg[4]=1;
    sg[5]=0;
    // sg[0]=0;

//     sg[1][1]=1;
//     sg[1][2]=1;
//     sg[2][1]=1;

// 1 3
// 2 2
// 3 1

    int n=100;
    int k=4;

    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=n;j++){
    //         for(int p=1;p<=i+j;p++){
    //             if(i+j-p-k>0){
    //                 vis[sg[i-j-k][j]]=i;
    //                 // cout<<i<<' '<<i-j-k<<' '<<sg[i-j-k]<<' '<<j<<' '<<sg[j]<<endl;
    //             }
    //         }
    //         for(int p=0;p<=i+j;p++){
    //             if(p>0){
                    
    //                 // cout<<i<<' '<<i-j-k<<' '<<sg[i-j-k]<<' '<<j<<' '<<sg[j]<<endl;
    //             }
    //         }
    //     }
    // }
    for(int i=6;i<=n;i++){
        for(int j=1;j<=i-1;j++){
            if(i-j-k>0){
                vis[sg[i-j-k]^sg[j]]=i;
                // cout<<i<<' '<<i-j-k<<' '<<sg[i-j-k]<<' '<<j<<' '<<sg[j]<<endl;
            }
        }
        for(int j=0;j<=i-1;j++){
            if(vis[j]!=i){
                sg[i]=j;
                // sg[0][i]=j;
                break;
            }
        }
        // for(int j=1;j<=i-1;j++){
        //     if(j>0){
        //         sg[i-j-k][j]=i;
        //         // cout<<i<<' '<<i-j-k<<' '<<sg[i-j-k]<<' '<<j<<' '<<sg[j]<<endl;
        //     }
        // }
    }
    for(int i=0;i<=n;i++){
        // for(int j=0;j<=n;j++)
        cout<<i<<' '<<sg[i]<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    // cin>>_;
    while(_--)solve();
    return 0;
}