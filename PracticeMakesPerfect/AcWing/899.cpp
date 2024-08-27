#include<bits/stdc++.h>
using namespace std;
const int N=15,M=1010;
int n,m;
int f[N][N];
char s[M][N];
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        scanf("%s",s[i]+1);
    }

    while(m--){
        char p[N];
        int mx;int cnt=0;
        scanf("%s%d",p+1,mx);
        
        for(int k=0;k<n;k++){
            int len1=strlen(s[k]+1);
            int len2=strlen(p+1);
            for(int i=0;i<len1;i++)f[i][0]=i;
            for(int i=0;i<len2;i++)f[0][i]=i;

            for(int i=1;i<n;i++){
                for(int j=1;j<n;j++){
                    f[i][j]=min(f[i][j-1]+1,f[i-1][j]+1);
                    if(s[k][i]==p[j]){
                        f[i][j]=min(f[i][j],f[i-1][j-1]);
                    }else f[i][j]=min(f[i][j],f[i-1][j-1]+1);
                }
            }
            if(f[n][m]<mx)cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}