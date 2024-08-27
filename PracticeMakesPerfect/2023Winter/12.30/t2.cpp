#include<bits/stdc++.h>
using namespace std;
const int N=1010;
char g[N][N];
int book[N][N];
int main(){
    int n,m;
    cin>>n>>m;
    getchar();
    int op[4]={0,0,n-1,n-1};
    int op2[4]={0,m-1,0,m-1};
    int mx=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%c",&g[i][j]);
            if(g[i][j]=='#'){
                for(int k=0;k<4;k++){
                    if(abs(i-op[k])+abs(j-op[k])>mx){
                        mx=abs(i-op[k])+abs(j-op[k]);
                    }
                }
            }
        }
        getchar();
    }
    cout<<mx<<endl;
    return 0;
}