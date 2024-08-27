#include<bits/stdc++.h>
using namespace std;
const int N=110;
int main(){
    int t;cin>>t;
    while(t--){
        char s[N];
        scanf("%s",s);
        int len=strlen(s);
        if(s[0]=='a'&&s[len-1]=='a'||s[0]=='b'&&s[len-1]=='b'){
            printf("%c ",s[0]);
            char c=s[len-1];s[len-1]='\0';
            printf("%s ",&s[1]);
            printf("%c\n",c);
        }else if(s[0]=='a'&&s[len-1]=='b'){
            if(s[1]=='b'){
                printf("%c ",s[0]);
                char c=s[len-1];s[len-1]='\0';
                printf("%s ",&s[1]);
                printf("%c\n",c);
            }else{
                printf("%c ",s[0]);                
                printf("%c ",s[1]);
                printf("%s\n",&s[2]);
            }
        }else if(s[0]=='b'&&s[len-1]=='a'){
            printf("%c ",s[0]);                
            printf("%c ",s[1]);
            printf("%s\n",&s[2]);
        }
    }
    return 0;
}