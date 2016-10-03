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
#define MAXN 65536
#define MAXLG 17

char A[MAXN];
struct entry 
{
	int nr[2], p;
} L[MAXN];

int P[MAXLG][MAXN], N, i, stp, cnt;
int compare (const void *elem1, const void *elem2){
	int x = (*(struct entry*)elem1).nr[0] - (*(struct entry*)elem2).nr[0];
    if(x==0)
    {	return  (*(struct entry*)elem1).nr[1] - (*(struct entry*)elem2).nr[1];
    	
    }
    else
    	return x;
}
int cmp(struct entry a, struct entry b)
{
	return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1] ? 1 : 0) : (a.nr[0] < b.nr[0] ? 1 : 0);
}

void suffix()
{
	for (N = strlen(A), i = 0; i < N; i ++)
		P[0][i] = A[i] - 'a';
	for (stp = 1, cnt = 1; cnt >> 1 < N; stp ++, cnt <<= 1)
	{
		for (i = 0; i < N; i ++)	
		{	
			L[i].nr[0] = P[stp - 1][i];
			L[i].nr[1] = i + cnt < N ? P[stp - 1][i + cnt] : -1;
			L[i].p = i;
		}
		qsort(L, N, sizeof(struct entry),compare);
		for (i = 0; i < N; i ++)
			P[stp][L[i].p] = i > 0 && L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1] ? P[stp][L[i - 1].p] : i;
	}
}
int lcp(int x, int y)
{
	int k, ret = 0;
	if (x == y) return N - x;
	for (k = stp - 1; k >= 0 && x < N && y < N; k --)
	if (P[k][x] == P[k][y])
	x += 1 << k, y += 1 << k, ret += 1 << k;
	return ret;
}
int temp[50002];
int main()
{
	int t;
	gi(t);
	while(t--)
	{
		scanf("%s",A);
		suffix();
		int x =0;
		for(int i=0;A[i]!='\0';i++)
			x++;
		
		rep(i,x)
			temp[P[stp-1][i]]=i;
		int tt = 0;
		int n = x;
		for(int i=0;i<n-1;i++)
		{
			tt+=lcp(temp[i],temp[i+1]);
		}
		ll sz = x;
		sz  = sz*(sz+1);
		sz/=2;
		sz = sz-tt;
		pin(sz);
	}

}

