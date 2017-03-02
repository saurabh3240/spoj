
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
#include<unordered_map>
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
#define INF 1000000000
#define ull unsigned long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<double,int> PDI;

int main()
{
	while(true)
	{

	 int N,M ,s, t;
	 gi(N);
	 
	 if(N==0)
	 	break;
	 gi(M);
	 s  = 0;
	 t = N-1;
	  vector<vector<PDI> > edges(N);
	  rep(i,M)
	  {	
	  	int u,v;
	  	double p;
	  	gi(u);
	  	gi(v);
	  	cin>>p;
	  	p/=100.0f;
	  	edges[u-1].pb(make_pair(p,v-1));
		edges[v-1].pb(make_pair(p,u-1));


	  }

	  
	  // use priority queue in which top element has the "smallest" priority
	  priority_queue<PDI, vector<PDI>, less<PDI> > Q;
	  vector<double> dist(N, -1.0f);
	 // vector<int> dad(N, -1);
	  Q.push (make_pair (1.0f, s));
	  dist[s] = 1.0;
	  
	  while (!Q.empty())
	  {
	    PDI p = Q.top();
	    //cout<<p.fs<<" "<<p.sc<<endl;
	    if (p.sc == t) 
	    	break;
	    Q.pop();
	    int here = p.sc;
	    for (vector<PDI>::iterator it=edges[here].begin(); it!=edges[here].end(); it++)
	    {
	      if (dist[here] * it->first > dist[it->second]){
	        dist[it->second] = dist[here] * it->first;
	   //     dad[it->second] = here;
	        Q.push (make_pair (dist[it->second], it->second));
	      }
	    }
	  }
	  double ans = dist[t]*100.0;
	  printf ("%.6f percent\n", ans);
	  //if (dist[t] < INF)
	    //for(int i=t;i!=-1;i=dad[i])
	      //printf ("%d%c", i, (i==s?'\n':' '));
	    

	}


  return 0;
}
 

