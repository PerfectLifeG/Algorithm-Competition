#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<string>
#include<cmath>
using namespace std;
int food[50003];int r[50003];
int find(int a){  //只能用递归   find有两个作用：1.返回根节点 2.压缩路径确定与根结点的关系
    if(a==food[a]) return a;
    int t=food[a];
    food[a]=find(food[a]);
    r[a]=(r[a]+r[t])%3;
    return food[a];
}

void merge(int a,int b){
    a=find(food[a]);b=find(food[b]);
    food[a]=b;
}

int main()
{   
    int n,k;
    cin>>n>>k;
    int cnt=0;
    for (int i = 1; i <= n; i++){food[i]=i;r[i]=0;}
    for (int i = 0; i < k; i++)
    {
        int flag,a,b;
        cin>>flag>>a>>b;
        if(flag==2&&a==b){cnt++;continue;}
        if(a>n||b>n){cnt++;continue;}
        int ra=find(a);int rb=find(b);
        if(ra==rb){
            if((flag-1)!=((r[b]-r[a]+3)%3)){cnt++;continue;}//枚举公式
        }
        else {
            merge(a,b);
            if(flag==2)
            r[ra]=(-r[a]+r[b]+flag+3)%3;//枚举公式
            else if(flag==1)
            r[ra]=(-r[a]+r[b]+flag-1+3)%3;//枚举公式
        }
    }
    cout<<cnt;
    return 0;
}