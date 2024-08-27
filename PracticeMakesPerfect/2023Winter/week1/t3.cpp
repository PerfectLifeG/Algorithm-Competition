#include<bits/stdc++.h>
using namespace std;
int main(){
    int st,time;cin>>st>>time;
    int min=st%10;st/=10;
    min+=10*(st%10);
    st/=10;
    min+=time;
    int h=min/60;
    min%=60;
    if(min<0){h--;min+=60;}
    h+=st;
    cout<<h<<min;
    if(min/10==0)cout<<0;
    return 0;
}