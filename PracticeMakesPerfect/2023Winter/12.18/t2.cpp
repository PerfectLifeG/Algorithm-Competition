#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int mn=999;int mx=0;
        int idx1,idx2;
        for(int j=1;j<=4;j++){
            int a;scanf("%d",&a);
            if(mn>a){idx1=j;mn=a;}
            if(a>mx){idx2=j;mx=a;}
        }
        if(idx1+idx2==5)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}