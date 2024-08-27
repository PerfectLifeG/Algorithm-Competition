#include<cstdio>
const int N=1000005,M=1005;
int n,m,i,j,k,f[M][M],d[N][3],p[N/10],tot;bool v[N];
int gcd_normal(int x,int y){
if(!x||!y)return x+y;
return gcd_normal(y,x%y);
}
inline int gcdfast(int a,int b){
if(!a||!b)return a+b;
int c=1;
while(a-b){
if(a&1){
if(b&1){
if(a>b)a=(a-b)>>1;else b=(b-a)>>1;
}else b>>=1;
}else{
if(b&1)a>>=1;else c<<=1,a>>=1,b>>=1;
}
}
return c*a;
}
inline int gcdO1(int x,int y){
if(!x||!y)return x+y;
int t=1;
for(int*j=d[x],i=0,k;i<3&&y>1;i++,j++){
if(*j==1)continue;
else if(*j<=m)k=f[*j][y%*j];
else if(y%*j==0)k=*j;
else continue;
t*=k,y/=k;
}
return t;
}
int main(){
    n=1000000,m=1000;
    for(i=0;i<=m;i++)f[0][i]=f[i][0]=f[i][i]=i;
    for(i=2;i<=m;i++)for(j=1;j<i;j++)f[i][j]=f[j][i]=f[i-j][j];
    for(d[1][0]=d[1][1]=d[1][2]=1,i=2;i<=n;i++){
        if(!v[i])p[tot++]=i,d[i][0]=i,d[i][1]=d[i][2]=1;
        for(j=0;j<tot;j++){
            if(i*p[j]>n)break;
            v[k=i*p[j]]=1;
            d[k][0]=d[i][0],d[k][1]=d[i][1],d[k][2]=d[i][2];
            if(d[k][0]*p[j]<=m)d[k][0]*=p[j];
            else if(d[k][1]*p[j]<=m)d[k][1]*=p[j];
            else d[k][2]*=p[j];
            if(i%p[j]==0)break;
        }
    }
}