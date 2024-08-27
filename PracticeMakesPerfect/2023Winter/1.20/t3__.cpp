#include<bits/stdc++.h>
using namespace std;
void fun(int n)
{
    int k=n/4+1;
    for(int i=0;i<k;i++)
        for(int j=0;;j++){
            int c=n-i*4-j*5;
            if(c<0) break;
            if(c%6==0){
                
                return ;
            }
        }
    printf("NO\n");
}
int main ()
{
    int n;
    while(~scanf("%d",&n)){
        fun(n);
    }
    return 0;
}