#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int book[10];
int main(){

    int t;cin>>t;

    book[1]=2;
    for(int i=2;i<=10;i++)book[i]=i+book[i-1];
    
    for(int i=0;i<t;i++){
        int n,m;scanf("%d%d",&n,&m);
        int j=min(n,9);
        while(m<book[j])j--;
        int cnt;
        if(n-j-1<=m-book[j])cnt=j;
        else while(n-j-1>m-book[j])j--;
        cnt=j;
        int s=1;
        for(int j=0;j<cnt+1&&j<n-1;j++){
            s+=j;
            printf("%d ",s);
        }
        for(int j=cnt+1;j<n-1;j++){
            s+=1;
            printf("%d ",s);
        }
        printf("%d\n",m);
    }
    return 0;
}