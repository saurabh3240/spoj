/* user :saurabh3240
	contest : spoj
	problem: ARITH2
	date: 4-6-2014
*/

#include <vector>
#include <list>
#include <map>
#include <set>
#include <string.h>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
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
#define pln(x) printf("%d\n",x)
#define pds(x) printf("%.12f ",x)
#define pdn(x) printf("%.12f\n",x)
#define pnl() printf("\n")
#define fs first
#define sc second 
#define pb push_back

int main()
{	int t;
	gi(t);
	char s[20];
	long long int ans;
	while(t--)
	{	ans=0;
		scanf("%s",s);
		ans = atoll(s);
		scanf("%s",s);
		char op;
		while(s[0]!='=')
		{	op = s[0];
			scanf("%s",s);
			switch(op)
			{
				case '+':	ans+=atoll(s);
							break;
				case '-':	ans-=atoll(s);
							break;
				case '*':	ans*=atoll(s);
							break;
				case '/':	ans/=atoll(s);
							break;
				case '%':	ans+=atoll(s);
							break;
			}
		}
		printf("%lld\n",ans);
	}
}