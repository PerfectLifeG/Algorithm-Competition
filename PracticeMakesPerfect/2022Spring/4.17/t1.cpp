#include<bits/stdc++.h>
using namespace std;
int main(){
    float a,b,c;cin>>a>>b>>c;
    float e;
    if(b==0){e=a*2.455;
    printf("%.2f ",a*2.455);}
    else if(b==1){e=a*1.26;printf("%.2f ",a*1.26);}
    if(e>c)cout<<"T_T";
    else cout<<"^_^";
   // else cout<<"^_^";
    return 0;
}