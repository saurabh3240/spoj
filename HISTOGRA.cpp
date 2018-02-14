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
#define limit 100005

#define MOD 1000000007


using namespace std;

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
  while(true)
  {
    int n;
    gi(n);
    if(n==0)
      break;
    vector<int> v;
    rep(i,n)
    {
      int x;
      gi(x);
      v.pb(x);
    }
    // solve using stack

    int i =0;
    ll max_ans =0;
    stack<ll> st;
    while(i<n)
    {

//        int ts = st.top();

        if(st.empty()||v[st.top()]<=v[i])
        {
          st.push(i++);
        }
        else
        {
          // pop
          int ts = st.top();
          st.pop();
        //  int k = st.top();
          cout<<ts<<" "<<st.size()<<endl;
          ll temp = v[ts]*(st.empty()?i:i-st.top()-1);
          max_ans = max(temp,max_ans);
        }

    }
    while(st.size()!=0)
    {
      int ts = st.top();
      st.pop();
      cout<<ts<<" "<<st.size()<<endl;

      ll temp = v[ts]*(st.empty()?i:i-st.top()-1);
      max_ans = max(temp,max_ans);
    }
    pln(max_ans);
  }
}
