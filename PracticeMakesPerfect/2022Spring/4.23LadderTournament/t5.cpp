#include<bits/stdc++.h>
using namespace std;
int book[7][7];
int main(){
    int a[7],b[7];
    for (int i = 1; i <= 6; i++)
    {
        cin>>a[i];
        book[i][a[i]]=1;
        // if(a[i]==6)b[i]=5;
        // else b[i]=6;
        // book[i][b[i]]=1;
    }
    int n;cin>>n;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            for (int k = 6; k >= 1; k--)
            {
                if(book[j][k]==0){book[j][k]=1;break;}
            }
        }
    }
    for (int j = 1; j <= 6; j++)
        {
            for (int k = 6; k >= 1; k--)
            {
                if(j==1&&book[j][k]==0){cout<<k;break;}
                else if(book[j][k]==0){cout<<" "<<k;break;}
            }
        }
    
    
    return 0;
}