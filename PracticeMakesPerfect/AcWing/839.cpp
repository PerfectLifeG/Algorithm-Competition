#include<iostream>
#include<string.h>
using namespace std;
const int N=100010;
int h[N];
int idx,n;
int hp[N],ph[N];
void heap_swap(int a, int b)
{
    swap(ph[hp[a]],ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}
void down(int k){
    int mn=k;
    if(2*k<=idx && h[2*k]<h[mn])mn=2*k;
    if(2*k+1<=idx && h[2*k+1]<h[mn])mn=2*k+1;
    if(mn!=k){
        heap_swap(k,mn);
        down(mn);
    }
}
void up(int k){
    while(k/2 && h[k/2]>h[k]){    //     不是k而是k/2。。。。。。。。
        heap_swap(k/2,k);
        k/=2;
    }
}
int main(){
    int  i = 0;
    scanf("%d",&n);
    while (n -- )
    {
        string c;cin>>c;
        int x,k;
        if(c=="I"){
            cin>>x;
            h[++idx]=x;
            i++;
            ph[i]=idx;
            hp[idx]=i;
            up(idx);
        }else if(c=="PM"){
            printf("%d\n",h[1]);
        }else if(c=="DM"){
            heap_swap(1,idx);
            idx--;
            down(1);
        }else if(c=="D"){
            cin>>k;
            k=ph[k];
            heap_swap(k,idx);   //这个k=ph[k] 把我害惨了！！！！！！
            idx--;
            down(k);
            up(k);
        }else{
            cin>>k>>x;     
            k=ph[k];
            h[k]=x;
            down(k);
            up(k);
        }
    }
    return 0;
}