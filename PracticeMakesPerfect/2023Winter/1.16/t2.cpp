#include<bits/stdc++.h>
using namespace std;
const int N=10010;
#define sc(n) scanf("%d",&n)
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    int cnt=0;
    while(t--){
        int n;cin>>n;
        for(int i=0;i<n;i++)
        {int a;cin>>a;
        if(a>0)cnt++;}
        cout<<cnt<<endl;
    }
    return 0;
}