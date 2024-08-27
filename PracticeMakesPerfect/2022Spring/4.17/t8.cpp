#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    if(m>50&&m<800)cout<<0;
    else if(m>800&&m<850)cout<<0;
    else if(m>850&&m<900)cout<<0;
    else if(m<50)cout<<0;
    else if(m>900)cout<<0;
    return 0;
}