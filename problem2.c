#include<stdio.h>
typedef long long ll;

//program to find the nth fibonacci number recusivley and iteratively

//fibonacci number function by recursion
ll fib_by_recursion(ll n) {
	if(n <= 1)
		return n;
	else
		return fib_by_recursion(n - 1) + fib_by_recursion(n - 2);
}

//fibonacci number function by iteration
ll fib_by_iteration(ll n) {
	if(n == 0)
		return 0;
	
	ll l = 0, h = 1, x = 1;
	for(ll i = 1; i < n; i++)
	{
		x = l + h;
		l = h;
		h = x;
	}
	return x;
}


int main() {
	ll n;
	printf("Enter the number :- ");
	scanf("%lld", &n);
	
	//int val1 = fib_by_recursion(n);
	ll val2 = fib_by_iteration(n);
	
	//printf("The value generated by recursion :- %d\n", val1);
	printf("The value generated by iteration :- %lld\n", val2);
	return 0;
}