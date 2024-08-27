#include<bits/stdc++.h>
using namespace std;
const int N = 10010;
int main(){
    int t; cin >> t;
    while(t -- ){
        int n;
        scanf("%d", &n);
        if(n%2 == 0 || n==1){
            printf("YES\n");
            int s = -1;
            int flag = 1;
            for(int i = 0; i < n; i++){
                if(flag==0)printf(" %d", s);
                else if(flag){printf("%d", s);flag=0;}
                s*= -1;
            }
            puts("");
        }else 
        printf("NO\n");
    }
    return 0;
}