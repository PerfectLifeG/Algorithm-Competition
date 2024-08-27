#include<iostream>
using namespace std;
const int N=20;
int w[N];
int group[N][N];
int book[N];
int n,m;
int ans=N;
bool check(int g[],int mcnt,int t){
    int s=0;
    for(int i=0;i<mcnt;i++){
        s+=w[g[i]];
    }
    if(s+w[t]<=m)return true;
    else return false;
}
void dfs(int gcnt,int mcnt,int s,int start){
    if(gcnt+1>=ans)return;
    if(s==n){
        ans=gcnt+1;
        return;
    }
    int flag=1;
    for(int i=start;i<n;i++){
        if(book[i]==0&&check(group[gcnt],mcnt,i)){
            book[i]=1;
            group[gcnt][mcnt]=i;
            dfs(gcnt,mcnt+1,s+1,i+1);
            book[i]=0;
            flag=0;
            if(mcnt==0)return;
        }
    }
    if(flag)dfs(gcnt+1,0,s,0);
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>w[i];
    dfs(0,0,0,0);
    cout<<ans;
    return 0;
}