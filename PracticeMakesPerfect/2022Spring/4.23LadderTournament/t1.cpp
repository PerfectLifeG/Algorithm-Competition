#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;cin>>a>>b;
    int c,d;cin>>c>>d;
    if(c>=a&&d>=a)
    {cout<<c<<"-Y "<<d<<"-Y"<<endl;
    cout<<"huan ying ru guan"<<endl;}
    else if(c<a&&d<a)
    {cout<<c<<"-N "<<d<<"-N"<<endl;
    cout<<"zhang da zai lai ba"<<endl;}
    else if(c<a&&d>=b)
    {cout<<c<<"-Y "<<d<<"-Y"<<endl;
    cout<<"qing 2 zhao gu hao 1"<<endl;}
    else if(c>=b&&d<a)
    {cout<<c<<"-Y "<<d<<"-Y"<<endl;
    cout<<"qing 1 zhao gu hao 2"<<endl;}
    else if(c<b&&d<b&&c<a&&d>=a)
    {cout<<c<<"-N "<<d<<"-Y"<<endl;
    cout<<"2: huan ying ru guan"<<endl;}
    else if(c<b&&d<b&&c>=a&&d<a)
    {cout<<c<<"-Y "<<d<<"-N"<<endl;
    cout<<"1: huan ying ru guan"<<endl;}
    return 0;
}