#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;cin>>a>>b;
    int s=1;
    for (int i = 1; i <= a+b; i++)
    {
        s*=i;
    }
    cout<<s;
    return 0;
}