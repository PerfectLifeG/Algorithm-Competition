#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Tree* tree;
struct Tree
{
    tree left;
    tree right;
    int data;
};
tree delete(int a,tree t);
int main()
{
    
    return 0;
}

tree delete(int a,tree t){ //太聪明了   delete删除值并返回子树地址
    tree p;
    if(!t) return NULL;
    else if(a<t->data){
            delete(a,t->left);
        }
    else if(a>t->data){
            delete(a,t->right);
        }
    else{
        if(t->left&&t->right){
            p=find(t->right);
            t->data=p->data;
            t->right=delete(p->data,t->right);
        }
        else{
            p=t;
            if(t->left){
                t->right
            }
        }
    }
    
    return t;
}


tree Delete( tree t, int X ) 
{ 
    tree p; 

    if( !t ) 
        printf("要删除的元素未找到"); 
    else {
        if( X < t->data ) 
            t->left = Delete( t->left, X );   /* 从左子树递归删除 */
        else if( X > t->data ) 
            t->right = Delete( t->right, X ); /* 从右子树递归删除 */
        else { /* BST就是要删除的结点 */
            /* 如果被删除结点有左右两个子结点 */ 
            if( t->left && t->right ) {
                /* 从右子树中找最小的元素填充删除结点 */
                p = FindMin( t->right );
                t->data = p->data;
                /* 从右子树中删除最小元素 */
                t->right = Delete( t->right, t->data );
            }
            else { /* 被删除结点有一个或无子结点 */
                p = t; 
                if( !t->left )       /* 只有右孩子或无子结点 */
                    t = t->right; 
                else                   /* 只有左孩子 */
                    t = t->left;
                free( p );
            }
        }
    }
    return t;
}