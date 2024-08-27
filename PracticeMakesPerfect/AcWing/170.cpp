#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n;
int path[N];
int dfs(int t,int depth){//t是当前层数，depth是最大层数

    if(t>depth)return 0;
    if(path[t-1]==n)return 1;
    bool book[N]={0};//排除等效冗余
    for(int i=t-1;i>=0;i--){//枚举第t个数，第t个数=前面两个数相加,第t个数要从大到小枚举所以i和j是递减
        for(int j=i;j>=0;j--){//枚举一个组合数
            int s=path[i]+path[j];
            if(s>n||s<=path[t-1]||book[s])continue;
            book[s]=1;
            path[t]=s;
            if(dfs(t+1,depth))return 1;
        }
    }
    return 0;
}
int main(){
    path[0]=1;
    while(cin>>n,n){
        int depth=1;
        while(!dfs(1,depth))depth++;
        for(int i=0;i<depth;i++){
            cout<<path[i]<<' ';
        }
        cout<<endl;
    }
    return 0;
}