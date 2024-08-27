#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    for (int i = 0; i < n; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1){
            if(b==130)cout<<"wan mei! ";
            if(b>130)cout<<"ni li hai! ";
            if(b<130)cout<<"duo chi yu! ";
            if(c>27)cout<<"shao chi rou!";
            if(c==27)cout<<"wan mei!";
            if(c<27)cout<<"duo chi rou!";
        }
        else if(a==0){
            if(b==129)cout<<"wan mei! ";
            if(b>129)cout<<"ni li hai! ";
            if(b<129)cout<<"duo chi yu! ";
            if(c>25)cout<<"shao chi rou!";
            if(c==25)cout<<"wan mei!";
            if(c<25)cout<<"duo chi rou!";
        }
        cout<<endl;
    }
    
    return 0;
}