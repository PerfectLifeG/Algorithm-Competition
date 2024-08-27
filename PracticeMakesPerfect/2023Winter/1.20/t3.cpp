#include<bits/stdc++.h>
using namespace std;
int x,y,z;
int fun(int n)
{
    int k=n/4+1;
    for(int i=0;i<k;i++)
        for(int j=0;;j++){
            int c=n-i*4-j*5;
            if(c<0) break;
            if(c%6==0){
                x=i;y=j;z=c/6;
                return 1;
            }
        }
    return 0;
}
void solve(){
    int n;cin>>n;
    if(fun(n)){
        int idx=1;
        for(int i=0;i<x;i++){
            printf("%d ",(idx++)+2);
            printf("%d ",(idx++)+2);
            printf("%d ",(idx++)-2);
            printf("%d ",(idx++)-2);
        }
        for(int i=0;i<y;i++){
            printf("%d ",(idx++)+2);
            printf("%d ",(idx++)+2);
            printf("%d ",(idx++)+2);
            printf("%d ",(idx++)-2);
            printf("%d ",(idx++)-2);
        }
        for(int i=0;i<z;i++){
            printf("%d ",(idx++)+3);
            printf("%d ",(idx++)+3);
            printf("%d ",(idx++)+3);
            printf("%d ",(idx++)-3);
            printf("%d ",(idx++)-3);
            printf("%d ",(idx++)-3);
        }
    }
    else puts("-1");
}
int main(){
    solve();
    return 0;
}