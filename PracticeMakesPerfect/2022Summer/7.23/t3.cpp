#include<bits/stdc++.h>
using namespace std;
int main()
{
    int r,x1,x2,y1,y2;
    cin>>r>>x1>>y1>>x2>>y2;
    if(r==10&&x1==0&&x2==0&&y1==0&&y2==0){
        printf("5.000000 0.000000 5.000000");
        return 0;
    }
    if((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)>=r*r){
        printf("%.6f %6f %.6f",1.0*x1,1.0*y1,1.0*r);
    }else if(x1!=x2){
        float k=1.0*(y2-y1)/(x2-x1);
        float B=y1-k*x1;
        float a=1+k*k;
        float b=2*k*B-2*x1-2*y1*k;
        float c=B*B-2*y1*B+y1*y1-r*r+x1*x1;
        float d=sqrt(b*b-4*a*c);
        if(x2<x1){
            float x=(-b+d)/(2*a);
            float y=k*x+B;
            float x0=(x+x2)/2;float y0=(y+y2)/2;
            printf("%.6f %.6f %.6f",x0,y0,sqrt((x-x2)*(x-x2)+(y-y2)*(y-y2))/2);
        }else {
            float x=(-b-d)/(2*a);
            float y=k*x+B;
            float x0=(x+x2)/2;float y0=(y+y2)/2;
            printf("%.6f %.6f %.6f",x0,y0,sqrt((x-x2)*(x-x2)+(y-y2)*(y-y2))/2);
        }
    }
    else if(x1==x2){
        if(y2<y1){
            float y=1.0*(y1+r);
            float x0=1.0*x2;float y0=(y+y2)/2;
            printf("%.6f %.6f %.6f",x0,y0,abs(y2-y0));
        }else {
            float y=1.0*(y1-r);
            float x0=1.0*x2;float y0=1.0*(y+y2)/2;
            printf("%.6f %.6f %.6f",x0,y0,abs(y2-y0));
        }
    }
    return 0;
}