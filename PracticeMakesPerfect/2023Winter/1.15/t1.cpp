#include<bits/stdc++.h>
using namespace std;
const int N=10010;
#define sc(n) scanf("%d",&n)
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int w,h,d;cin>>w>>d>>h;
        int a,b,f,g;cin>>a>>b>>f>>g;
        cout<<min(min(h+abs(a-f)+g+b,h+abs(g-b)+a+f),min(h+abs(a-f)+d-g+d-b,h+abs(g-b)+w-a+w-f))<<endl;
    }
    return 0;
}