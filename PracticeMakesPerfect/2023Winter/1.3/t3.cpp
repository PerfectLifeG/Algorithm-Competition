#include<bits/stdc++.h>
using namespace std;
const int N = 10010;
int s[N];
int main(){
    int t; cin >> t;
    while(t -- ){
        int n,m;cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>s[i];
            s[i]+=s[i-1];
        }
        for(int i=1;i<=n;i++){
            cout<<s[i]<<' ';
        }
        puts("");
    }
    return 0;
}