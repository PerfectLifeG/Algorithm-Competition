#include<bits/stdc++.h>
int main()
{
	const double eps = 1e-8;
	double x=1515; //用于比较的目标值
	double left = 0,right=10000;
	//注意，这里当相差的差值大于eps时视为不相等
	while(right-left>eps){
		double mid = (left+right)/2;
		if(x<mid){
		  	right=mid;
		}else{
			left=mid;
		}
	}	
	printf("%lf",left);
}
