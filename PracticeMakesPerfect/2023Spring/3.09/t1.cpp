#include<bits/stdc++.h>
using namespace std;
const int N=10010;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        int l=0,dl=0;
        for(int i=0;i<n;i++){
            int a;cin>>a;
            if(a>0)l++;
            else if(a<0)dl++;
        }
        for(int i=1;i<=l;i++){
            cout<<i<<' ';
        }
        for(int i=1;i<=dl;i++){
            cout<<l-i<<' ';
        }
        cout<<endl;
        int a=1;
        for(int i=1;i<=l;i++){
            cout<<a<<' ';
            if(dl){
                cout<<--a<<' ';
                dl--;
            }
            a++;
        }
        cout<<endl;
    }
    return 0;
}