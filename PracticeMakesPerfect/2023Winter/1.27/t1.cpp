#include<bits/stdc++.h>
using namespace std;
const int N=10010;
#define sc(n) scanf("%d",&n)
char p[50]{'3','1','4','1','5','9','2','6','5','3','5','8','9','7','9','3','2','3','8','4','6','2','6','4','3','3','8','3','2','7'};
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        char c[50];
        cin>>c;
        int cnt=0;
        for(int i=0;i<strlen(c);i++){
            if(p[i]==c[i])cnt++;
            else break;
        }
        cout<<cnt<<endl;
    }
    return 0;
}