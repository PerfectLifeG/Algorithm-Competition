#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int mod=998244353;
const int INF=0x3f3f3f3f;
const int N=1e5+1;
const int M=1e6+1;
int nx[N];
char p[N],s[M];
int n,m;
void kmp(char p[],char s[],int n,int m){
    for(int i=2,j=0;i<=n;i++){
        while(j && p[i]!=p[j+1])j=nx[j];
        if(p[i]==p[j+1])j++;
        nx[i]=j;
    }
    for(int i=1,j=0;i<=m;i++){
        while(j && s[i]!=p[j+1])j=nx[j];
        if(s[i]==p[j+1])j++;
        if(j==n){
            yes;
            return;
        }
    }
    no;
}
void solve()
{
    int n,m;
    scanf("%d%d",&n,&m);
    char temp[n+1][2*m+1];
    for(int i=1;i<=n;i++){
        cin>>temp[i];
        for(int j=m;j<2*m+1;j++){
            temp[i][j]=temp[i][j-m];
        }
        // cout<<endl;
    }
    int q;cin>>q;
    while(q--){
            int a,b;cin>>a>>b;
            kmp(temp[a],temp[b],m,2*m);
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}