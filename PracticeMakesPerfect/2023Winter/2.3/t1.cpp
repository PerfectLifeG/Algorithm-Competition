#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100010;
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    if(n<=7)cout<<"very easy";
    else if(n<=233)cout<<"easy";
    else if(n<=10032)cout<<"medium";
    else if(n<=114514)cout<<"hard";
    else if(n<=1919810)cout<<"very hard";
    else cout<<"can not imagine";
    return 0;
}