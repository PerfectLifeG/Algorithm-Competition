#include<bits/stdc++.h>
using namespace std;
const int N=10010;
#define sc(n) scanf("%d",&n)
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;sc(t);
    while(t--){
        int n;sc(n);getchar();
        int sum=10*n*n;int s=0;
        for(int i=0;i<n*n-1;i++){
            s+=10;
            for(int j=0;j<4;j++){
                char c;c=getchar();
                if(c=='1')s--;
                else if(c=='2')s++;
            }
            getchar();
        }
        printf("%d\n",sum-s);
    }
    return 0;
}