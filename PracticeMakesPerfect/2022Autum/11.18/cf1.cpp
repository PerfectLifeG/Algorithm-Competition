#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    string s="YesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYes";
    for (int i = 0; i < n; i++)
    {
        string a;cin>>a;
        if(s.find(a)!=-1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}