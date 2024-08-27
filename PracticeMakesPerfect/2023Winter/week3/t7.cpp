#include<bits/stdc++.h>
using namespace std;
map<char,int>mp;
set<char>s;
int main(){
    string a,b;
    getline(cin,a);
    getline(cin,b);
    for(int i=0;i<a.size();i++){
        if(a[i]==':'){
            if(a[i-1]!='\"'){
                int sum=0;int j=1;
                while(a[i+j]!=','&&a[i+j]!='}'){
                    sum=sum*10+a[i+j]-'0';
                    j++;
                }
                mp[a[i-1]-'0']+=sum;
                
                s.insert(a[i-1]-'0');
            }
            else{
                int sum=0;int j=1;
                while(a[i+j]!=','&&a[i+j]!='}'){
                    sum=sum*10+a[i+j]-'0';
                    j++;
                }
                mp[a[i-2]]+=sum;
                s.insert(a[i-2]);
            }
        }
    }
    for(int i=0;i<b.size();i++){
        if(b[i]==':'){
            if(b[i-1]!='\"'){
                int sum=0;int j=1;
                while(b[i+j]!=','&&b[i+j]!='}'){
                    sum=sum*10+b[i+j]-'0';
                    j++;
                }
                mp[b[i-1]-'0']+=sum;
                s.insert(b[i-1]-'0');
            }
            else{
                int sum=0;int j=1;
                while(b[i+j]!=','&&b[i+j]!='}'){
                    sum=sum*10+b[i+j]-'0';
                    j++;
                }
                mp[b[i-2]]+=sum;
                s.insert(b[i-2]);
            }
        }
    }
    printf("{");
    auto it=s.begin();
    if(*it<=9&&*it>=0)printf("%d:%d",*it,mp[*it]);
    else printf("\"%c\":%d",*it,mp[*it]);
    it++;
    for(;it!=s.end();it++){
        if(*it<=9&&*it>=0)printf(",%d:%d",*it,mp[*it]);
        else printf(",\"%c\":%d",*it,mp[*it]);
    }
    printf("}");
    return 0;
}