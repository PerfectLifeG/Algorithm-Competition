#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    static int b[100];
    scanf("%d %d",&n,&k);
    if(k>n)k=n;
    for (int i = 0; i <= k; i++)
    {
        b[i]=-100000000;
    }
    
    for (int l = 0; l < n; l++)
    {
        if(l>=k)
        scanf("%d",&b[k]);
        else scanf("%d",&b[l]);
        
    for (int i = 0; i < k; i++)
    {
        int t,p=i;
        for (int j = i+1; j < k+1; j++)
        {
            if (b[p]<b[j])  
            p=j;
        }
        t=b[p];
        b[p]=b[i];
        b[i]=t;
    }

    }
    
    
    printf("%d",b[0]);
    for (int i = 1; i < k; i++)
    {
        printf(" %d",b[i]);
    }
    return 0;
}