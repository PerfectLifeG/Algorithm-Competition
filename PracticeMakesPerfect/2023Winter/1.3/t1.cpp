#include<bits/stdc++.h>
using namespace std;
const int N = 10010;
int main(){
    int t; cin >> t;
    while(t -- ){
        int n;
        scanf("%d", &n);
        string s;
        cin >> s;
        if(s.find("RL") != -1){
            printf("0\n");
            continue;
        }
        else if(s.find("LR") != -1){
            printf("%d\n", s.find("LR") + 1);
        }
        else printf("-1\n");
    }
    return 0;
}