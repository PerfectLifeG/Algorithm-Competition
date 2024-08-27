#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int main(){
    int a=0;char c;
    int i=0;while((c=getchar())!='\n'){i++;a=a*10+(c-'0');}
    int cnt=1;
    while(1){
        int t=pow(10,i-1);
        if(a-t>=3&&a-t<t){
            if(cnt==-1){cout<<"Yaya-win!"<<endl;return 0;}
            else if(cnt==1){cout<<"Sajin-win!"<<endl;return 0;}
        }else if(a==t||a-t==t){cout<<"win-win!"<<endl;return 0;}
        else if(a<10){
            if(a%2==0){cout<<"win-win!"<<endl;return 0;}
            else {
                if(cnt==1){cout<<"Yaya-win!"<<endl;return 0;}
                else if(cnt==-1){cout<<"Sajin-win!"<<endl;return 0;}
            }
        }
        a-=t;
        cnt*=-1;
    }
    return 0;
}