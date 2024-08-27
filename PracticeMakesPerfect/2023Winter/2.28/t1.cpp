#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int M=1e6+10;
int nx[N];
char p[N],s[M]={'0','F','B','F','F','B','F','F','B','F','B','F','F','B','F','F','B','F','B','F','F','B','F','F','B','F','B','F','F','B','F','F','B'};
int n,m;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
int flag;
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
            flag=1;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        cin>>p+1;flag=0;
        kmp(p,s,n,32);
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}