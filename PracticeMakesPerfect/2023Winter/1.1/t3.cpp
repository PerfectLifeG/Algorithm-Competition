#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int main(){
    int a,b;
    cin>>a>>b;
    printf("Age: %d\nHealthy Index: %d\n",a,b);
    if(a>=1&&a<60&&b>=0&&b<30||a>=60&&a<80&&b>=0&&b<50||a>=80&&a<200&&b>=0&&b<60)printf("Red Alert!!");
    else if(a>=1&&a<60&&b>=30&&b<60||a>=60&&a<80&&b>=50&&b<70||a>=80&&a<200&&b>=60&&b<75)printf("Yellow Alert!");
    else if(a>=1&&a<60&&b>=60&&b<=100||a>=60&&a<80&&b>=70&&b<=100||a>=80&&a<200&&b>=75&&b<=100)printf("Green ^_^");
    return 0;
}