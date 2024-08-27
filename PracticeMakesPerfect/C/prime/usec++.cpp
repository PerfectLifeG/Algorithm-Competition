#include<iostream>
using namespace std;
#define ll long long

void f(ll n)
{	
	ll i = 0;
	ll a = 0;			//底数 
	ll p = 0;			//幂 
	for(i = 2;i * i <= n;i++)	//从小到大枚举，找出一个可分解的质因数
	{
		while(n % i == 0)	//算该质因数幂的过程
		{
			a = i;
			p++;
			n /= i;
		}
		if(p != 0)			//一旦找到就跳出
			break;
	}
	if(p != 0)
	{
		if(n != 1)			//边界在后面 ， n == 1 就不继续调用了 
		{
			if(p != 1)
				cout << a << "^" << p << "*";
			else
				cout << a << "*";
			f(n);			//n已经自我除掉了一部分，递归打印剩余部分就可以 	
		}
		else				//n == 1
		{
			if(p != 1)
				cout << a << "^" << p;		//直接输出就行了
			else
				cout << a;
		}				
	} 
	else		//如果找不到质因数来分解，直接输出自己 
	{
		cout << n;
	}
}

int main()
{
	ll n;
	cin >> n;
	cout << n << "=";
	f(n);
	return 0;
}
