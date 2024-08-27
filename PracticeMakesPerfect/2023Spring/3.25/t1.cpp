#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int book[10];
int book2[10];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    string a,b;cin>>a>>b;
    cout<<a<<' '<<b<<endl;
    if(a==b){cout<<"Equal";return 0;}
    for(auto i:a){
        book[i-'0']++;
    }
    for(auto i:b){
        book2[i-'0']++;
    }
    for(int i=0;i<=9;i++){
        if(book[i]!=book2[i]){
            cout<<"Different";
            return 0;
        }
    }
    cout<<"ALIEN";
    return 0;
}