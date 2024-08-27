#include<bits/stdc++.h>
using namespace std;
#define psi pair<string,int>
int cmp(psi &v1,psi &v2){
    if(v1.first[0]==v2.first[0]){
        // if(v1.first[1]=='s')return v1.first[0]<v2.first[0];
        // if(v2.first[1]=='s')return v1.first[0]>v2.first[0];
        // if(v1.first[1]=='p')return v1.first[0]<v2.first[0];
        // if(v2.first[1]=='p')return v1.first[0]>v2.first[0];
        // if(v1.first[1]=='d')return v1.first[0]<v2.first[0];
        // if(v2.first[1]=='d')return v1.first[0]>v2.first[0];
        // if(v1.first[1]=='f')return v1.first[0]<v2.first[0];
        // if(v2.first[1]=='f')return v1.first[0]>v2.first[0];
        return v1.second<v2.second;
    }
    return v1.first[0]<v2.first[0];
}
int main()
{
    int t;cin>>t;
    for (int i = 0; i < t; i++)
    {
        vector<psi>v;
        int a;cin>>a;
        if(a>0){
            if(a<2)v.push_back({"1s",a});
            else v.push_back({"1s",2});
            a-=2;
        }
        if(a>0){
            if(a<2)v.push_back({"2s",a});
            else v.push_back({"2s",2});
            a-=2;
        }
        if(a>0){
            if(a<6)v.push_back({"2p",10+a});
            else v.push_back({"2p",10+6});
            a-=6;
        }
        if(a>0){
            if(a<2)v.push_back({"3s",a});
            else v.push_back({"3s",2});
            a-=2;
        }if(a>0){
            if(a<6)v.push_back({"3p",10+a});
            else v.push_back({"3p",10+6});
            a-=6;
        }
        if(a>0){
            if(a<2)v.push_back({"4s",a});
            else v.push_back({"4s",2});
            a-=2;
        }if(a>0){
            if(a<10)v.push_back({"3d",20+a});
            else v.push_back({"3d",20+10});
            a-=10;
        }
        if(a>0){
            if(a<6)v.push_back({"4p",10+a});
            else v.push_back({"4p",10+6});
            a-=6;
        }
        if(a>0){
            if(a<2)v.push_back({"5s",a});
            else v.push_back({"5s",2});
            a-=2;
        }if(a>0){
            if(a<10)v.push_back({"4d",20+a});
            else v.push_back({"4d",20+10});
            a-=10;
        }if(a>0){
            if(a<6)v.push_back({"5p",10+a});
            else v.push_back({"5p",10+6});
            a-=6;
        }if(a>0){
            if(a<2)v.push_back({"6s",a});
            else v.push_back({"6s",2});
            a-=2;
        }
        if(a>0){
            if(a<14)v.push_back({"4f",30+a});
            else v.push_back({"4f",30+14});
            a-=14;
        }if(a>0){
            if(a<10)v.push_back({"5d",20+a});
            else v.push_back({"5d",20+10});
            a-=10;
        }if(a>0){
            if(a<6)v.push_back({"6p",10+a});
            else v.push_back({"6p",10+6});
            a-=6;
        }if(a>0){
            if(a<2)v.push_back({"7s",a});
            else v.push_back({"7s",2});
            a-=2;
        }
        if(a>0){
            if(a<14)v.push_back({"5f",30+a});
            else v.push_back({"5f",30+14});
            a-=14;
        }if(a>0){
            if(a<10)v.push_back({"6d",20+a});
            else v.push_back({"6d",20+10});
            a-=10;
        }if(a>0){
            if(a<6)v.push_back({"7p",10+a});
            else v.push_back({"7p",10+6});
            a-=6;
        }
        sort(v.begin(),v.end(),cmp);
        auto it=v.begin();
        cout<<it->first<<it->second;
        it++;
        for(;it!=v.end();it++){
            if(it->first[1]=='s')
            cout<<" "<<it->first<<it->second;
            if(it->first[1]=='p')
            cout<<" "<<it->first<<it->second-10;
            if(it->first[1]=='d')
            cout<<" "<<it->first<<it->second-20;
            if(it->first[1]=='f')
            cout<<" "<<it->first<<it->second-30;
        }
        cout<<endl;
    }
    return 0;
}