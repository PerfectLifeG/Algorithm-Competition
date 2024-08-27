#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        if(a&1){
            cout<<"Love!"<<endl;
        }else cout<<"!Love"<<endl;
    }   
    return 0;
}