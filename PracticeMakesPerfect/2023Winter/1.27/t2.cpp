#include<bits/stdc++.h>
using namespace std;
const int N=10010;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;sc(T);
    while(T--){
        int n,s,r;
        scanf("%d%d%d",&n,&s,&r);
        int mx=s-r;
        int av=r/(n-1)+(bool)(r%(n-1));
        int bu=av*(n-1)-r;
        int t=av;
        int cnt=0;
        while(bu--){
            t--;
            if(t==1){printf("%d ",t);t=av;cnt++;}
            else if(bu==0){printf("%d ",t);t=av;cnt++;}
        }
        for(int i=0;i<n-cnt-1;i++){
            printf("%d ",av);
        }
        printf("%d\n",mx);
    }
    return 0;
}