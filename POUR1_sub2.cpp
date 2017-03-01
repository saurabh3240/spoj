/* user :saurabh3240
    contest : spoj practicee
    problem:  POUR1
    platform :spoj
    date: 28-02-2017
*/
 
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <string.h>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>
#include <cassert>
 
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
 
#define forup(i,a,b) for(int i=a; i<b; ++i)
#define fordn(i,a,b) for(int i=a; i>b; --i)
#define rep(i,a) for(int i=0; i<a; ++i)
 
#define dforup(i,a,b) for(i=a; i<b; ++i)
#define dfordn(i,a,b) for(i=a; i>b; --i)
#define drep(i,a) for(i=0; i<a; ++i)
 
#define slenn(s,n) for(n=0; s[n]!=13 and s[n]!=0; ++n);s[n]=0
 
#define gi(x) scanf("%d",&x)
#define gl(x) scanf("%lld",&x)
#define gd(x) scanf("%lf",&x)
#define gs(x) scanf("%s",x)
 
#define pis(x) printf("%d ",x)
#define pin(x) printf("%d\n",x)
#define pls(x) printf("%lld ",x)
#define pln(x) printf("%lld\n",x)
#define pds(x) printf("%.12f ",x)
#define pdn(x) printf("%.12f\n",x)
#define pnl() printf("\n")
 
#define fs first
#define sc second
#define ll long long
#define pb push_back
#define MOD 1000000007
#define limit 10000005

int readint()
    {
       int cc = getc(stdin);
       for (;cc < '0' || cc > '9';)  cc = getc(stdin);
       int ret = 0;
       for (;cc >= '0' && cc <= '9';)
       {
          ret = ret * 10 + cc - '0';
          cc = getc(stdin);
       }
      return ret;
   }


unsigned long long mod_pow(unsigned long long num, unsigned long long pow, unsigned long long mod)
{
    unsigned long long test;
    unsigned long long n = num;
    for(test = 1; pow; pow >>= 1)
    {
        if (pow & 1)
            test = ((test % mod) * (n % mod)) % mod;
        n = ((n % mod) * (n % mod)) % mod;
    }
    return test; /* note this is potentially lossy */
}

ll gcd(ll a,ll b)
{	ll r;
	while(b)
	{	r= a%b;
		a = b;
		b = r;
	}
	return a;
}
int xGCD(int a, int b, int &x, int &y) 
{
    if(b == 0) 
    {
       x = 1;
       y = 0;
       return a;
    }
    int x1, y1, gcd = xGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}
int cnt(int A, int B, int C) {
	int move = 1, a = A, b = 0, pour;
	while(a != C && b != C) {
		pour = min(a, B-b);
		b += pour;
		a -= pour;
		move++;
		if(a == C || b == C) break;
		if(b==B) b = 0, move++; 
		else if(a==0) a = A, move++;
	}
	return move;
}
int main()
{
	int t;
	gi(t);
	while(t--)
	{
		int a,b,c;
		gi(a);
		gi(b);
		gi(c);
		int x,y;
		//cout<<a<<" "<<b<<" "<<c<<endl;
		int gc = xGCD(a,b,x,y);

		//cout<<gc<<" "<<x<<" "<<y<<endl;
		if(c==0)
		{
			pin(0);
		}
		else if(c%gc!=0)
		{
			pin(-1);
		}
		else if(c>a && c>b)
		{
			pin(-1);
			
		}
		else if(c==a ||b==a)
			pin(1);
		else
		{
			// 
			int ans =0;
				//swap
				ans = min(cnt(b,a,c),cnt(a,b,c));
					pin(ans);
			
		}
	}
	
}
