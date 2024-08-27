#include<bits/stdc++.h>
using namespace std;
int main(){
    string a;
    cin>>a;
    string s1,s2;
    for (int i = 0; i < a.size(); i++)
    {
        if((a[i]-'0')%2==(a[i-1]-'0')%2){
            s1+=max(a[i],a[i-1]);
            if(s1[0]=='0')s1.erase(0,1);
        }
    }
    cin>>a;
    for (int i = 0; i < a.size(); i++)
    {
        if((a[i]-'0')%2==(a[i-1]-'0')%2){
            s2+=max(a[i],a[i-1]);
            if(s2[0]=='0')s2.erase(0,1);
        }
    }
    if(s1==s2)cout<<s1;
    else cout<<s1<<endl<<s2;
    return 0;
}