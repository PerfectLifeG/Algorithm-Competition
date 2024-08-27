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
int main()
{
    int n;
    cin>>n;
    int a=n*n*n;
    for (int i = 101; i <= n*n*2;)
    {
        int s=i;
        int j=i;int flag=j;
        while (s<a)
        {
            j+=2;
            s+=j;
        }
        if(s==a)
        {   printf("%d*%d*%d=%d=%d",n,n,n,a,flag);
            int k;
            for (k = flag+2; k <= j;)
            {
                printf("+%d",k);
                 k+=2;
            }
            break;
           
        }
        
        i+=2;
    }   
    
    return 0;
}