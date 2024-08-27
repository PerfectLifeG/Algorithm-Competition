#include<iostream>
using namespace std;
int main(){
    int n;char c;
    cin>>n>>c;
    int cnt=2;
    int s=2;
    while(s-1+cnt+4<=n){
        cnt+=4;
        s+=cnt;
    }
    cnt/=2;
    int num=cnt/2+1;
    for(int j=0;j<num;j++){
        for(int i=0;i<j;i++){
            printf(" ");
        }
        for(int i=0;i<cnt;i++){
            printf("%c",c);
        }
        cnt-=2;
        puts("");
    }
    cnt+=2;
    for(int j=1;j<=num-1;j++){
        cnt+=2;
        for(int i=0;i<num-1-j;i++){
            printf(" ");
        }
        for(int i=0;i<cnt;i++){
            printf("%c",c);
        }
        puts("");
    }
    cout<<n-s+1;
    return 0;
}