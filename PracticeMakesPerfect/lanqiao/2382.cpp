#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int prime[N+1];
int book[N+1]={1,1},cnt;
void get_primes(int n=N){
    for(int i=2;i<=n;i++){
        if(!book[i])prime[cnt++]=i;
        for(int j=0;prime[j]<=n/i;j++){
            book[prime[j]*i]=1;
            if(i%prime[j]==0)break;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    get_primes();
    for(int i=0;i<cnt;i++){
        int flag=1;
        int t=prime[i];
        while(t){
            int a=t%10;
            if(book[a]){flag=0;break;}
            t/=10;
        }
        if(!flag)continue;
        t=prime[i];
        while(t>10){
            int a=t%100;
            if(book[a]){flag=0;break;}
            t/=10;
        }
        if(!flag)continue;
        t=prime[i];
        while(t>100){
            int a=t%1000;
            if(book[a]){flag=0;break;}
            t/=10;
        }
        if(!flag)continue;
        t=prime[i];
        while(t>1000){
            int a=t%10000;
            if(book[a]){flag=0;break;}
            t/=10;
        }
        if(!flag)continue;
        if(flag)cout<<prime[i]<<' ';
    }
    return 0;
}