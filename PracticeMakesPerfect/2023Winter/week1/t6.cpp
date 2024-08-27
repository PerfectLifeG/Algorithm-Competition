#include<bits/stdc++.h>
using namespace std;
int isprime(int n){
    if(n==1||n==0)return 0;
    for(int i=2;i<=n/i;i++){
        if(n%i==0)return 0;
    }
    return 1;
}
int main(){
    int l,k;cin>>l>>k;getchar();
    int w=1;for(int i=0;i<k-1;i++)w*=10;
    int num=0;char c;
    int i=0;
    while((c=getchar())!='\n'&&i<k-1){num=num*10+c-'0';i++;}
    while(c!='\n'){
        num%=w;
        num=num*10+c-'0';
        if(isprime(num)){printf("%0*d",k,num);return 0;}
        c=getchar();
    }
    cout<<404;
    return 0;
}