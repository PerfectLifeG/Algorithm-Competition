#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    for (int i = 0; i < t; i++)
    {
        map<string,int>mp;
        int a;cin>>a;
        if(a>0){
            if(a<2)mp["1s"]=a;
            else mp["1s"]=2;
            a-=2;
        }
        if(a>0){
            if(a<2)mp["2s"]=a;
            else mp["2s"]=2;
            a-=2;
        }
        if(a>0){
            if(a<6)mp["2p"]=a;
            else mp["2p"]=6;
            a-=6;
        }
        if(a>0){
            if(a<2)mp["3s"]=a;
            else mp["3s"]=2;
            a-=2;
        }if(a>0){
            if(a<6)mp["3p"]=a;
            else mp["3p"]=6;
            a-=6;
        }
        if(a>0){
            if(a<2)mp["4s"]=a;
            else mp["4s"]=2;
            a-=2;
        }if(a>0){
            if(a<10)mp["3d"]=a;
            else mp["3d"]=10;
            a-=10;
        }
        if(a>0){
            if(a<6)mp["4p"]=a;
            else mp["4p"]=6;
            a-=6;
        }
        if(a>0){
            if(a<2)mp["5s"]=a;
            else mp["5s"]=2;
            a-=2;
        }if(a>0){
            if(a<10)mp["4d"]=a;
            else mp["4d"]=10;
            a-=10;
        }if(a>0){
            if(a<6)mp["5p"]=a;
            else mp["5p"]=6;
            a-=6;
        }if(a>0){
            if(a<2)mp["6s"]=a;
            else mp["6s"]=2;
            a-=2;
        }
        if(a>0){
            if(a<14)mp["4f"]=a;
            else mp["4f"]=14;
            a-=14;
        }if(a>0){
            if(a<10)mp["5d"]=a;
            else mp["5d"]=10;
            a-=10;
        }if(a>0){
            if(a<6)mp["6p"]=a;
            else mp["6p"]=6;
            a-=6;
        }if(a>0){
            if(a<2)mp["7s"]=a;
            else mp["7s"]=2;
            a-=2;
        }
        if(a>0){
            if(a<14)mp["5f"]=a;
            else mp["5f"]=14;
            a-=14;
        }if(a>0){
            if(a<10)mp["6d"]=a;
            else mp["6d"]=10;
            a-=10;
        }if(a>0){
            if(a<6)mp["7p"]=a;
            else mp["7p"]=6;
            a-=6;
        }
        auto it=mp.begin();
        cout<<it->first<<it->second;
        it++;
        for(;it!=mp.end();it++){
            if(it->first[1]=='p'&&(++it)->first[1]=='s')
            cout<<" "<<(--it)->first<<(--it)->second<<" "<<(++it)->first<<(++it)->second;
            else cout<<" "<<it->first<<it->second;
        }
        cout<<endl;
    }
    return 0;
}