#include<bits\stdc++.h>
using namespace std;
class person
{
public:
    person(string name,int age){
        this->m_name=name;
        this->m_age=age;
    }
    string m_name;
    int m_age;
};

int main()
{
    vector<person*>v; 
    person p1("gepenglin",18);
    person p2("yuanjingwen",19);
    //向容器中添加数据
    v.push_back(&p1);
    v.push_back(&p2);
    //遍历
    for(vector<person*>::iterator it=v.begin();it!=v.end();it++)
    {
        cin>>(*it)->m_age>>(*it)->m_name;
    }
    for(vector<person*>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<"姓名 ： "<< (*it)->m_name <<" 年龄 ： "<<(*it)->m_age<<endl;
    }
    return 0;
}