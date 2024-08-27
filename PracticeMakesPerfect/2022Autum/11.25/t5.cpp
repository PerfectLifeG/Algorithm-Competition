#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
int down[N],w[N],cnt[N];
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int op,x;
        scanf("%d%d",&op,&x);
        if(op==1)down[x]++;
        else if(op==2){
            down[x]--;
            down[1]++;
        }
        else if(op==3){
            while(x){
                w[x]++;
                x/=2;
            }
        }
        else {
            while(x){
                w[x]--;
                x/=2;
            }
            down[1]++;
        }
    }
    for(int j=1;j<=n;j++){
        down[j]+=down[j/2];
        w[j]+=down[j];
        cnt[w[j]]++;
    }
    for(int j=0;j<=m;j++){
        printf("%d ",cnt[j]);
    }
    return 0;
}