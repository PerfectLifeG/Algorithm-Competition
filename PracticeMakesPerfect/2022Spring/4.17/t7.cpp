#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,x;
    cin>>n>>k>>x;
    int a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>a[i][j];
        }
        
    }
    int m=1;
    for (int j = 1; j < n; j += 2)
    {
        for (int i = n-1; i >= 0; i--)
        {
            if(i<m)a[i][j]=x;
            else
            a[i][j]=a[i - m][j];
        }
        m++;
        if(m>k)m=1;
    }

    int s=0;
    for (int i = 0; i < n; i++)
    s+=a[0][i];
    printf("%d",s);
    
    for (int i = 1; i < n; i++)
    {
        int s=0;
        for (int j = 0; j < n; j++)
        {
            s+=a[i][j];
        }
        printf(" %d",s);
    }
    
    return 0;
}