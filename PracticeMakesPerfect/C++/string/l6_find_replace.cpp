#include<bits\stdc++.h>
using namespace std;
int main()
{
    string s1;
    s1="I love yuanjingwen";
    if(s1.find("jingwen")!=-1){
        cout<<s1.find("jingwen")<<endl;//rfind从右往前找  返回的也是下标
    }else cout<<"not find408"<<endl;

    if(s1.find("jw",5,2)!=-1){
        cout<<s1.find("jingwen")<<endl;//rfind从右往前找  返回的也是下标
    }else cout<<"not find408"<<endl;

    string s2;
    s1.replace(11,7,"JW");
    cout<<s1;
    return 0;
}