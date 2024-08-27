#include<bits\stdc++.h>
using namespace std;
int main()
{
    //定义大容器
    vector<vector<int>> v;
    //小容器
    vector<int>v1;
    vector<int>v2;
    vector<int>v3;
    vector<int>v4;
    for ( int i=0; i < 4; i++)
    {
        v1.push_back(i+1);
        v2.push_back(i+2);
        v3.push_back(i+3);
        v4.push_back(i+4);
    }   
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    for ( vector<vector<int>>::iterator it=v.begin(); it !=v.end(); it++)
    {
        for ( vector<int>::iterator ite = (*it).begin(); ite !=(*it).end(); ite++)
        {
            cout<< *ite<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}