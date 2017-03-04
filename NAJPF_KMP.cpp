/* user :saurabh3240
    problem:  NAJPF
    date: 04-03-2016
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
#define limit 1000006


char haystack[1000005];
ll hashed[1000005];
ll prime =	31;
ll power[1000005];
char needle[1000005];
ll hashed_needle;

bool OK(int i)
{
	int j = 0;
	int m = strlen(needle);
	while(j<m)
	{
		if(needle[j]!=haystack[i])
		{
				return false;
		}
		j++;
		i++;
	}
	return true; 
}

vector<int>  kmpPrefix(string pattern) 
{	 // p is pattern string;
	//  http://www.inf.fh-flensburg.de/lang/algorithmen/pattern/kmpen.htm
	int size = pattern.size();
	vector<int> prefix(size+1,0);
	int i=0,j=-1;
	prefix[i]=j;
	while(i<size)
	{
		
		while(j>=0&&pattern[i]!=pattern[j])
			j = prefix[j];
	 	i++;
		j++;
		prefix[i] = j;
	}
	return prefix;
}

vector<int>  kmpSearch(string pattern,string text,vector<int> prefix)
{
	vector<int> ans;
	int n = text.size();
	int m = pattern.size();
	int i=0;
	int j=0;
	while(i<n)
	{
		while(j>=0&&text[i]!=pattern[j])
		{
			j = prefix[j];
		}
		if(j==m-1)
			ans.pb(i-j+1);
		//	cout<<i<<" "<<j+1<<endl;   
		// be carefull length of prefix matched up to  i  prefix start at  i-j .										
		//  p = aba 	t = abcabax
		// this will print      1201230  
		// tell the legth of the prefix match up to i which is at position i-j;
///          matched at 2003000				
		i++;
		j++;
		if(j==m)
		{
			//pin(i-j);  // if found  
			j = prefix[j];
		}
	}
	return ans;
			
}


int main()
{	
	int t;
	gi(t);
	
	
	while(t--)
	{
		string n,h;
		cin>>h>>n;		
		vector<int> prefix = kmpPrefix(n);
		vector<int> ans=	kmpSearch(n,h,prefix);
		if(ans.size()==0)
		{
			printf("Not Found\n\n");
		}
		else
		{
			pin(ans.size());
			rep(j,ans.size())
			{
				pis(ans[j]);	
			}	
			printf("\n\n");
		}
	
	}
		
}



