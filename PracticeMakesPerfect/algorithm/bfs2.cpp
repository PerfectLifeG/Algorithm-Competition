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
    int s;
}q[2500];
int book[50][50];
char mp[50][50]{
    {'#','#','#','#','#','#','#','#','#','#','#','#','#',},//0
    {'#','G','G','.','G','G','G','#','G','G','G','.','#',},//1
    {'#','#','#','.','#','G','#','G','#','G','#','G','#',},//2
    {'#','.','.','.','.','.','.','.','#','.','.','G','#',},//3
    {'#','G','#','.','#','#','#','.','#','G','#','G','#',},//4
    {'#','G','G','.','G','G','G','.','#','.','G','G','#',},//5
    {'#','G','#','.','#','G','#','.','#','.','#','.','#',},//6
    {'#','#','G','.','.','.','G','.','.','.','.','.','#',},//7
    {'#','G','#','.','#','G','#','#','#','.','#','G','#',},//8
    {'#','.','.','.','G','#','G','G','G','.','G','G','#',},//9
    {'#','G','#','.','#','G','#','G','#','.','#','G','#',},//10
    {'#','G','G','.','G','G','G','#','G','.','G','G','#',},//11
    {'#','#','#','#','#','#','#','#','#','#','#','#','#',},//12
};  //0   1   2   3   4   5   6   7   8   9   10  11  12
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int head=1;int tail=2;int n=13,m=13;int s,flag;

void f(int tx,int ty,int i){
    tx+=dir[i][0];ty+=dir[i][1];
    while(mp[tx][ty]!='#'){
        if(mp[tx][ty]=='G')
        q[tail].s++;
        tx+=dir[i][0];ty+=dir[i][1];
    }
    if(s<q[tail].s) {s=q[tail].s;flag=tail;}
}

void bfs(){
    int tx,ty;
    tx=q[head].x;ty=q[head].y;
    // if(mp[tx][ty]=='.'){
    //     book[tx][ty]=1;
    //     for (int j = 0; j < 4; j++)
    //     {
    //         f(tx,ty,j);
    //     }
    // }else{while(mp[tx][ty]!='.')
    //         {
    //             tx+=dir[1][0];ty+=dir[1][1];
    //             q[head].x=tx;
    //             q[head].y=ty;
    //         }
    //     }
    while (head<tail)
    {
        
        for (int i = 0; i < 4; i++)
        {
            //tx+=dir[i][0];ty+=dir[i][1];//错误  惨痛
            tx=q[head].x+dir[i][0];ty=q[head].y+dir[i][1];
            if(tx<1||ty<1||tx>n-1||ty>m-1||mp[tx][ty]=='#'||mp[tx][ty]=='G')continue;//n-1 m-1
            if(book[tx][ty]==0){
                q[tail].x=tx;q[tail].y=ty;
                
                //if(book[tx][ty]==1||mp[tx][ty]=='#'||mp[tx][ty]=='G')continue;
                book[tx][ty]=1;
                
                for (int j = 0; j < 4; j++)
                {
                    f(tx,ty,j);
                }
                tail++;
            }
        }
        head++;
    }
    
    

    
}
int main()
{
    q[head].x=3;
    q[head].y=3;
    q[head].s=0;
    bfs();
    printf("%d %d\n",q[flag].x,q[flag].y);
    printf("%d",s);
    return 0;
}