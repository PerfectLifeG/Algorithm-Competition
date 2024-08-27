#include<bits\stdc++.h>
using namespace std;
struct queuee
{
    int x;
    int y;
    int f;
    int step;
}q[2505];
int maze[50][50]={
    {1,1,1,1,1},
    {1,0,0,1,0},
    {1,0,0,0,0},
    {1,0,0,1,0},
    {1,0,1,0,0},
    {1,0,0,0,1}
};
int book[50][50];
int xx=4,yy=3;int n=5,m=4;
int head=1;int tail=2;
int way[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
void bfs(){
    int tx,ty;
    
    while(head<tail){ //一直找直到找不到
        for (int i = 0; i < 4; i++)
        {
            tx=q[head].x+way[i][0];ty=q[head].y+way[i][1];
            
            if(tx<1||ty<1||tx>n||ty>m||maze[tx][ty]==1)continue;
            if(book[tx][ty]==0){
                q[tail].x=tx;
                q[tail].y=ty;
                q[tail].step=q[head].step+1;
                q[tail].f=head;
                tail++;
                book[tx][ty]==1;
            }
            if(tx==xx&&ty==yy){
                return;
            }
        }
        head++;
    }
}
int main()
{   
    q[1].x=1;
    q[1].y=1;
    q[1].f=1;
    q[1].step=0;
    book[1][1]=1;
    bfs();
    int h;
    printf("%d\n",q[--tail].step);
    while (tail!=1)
    {
        h=q[tail].f;
        tail=h;
        printf("%d %d\n",q[h].x,q[h].y);
    }
    return 0;
}