#include<iostream>  
#include<windows.h>
using namespace std;  
int main()  
{  
    int t=1000;
    while(t)
    {  
        system("data.exe > data.txt");  
        system("ans.exe < data.txt > ans.txt");
        system("test.exe < data.txt > test.txt");
        if(system("fc test.txt ans.txt"))   break;        t--;
    }  
    if(t==0) cout<<"no error"<<endl;  
    else cout<<"error"<<endl;  

    return 0;  
}  