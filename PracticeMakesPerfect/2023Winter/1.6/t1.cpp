#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int main(){
    int n,a,b;
    cin>>n>>a>>b;
    int ans1=n%a;
    ans1%=b;
    int ans2=n%b;
    ans2%=a;
    cout<<min(ans1,ans2);
    return 0;
}