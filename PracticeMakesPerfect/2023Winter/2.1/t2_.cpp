#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    string a,b;
    int n=0;char c;
    int i=-1;while((c=getchar())!='\n'){i++;n=n*10+(c-'0');}
    while(1){
        int t=pow(10,i);
        if(n==t){
            if((a+to_string(t))==b){cout<<"win-win!";return 0;}
        }
        if(n<=t&&t!=1){i--;t=pow(10,i);}
        n-=t;
        a+=to_string(t);
        if(n==0){
            if(a<b)cout<<"Sajin-win!";
            else if(a>b)cout<<"Yaya-win!";
            else cout<<"win-win!";
            return 0;
        }
        if(n==t){
            if((b+to_string(t))==a){cout<<"win-win!";return 0;}
        }
        if(n<=t&&t!=1){i--;t=pow(10,i);}
        n-=t;
        b+=to_string(t);
        if(n==0){
            if(a<b)cout<<"Sajin-win!";
            else if(a>b)cout<<"Yaya-win!";
            else cout<<"win-win!";
            return 0;
        }
    }
    return 0;
}