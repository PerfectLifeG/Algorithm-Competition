#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    for (int i = 0; i < t; i++)
    {
        int s,ss,cnt=0;
        int a,b,c,d,e,f;
        cin>>s>>a>>b>>c>>d>>e>>f;
        if(36*s<a+4*b+9*c+16*d+25*e+36*f){cout<<"No"<<endl;continue;}
        int c1,c2;
        c2=c%4;if(c2==0)c1=c/4;else c1=c/4+1;
        int y=s-c1-d-e-f;
        s=s-c1-d-e-f;
        if(s<0){cout<<"No"<<endl;continue;}
        else {
            b=b-9*s-5*d;
            if(c2==1)b-=5;
            if(c2==2)b-=3;
            if(c2==3)b-=1;
            if(b>0){cout<<"No"<<endl;continue;}
        }
        cout<<"Yes"<<endl;
    }
    return 0;
}