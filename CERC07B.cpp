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
struct node
{
	int index;
	int vote;
};

int compare (const void *elem1, const void *elem2){
	int x = (*(struct node*)elem1).vote - (*(struct node*)elem2).vote;
    if(x==0)
    {	int y = (*(struct node*)elem1).index - (*(struct node*)elem2).index;
    	return y;
	}
    else
    	return x;
}
int maxi=0;
int maxj =0;
int n,m;	
char s[20][20];
int arr[20][20];
int neigh[20][20];
void neighbour()
{
	forup(i,1,n+1)
	{
		forup(j,1,m+1)
		{	if(s[i][j]=='X')
				arr[i][j]=1;	
			else
				arr[i][j]=0;			
		}
	}
	forup(i,1,n+1)
	{
		forup(j,1,m+1)
		{
			neigh[i][j]=arr[i][j]+arr[i+1][j]+arr[i][j+1]+arr[i-1][j]+arr[i][j-1];
			if(neigh[maxi][maxj]< neigh[i][j])
			{
				maxi = i;
				maxj= j;
			}
		}
	}
//	change(maxi,maxj);
}
void flip(int i,int j)
{
	if(s[i][j]=='X')
		s[i][j]='.';
	else
		s[i][j]='X';
}
void change()
{
	//flip max
	//corner case
	neighbour();
	if(maxi==1&&maxj==1)
	{	
		flip(maxi,maxj);
		flip(maxi+1,maxj);
		flip(maxi,maxj+1);		
	}	
	else if(maxi==1&&maxj==m)
	{	
		flip(maxi,maxj);
		flip(maxi,maxj-1);
		flip(maxi+1,maxj);		
	}
	else if(maxi==n&&maxj==1)
	{	
		flip(maxi,maxj);
		flip(maxi-1,maxj);
		flip(maxi,maxj+1);		
	}
	else if(maxi==n&&maxj==m)
	{	
		flip(maxi,maxj);
		flip(maxi-1,maxj);
		flip(maxi,maxj-1);		
	}
	else if(maxi==1)
	{	
		flip(maxi,maxj);
		flip(maxi+1,maxj);
		flip(maxi,maxj+1);		
		flip(maxi,maxj-1);
		
	}
	else if(maxi ==n)
	{	flip(maxi,maxj);
		flip(maxi-1,maxj);
		flip(maxi,maxj-1);		
		flip(maxi,maxj+1);
	}
	else if(maxj==1)
	{
		flip(maxi,maxj);
		flip(maxi+1,maxj);
		flip(maxi,maxj+1);		
		flip(maxi-1,maxj);
	}
	else if(maxj==m)
	{
		flip(maxi,maxj);
		flip(maxi-1,maxj);
		flip(maxi,maxj-1);		
		flip(maxi+1,maxj);
	}
	else
	{
		flip(maxi,maxj); //0 0
		flip(maxi-1,maxj); //-1 0
		flip(maxi,maxj-1);	//0 -1	
		flip(maxi+1,maxj); //1 0
		flip(maxi,maxj+1); //0 1
	}
	//
	forup(i,1,n+1)
	{
		cout<<s[i]+1<<endl;
	}
	change();
	int x;
	cin>>maxi>>maxj;
	
}

vector<int> v;
int main()
{
	cin>>n>>m;
	rep(i,n)
	{
		cin>>s[i+1]+1;	
	}
	change();
	//calculate neighbour count
}
