/* This Program Prints the largest prime factor of the given number
	Created By: Prateek Singhal

*/

#include<iostream>
#include<map>
#include<math.h>
#include<stdio.h>

#define prime(i) ((Prime[i>>5])&(1<<(i&(31))))
#define set(j) (Prime[j>>5]|=(1<<(j&(31))))
#define LIM 2000000
#define SLIM 12000
#define ll long long
using namespace std;
ll j,i=3,l;
ll Prime[10000000];
ll prime_nums[10000000];
ll count = 0;
void sieve()
{
	ll i, j, m, n, t,x,k,h;
	set(1);

	for(k=2,l=3,i=5; i<=SLIM; k++,i=3*k-(k&1)-1)
		if(prime(k)==0)
		{
			prime_nums[count++] = i;
			l++;

			for(j=i*i,h=((j+2)/3); j<=LIM; h+=(k&1)?(h&1?((k<<2)-3):((k<<1)-1)):(h&1?((k<<1)-1):((k<<2)-1)),j=3*h-(h&1)-1)
				set(h);
		}
	i=3*k-(k&1)-1;
	for(;(l<=10000000)&&(i<=LIM) ; k++,i=3*k-(k&1)-1)
		if(prime(k)==0)
		{
			prime_nums[count++] = i;
			l++;
		}
}

int main()
{
	prime_nums[count++] = 2;
	prime_nums[count++] = 3;
	sieve();
	ll n, i, p, x, t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		x = sqrt(n);
		i = 0;
		while(prime_nums[i] <= x)
		{
			if((n % prime_nums[i]) == 0)
			{
				n = n / prime_nums[i];
				x = sqrt(n);
			}
			else
				i++;
		}
		cout << n << endl;
	}
	return 0;
}

