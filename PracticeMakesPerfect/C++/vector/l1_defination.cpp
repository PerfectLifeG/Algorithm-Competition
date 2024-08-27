#include<bits\stdc++.h>
using namespace std;

void print(int a){
    cout<<a<<endl;
}

int main()
{
    vector <int> v;    //链式数组
    v.push_back(10);
    v.push_back(10);
    //通过迭代器来访问
   // vector<int>::iterator itbegin=v.begin();//起始迭代器
   // vector<int>::iterator itend=v.end();//结束迭代器 指向最后的下一个

//遍历
    for (vector<int>::iterator itbegin=v.begin() ; itbegin != v.end(); itbegin++)
    {
        cout<< *itbegin<<endl;
    }

    for_each(v.begin(),v.end(),print);
    


    
    return 0;
}