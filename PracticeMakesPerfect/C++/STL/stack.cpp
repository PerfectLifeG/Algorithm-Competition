#include <bits/stdc++.h>
using namespace std;
int main(){
    stack<int>s;
    for (int i = 0; i < 5; i++)
    {
        s.push(i);
        if(!s.empty()&&i==1){
            printf("栈非空\n");
        }
    }
        printf("%d ",s.size());
        printf("%d ",s.top());
    for (int i = 0; i < 5; i++)
    {
        s.pop();
    }
        printf("%s",s.top());
        if(s.empty()){
            printf("栈为空\n");
        }
    return 0;
}