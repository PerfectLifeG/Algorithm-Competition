#include<bits/stdc++.h>
using namespace std;
int main()
{
    char c;int s=0;
    while((c=getchar())!='\n'){
        s+=c-'0';
    }
    int ss=s;int i=0;
    if(s==0){cout<<"zero";return 0;}
    while(s){
        s/=10;
        i++;
    }
    int a=pow(10,i-1);
    if(ss/a==1){cout<<"one";ss-=1*a;}
        else if(ss/a==2){cout<<"two";ss-=2*a;}
        else if(ss/a==3){cout<<"three";ss-=3*a;}
        else if(ss/a==4){cout<<"four";ss-=4*a;}
        else if(ss/a==5){cout<<"five";ss-=5*a;}
        else if(ss/a==6){cout<<"six";ss-=6*a;}
        else if(ss/a==7){cout<<"seven";ss-=7*a;}
        else if(ss/a==8){cout<<"eight";ss-=8*a;}
        else if(ss/a==9){cout<<"nine";ss-=9*a;}
        else if(ss/a==0){cout<<"zero";}
    i--;    
    while(i){
        int a=pow(10,i-1);
        if(ss/a==1){cout<<" "<<"one";ss-=1*a;}
        else if(ss/a==2){cout<<" "<<"two";ss-=2*a;}
        else if(ss/a==3){cout<<" "<<"three";ss-=3*a;}
        else if(ss/a==4){cout<<" "<<"four";ss-=4*a;}
        else if(ss/a==5){cout<<" "<<"five";ss-=5*a;}
        else if(ss/a==6){cout<<" "<<"six";ss-=6*a;}
        else if(ss/a==7){cout<<" "<<"seven";ss-=7*a;}
        else if(ss/a==8){cout<<" "<<"eight";ss-=8*a;}
        else if(ss/a==9){cout<<" "<<"nine";ss-=9*a;}
        else if(ss/a==0){cout<<" "<<"zero";}
        i--;
    }
    return 0;
}