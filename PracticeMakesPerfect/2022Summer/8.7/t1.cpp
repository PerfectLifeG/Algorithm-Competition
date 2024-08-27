#include<bits/stdc++.h>
using namespace std;
int main()
{
    char c;
    int i=0;int ans=0;
    while((c=getchar())!='\n'){
        if(c=='0'){
            if(i%2==0){
                ans-=i*i;
            }else ans+=i*i;
            i=0;
        }else i++;
    }
    if(i%2==0)
    cout<<ans-i*i;
    else cout<<ans+i*i;
    return 0;
}