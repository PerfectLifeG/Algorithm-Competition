#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int a,b;
    cin>>a>>b;
    if(a<b){cout<<"niuniu eats more than others";return 0;}
    int c=a%b;
    if(c<a/b){
        cout<<"niuniu eats less than others";
    }else if(c==a/b)cout<<"same";
    else cout<<"niuniu eats more than others";
    return 0;
}