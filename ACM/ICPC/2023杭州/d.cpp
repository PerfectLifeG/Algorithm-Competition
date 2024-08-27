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
int a[N];
int b[N];
void solve(){
    int n;cin>>n;
    n*=2;
    if(n==4){
        cout<<"1 -3 -3 1\n";
    }else if(n==6){
        cout<<"1 -10 6 6 -10 1\n";
    }else if(n%8==0){
        b[1]=a[1],b[n]=a[n];
        a[1]=4,a[n]=6;
        for(int i=1;i<=n;i++)cout<<a[i]<<' ';cout<<endl;
        a[1]=b[1],a[n]=b[n];
    }else if(n%8==2){
        b[1]=a[1],b[n]=a[n];b[n-2]=a[n-2],b[n-1]=a[n-1];
        a[1]=6,a[n]=2;a[n-2]=-1,a[n-1]=2;
        for(int i=1;i<=n;i++)cout<<a[i]<<' ';cout<<endl;
        a[1]=b[1],a[n]=b[n];a[n-2]=b[n-2],a[n-1]=b[n-1];
    }else if(n%8==4){
        b[1]=a[1],b[n]=a[n];
        a[1]=1,a[n]=1;
        for(int i=1;i<=n;i++)cout<<a[i]<<' ';cout<<endl;
        a[1]=b[1],a[n]=b[n];
    }else{
        b[1]=a[1],b[n]=a[n];b[n-2]=a[n-2],b[n-1]=a[n-1];
        a[1]=2,a[n]=-1;a[n-2]=1,a[n-1]=-2;
        for(int i=1;i<=n;i++)cout<<a[i]<<' ';cout<<endl;
        a[1]=b[1],a[n]=b[n];a[n-2]=b[n-2],a[n-1]=b[n-1];
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    for(int i=2;i<N;i+=8){
        a[i]=-3;a[i+1]=2;
        a[i+2]=3;a[i+3]=-2;
        a[i+4]=3;a[i+5]=-2;
        a[i+6]=-3;a[i+7]=2;
    }
    while(_--)solve();
    return 0;
}