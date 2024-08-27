#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int f[N][N];
int a[N];
int n,m;
void dfs(int s,int cnt,int used){
    if(s>n)return;
    if(used>=m)return;
    for(int i=0;i<2;i++){
        a[s]=i;if(i==1){cnt++;used++;}
        if(s>2){
            if(cnt>=2)
            f[s][used]++;
            if(a[s-2]==1)cnt--;
        }
        dfs(s+1,cnt,used);
        if(a[s-2]==1)cnt++;
        if(i==1)used--;
    }
}
int main(){
    cin>>n>>m;
    dfs(1,0,0);
    cout<<f[n][m];
    return 0;
}