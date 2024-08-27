#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<cstdio>
using namespace std;
int book[10];int box[10];int n;
void dfs(int step){
    if(step==n+1){
        int a=box[1]*100+box[2]*10+box[3];
        int b=box[4]*100+box[5]*10+box[6];
        int c=box[7]*100+box[8]*10+box[9];
        if(a+b==c)
        printf("%d+%d=%d\n",a,b,c);
        return;
    }

    for (int i = 1; i <= n; i++)//从小到大
    {
        if(book[i]==0){
        box[step]=i;
        book[i]=1;
        dfs(step+1);
        book[i]=0;
        }
    }
    
}
int main()
{
    n=9;
    dfs(1);
    return 0;
}