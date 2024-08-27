#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int main(){
    int n;
    cin>>n;getchar();
    for(int i=0;i<n;i++){
        char a,b;
        cin>>a>>b;
        getchar();
        if(a=='0')cout<<"1"<<endl;
        else if(b=='0')cout<<"3"<<endl;
        else if(b=='1')cout<<"2"<<endl;
    }
    return 0;
}