/* user :saurabh3240
    contest : 101 Hack Jun 2015
    problem:  A
    platform :hackerrank
    date: 22-06-2015
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

int main()
{	
	int t;
	gi(t);
	while(t--)
	{
		int n,k;
		gi(n);
		gi(k);
		k--;
		ll arr[n];
		
		rep(i,n)
		{
		    cin>>arr[i];
		}		
	       	sort(arr,arr+n);
		if(k==1)
		{
			pln(arr[n-1]-arr[0]);
			continue;
		}
		ll summ[n];
		ll high = 0;
		for(int i=1;i<n;i++)
		{
		 	summ[i-1]= arr[i]-(ll)arr[i-1];
			high+=summ[i-1];	
		}	
		ll low = summ[0];
		ll ans =0;
		ll mid;
		while(low<high)
		{ 	
			mid = low +(high-low)/2;
			ll cows =1,dist = 0;
	
			for(int i=0;i<n-1;i++)
			{
				if(dist+summ[i]<=mid){
					dist+=summ[i];
				  
				}
				else
				{
					
					cows++;
					dist= summ[i];
				}        
			
			}
			if(cows<=k)
				high = mid;
			else
				low = mid+1;		
	       				
		//	cout<<mid<<endl;
		}
               	ll x = 1e12;
		ll dist =0;
		for(int i=0;i<n-1;i++)
		{
			if(dist+summ[i]<=mid){
				dist+=summ[i];
				  
			}
			else
			{	
				x = min(x,dist);			
				dist= summ[i];
			}        
			
		}
		x = min(x,dist);			
		
		pln(x);
		
	}             
}

