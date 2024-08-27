#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int main(){
    int n;cin>>n;getchar();
    int cnta=0,cntb=0;
    for(int i=0;i<n;i++){
        int flag=1;
        cnta=0,cntb=0;
        for(int j=1;j<=10;j++){
            char c;cin>>c;
            if(flag==0)continue;
            if(c=='1'){
                if(j&1){
                    cnta++;
                    if((10-j)/2+1+cntb<cnta){
                        printf("%d\n",j);
                        flag=0;
                    }
                }
                else {
                    cntb++;
                        if((10-j)/2+cnta<cntb){
                        printf("%d\n",j);
                        flag=0;
                    }
                }
            }else{
                if(j&1){
                    if((10-j)/2+cnta<cntb){
                        printf("%d\n",j);
                        flag=0;
                    }
                }
                else {
                        if((10-j)/2+cntb<cnta){
                        printf("%d\n",j);
                        flag=0;
                    }
                }
            }
        }
        getchar();
        if(flag)puts("-1");
    }
    return 0;
}