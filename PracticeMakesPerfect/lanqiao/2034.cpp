#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int book[N];
int mx[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cout<<max(2*(i-2)+2,2*(n-i-1)+2)<<endl;
    }
    return 0;
}