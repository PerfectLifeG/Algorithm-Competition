#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int x,y,xp,yp;
        cin>>x>>y>>xp>>yp;
        int op[][2]={0,0,x,0,0,y,x,y};
        int r2=0;
        int tx,ty;
        for(int i=0;i<4;i++){
            if(abs(xp-op[i][0])*abs(yp-op[i][1])>r2){
                r2=abs(xp-op[i][0])*abs(yp-op[i][1]);
                tx=op[i][0];ty=op[i][1];
            }
        }
        int jiao;
        int r1=x*y;
        if(xp<x&&xp>0&&yp<y&&yp>0)jiao=r2;
        else if(xp<x&&xp>0)jiao=abs(tx-xp)*y;
        else if(yp<y&&yp>0)jiao=abs(ty-yp)*x;
        else jiao=r1;
        int bing=r1+r2-jiao;
        printf("%.9lf\n",1.0*jiao/bing);
    }
    return 0;
}