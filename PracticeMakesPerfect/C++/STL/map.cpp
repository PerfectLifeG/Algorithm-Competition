#include<bits/stdc++.h>
using namespace std; 
int main(){
    string str;
    cin>>str;
    map<char,int>m;
    map<char,int>::iterator iter;
    for (int i = 0; i < str.length(); i++)
    {
        iter=m.find(str[i]);//find会一直遍历到末尾
        if(iter!=m.end()) m[str[i]]++;//iter->second++;//找到val+1
        else m.insert(pair<char,int>(str[i],1));//找不到就插入
    }
    for (iter=m.begin(); iter != m.end(); iter++)
    {
        cout<<'('<<iter->first<<','<<iter->second<<')'<<endl;
    }
    return 0;
}