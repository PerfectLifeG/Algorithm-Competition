#include<stdio.h>
const int N=105;
char ans[105][105];
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
int main(){
    int T;sc(T);
    while(T--){
        int n;sc(n);getchar();
        int book[105]={};
        gets(ans[0]);
        book[ans[0][0]-'0']++;
        char c='_';
        int idx;
        for(int i=1;i<n-1;i++){
            gets(ans[i]);
            if(ans[i][0]!=ans[i-1][0])idx=i;
            if(c!='_')continue;
            book[ans[i][0]-'0']++;
            if(book[ans[i][0]-'0']>1){
                c=ans[i][0];
            }
        }
        printf("%c ",c);
        if(ans[idx][0]!=c)printf("%s\n",ans[idx]);
        else printf("%s\n",ans[idx-1]);
    }
    return 0;
}