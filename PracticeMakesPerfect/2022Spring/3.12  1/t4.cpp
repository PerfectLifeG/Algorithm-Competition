#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<string>
#include<cmath>
using namespace std;
typedef struct Tree* tree;
struct Tree
{
    int data;
    tree left;
    tree right;
};

int preorder(tree t);
int s;
int main()
{
    int n;
    cin>>n;
    int a;
    cin >>a;
    struct Tree tt[10000];
    tt[a].data=a;
    for (int i = 0; i < n-1; i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        if(y==0){tt[x].left=&tt[z];tt[z].data=z;}
        if(y==1){tt[x].right=&tt[z];tt[z].data=z;}
    }
    preorder(&tt[a]);
    cout<<s;
    return 0;
}

int preorder(tree t){
    int w=0,flag=0;
    if (t)
    {   w=1;
        if(preorder(t->left)==0) flag++;
        if(preorder(t->right)==0)flag++;
        if(flag==2) s+=t->data;
    }
    return w;
}