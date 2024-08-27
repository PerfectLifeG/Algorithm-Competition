#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int main(){
    int t;cin>>t;
    while(t--){
        int n,k;scanf("%d%d",&n,&k);
        int len=k;
        int mx=n,mn=1;
        while(mx>=mn){
            for(int i=1;i<=len-1&&mx>=mn;i++){
                printf("%d ",mx--);
            }
            if(mx<mn)break;
            printf("%d ",mn++);
        }
        puts("");
    }
    return 0;
}