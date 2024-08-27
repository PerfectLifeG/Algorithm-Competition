#include<bits\stdc++.h>
using namespace std;
int main()
{
    string s1("666");
    s1.insert(1,"555");
    cout<<s1;
    cout<<endl; 
    s1.erase(1,3);
    cout<<s1;
    return 0;
}