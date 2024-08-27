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
struct queuee
{
    int x;
    int y;
}q[5000];
int maze[50][50];
int book[50][50];
int xx,yy;int m;
int head=1;int tail=2;int flag=0;
int way[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int main()
{   
    int n;cin>>n;
    for (int o = 1; o <= n; o++)
    {
        cin>>m;
        for (int j = 1; j <= m; j++)
        {
            for (int k = 1; k <= m; k++)
            {
                cin>>maze[j][k];
            }
        }
        xx=m;yy=m;
        book[1][1]=1;//


    q[1].x=1;
    q[1].y=1;
    int tx,ty;
    while(head<tail){ //一直找直到找不到
        for (int i = 0; i < 4; i++)
        {
            tx=q[head].x+way[i][0];ty=q[head].y+way[i][1];
            
            if(tx<1||ty<1||tx>m||ty>m||maze[tx][ty]==1)continue;
            if(book[tx][ty]==0){
                q[tail].x=tx;
                q[tail].y=ty;
                tail++;
                book[tx][ty]=1;
            }
            if(tx==xx&&ty==yy){
                flag=1;
                break;
            }
        }
        if(flag==1)break;
        
        head++;
    }


    if(flag==1)
        printf("LCyyds\n");
        else printf("QwQ\n");
    flag=0;
    head=1;tail=2;
    // for (int j = 1; j <= m; j++)
        // {
        //     for (int k = 1; k <= m; k++)

        //     {
        //         book[j][k]=0;
        //     }
        // }

    }
    
    return 0;
}