#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int n,m;cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m));
    int id=0;
    for(int j=0;j<m;j++){
        v[0][j]=id++;
    }
    int i=1;
    int q;
    if(n<m)q=n;
    else q=min(n-1,m-1);
    for(;i<q;i++){
        int id=0;
        for(int j=i;j<m;j++){
            v[i][j]=id++;
        }
        for(int j=0;j<i;j++){
            v[i][j]=id++;
        }
    }
    for(;i<n;i++){
        for(int j=0;j<m;j++){
            v[i][j]=v[0][j];
        }
    }

    // for(int k=(n-1)*b;k<n;k++){
    //     int i=0;int id=0;
    //     for(int j=i;j<m;j++){
    //         v[k][j]=id++;
    //     }
    //     for(int j=0;j<i;j++){
    //         v[k][j]=id++;
    //     }
    // }

    // int ans=0;
    // vector<int>book2(m);
    // for(int i=0;i<m;i++){
    //     vector<int>book(m);
    //     for(int j=0;j<n;j++){
    //         if(v[j][i]<m)book[v[j][i]]=1;
    //     }
    //     for(int j=0;j<m;j++){
    //         // cout<<j<<' '<<book[j]<<endl;
    //         if(book[j]==0){book2[j]=1;break;}
    //     }
    // }
    // int f=-1;
    // for(int i=0;i<m;i++){
    //     // cout<<i<<' '<<book2[i]<<endl;
    //     if(book2[i]==0){f=i;break;}
    // }
    // if(f==-1)f=m;
    if(m==1)cout<<0<<endl;
    else if(n<m)cout<<n+1<<endl;
    else cout<<m<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<v[i][j]<<' ';
        }cout<<endl;
    }

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}