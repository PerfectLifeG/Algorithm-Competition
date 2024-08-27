#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<string>
#include<cmath>
using namespace std;
int food[150003];
int find(int a){
    int t=a,tt=food[a];
    while(food[a]!=a)
    a=food[a];
    while (t!=a)    
    {
        tt=a;
        t=food[t];
        tt=food[t];
    }
    return a;
}

void merge(int a,int b){
    a=find(food[a]);b=find(food[b]);
    food[a]=b;
}

int main()
{   int cnt=0;
    int n,k;
    cin>>n>>k;
    for (int i = 1; i <= n*3; i++)food[i]=i;
    for (int i = 0; i < k; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a==2&&b==c){cnt++;continue;}
        if(b>n||c>n){cnt++;continue;}
        if(a==1) {
            if(find(b)==find(c+n)||find(b)==find(c+2*n)){cnt++;continue;}//b不吃c  c不吃b
            merge(b,c);
            merge(b+n,c+n);
            merge(b+2*n,c+2*n);
        }
        else if(a==2) {
            if(find(b)==find(c)||find(b)==find(c+2*n)){cnt++;continue;}
            merge(b,c+n);
            merge(b+n,c+2*n);
            merge(b+2*n,c);
        }
    }
    printf("%d",cnt);
    return 0;
}