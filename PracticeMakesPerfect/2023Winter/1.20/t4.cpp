#include<bits/stdc++.h>
using namespace std;
int main(){
    double xa,xb,ya,yb;
    cin>>xa>>ya>>xb>>yb;
    if(yb<ya){
        swap(ya,yb);
        swap(xa,xb);
    }
    double x=1.0*(xa+xb)/2;
    double y=1.0*(ya+yb)/2;
    if(xa==xb){
        double ansx=xa+fabs(ya-yb)/2;
        if(y-(int)y>0||ansx-(int)ansx>0){puts("No Answer!");}
        else printf("%d %d\n",(int)ansx,(int)y);
        return 0;
    }
    if(ya==yb){
        double ansy=ya+fabs(xa-xb)/2;
        if(x-(int)x>0||ansy-(int)ansy>0){puts("No Answer!");}
        else {printf("%d %d\n",(int)x,(int)ansy);}
        return 0;
    }
    double lk=1.0*(ya-yb)/(xa-xb);
    if(lk==1||lk==-1){
        printf("%d %d\n",(int)xa,(int)yb);
        return 0;
    }
    double k1=-1.0/lk;
    double k2=(1.0+lk)/(1.0-lk);
    double b2=-1;double b1=-1;double a1=k1;double a2=k2;double c1=-(y-k1*x);double c2=-(ya-k2*xa);
    double ansx=1.0*(c1-c2)/(a1-a2);
    double ansy=1.0*a1*ansx-c1;
    for(int i=(int)ansx-1;i<=(int)ansx+1;i++){
        for(int j=(int)ansy-1;j<=(int)ansy+1;j++){
            if(((x-xa)*(x-xa)+(y-ya)*(y-ya))==((i-x)*(i-x)+(j-y)*(j-y))){
                printf("%d %d\n",i,j);
                return 0;
            }
        }
    }
    puts("No Answer!");
    return 0;
}