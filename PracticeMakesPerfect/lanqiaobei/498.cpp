#include<bits/stdc++.h>
using namespace std;
const int N=99999999;
int main(){
    int n;scanf("%d",&n);
    int flag=1,flag2=1;
    int ans1=0,ans2=0;
    for(int i=n+1;i<=N;i++){
        int a=(i/10000000)%10;
        int b=(i/1000000)%10;
        int c=(i/100000)%10;
        int d=(i/10000)%10;
        int e=(i/1000)%10;
        int f=(i/100)%10;
        int g=(i/10)%10;
        int h=i%10;
        if(!(e*10+f>=1&&e*10+f<=12&&g*10+h>=1&&g*10+h<=31)){
            continue;
        }
        if(e*10+f==2&&g*10+h>29)continue;
        if(flag&&a==h&&b==g&&c==f&&d==e){
            ans1=i;
            flag=0;
        }
        if(flag2&&a==h&&b==g&&a==c&&b==d&&c==f&&d==e){
            ans2=i;
            flag2=0;
        }
        if(!flag&&!flag2)break;
    }
    if(ans1)printf("%08d\n",ans1);
    if(ans2)printf("%08d",ans2);
    return 0;
}