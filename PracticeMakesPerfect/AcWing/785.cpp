#include<iostream>
using namespace std;
const int N=1e8+10;
int n;
int q[N];
void qp(int q[],int l,int r){
    if(l>=r)return ;
    int x=q[(l+r)/2];int i=l-1;int j=r+1;
    while(i<j){
        do i++;while(q[i]<x);
        do j++;while(q[j]>x);
        if(i<j)swap(q[i],q[j]);
    }
    qp(q,l,j);
    qp(q,j+1,r);
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d",&q[i]);
    }
    qp(q,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",q[i]);
    }
    return 0;
}