

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


// Classic Segment Tree

int a[50005];
struct node
{
    int pre;
    int mx;
    int total;
    int suff;
};
struct node s[4*50005];
int n;
void build(int id = 1,int l = 0,int r = n)         //root index 1,children 2x,2x+1
{						   // root = [0,n)
	if( l+1 == r )
	{
	    s[id].pre = a[l];			// put values in leaf nodes
        s[id].mx = a[l];			// put values in leaf nodes
        s[id].total = a[l];			// put values in leaf nodes
        s[id].suff = a[l];			// put values in leaf nodes

        return;				// comes from array
	}

	ll mid = l + (r-l)/2;
	build( id*2, l, mid);			// interval = [left,right)
	build( id*2+1, mid, r);

    s[id].pre= max(s[id * 2].total+s[id*2+1].pre,s[id*2].pre);
	s[id].total= s[id * 2].total + s[id * 2 + 1].total;	// put values in non-leaf nodes
    s[id].suff= max(s[id * 2+1].total+s[id*2].suff,s[id*2+1].suff);

    s[id].mx = max(max(s[id*2].mx, s[id*2+1].mx),s[id*2].suff+ s[id*2+1].pre);
						// comes from child nodes
}
void modify(int p, int x, int id=1, int l=0, int r=n)    // call modify(p,x)
{
				    //x is the value to which a[p] is changed
	//s[id] += x-a[p] ;  		// change the value of the segtree node
	if( l+1 == r)
    {			// l=r-1=p
	   a[p]=x;
       s[id].pre = a[p];			// put values in leaf nodes
       s[id].mx = a[p];			// put values in leaf nodes
       s[id].total = a[p];			// put values in leaf nodes
       s[id].suff = a[p];

                            // change the value in the array
	   return;
	}
	ll mid = l + (r-l)/2;

	if( p < mid )
	{
	   modify(p, x, id*2, l, mid);
	}
	else
	{
	   modify(p, x, id*2+1, mid, r);
	}

        s[id].pre= max(s[id * 2].total+s[id*2+1].pre,s[id*2].pre);
    	s[id].total= s[id * 2].total + s[id * 2 + 1].total;	// put values in non-leaf nodes
        s[id].suff= max(s[id * 2+1].total+s[id*2].suff,s[id*2+1].suff);

        s[id].mx = max(max(s[id*2].mx, s[id*2+1].mx),s[id*2].suff+ s[id*2+1].pre);

}
struct node query(int x,int y,int id=1,int l=0,int r=n){		//verify return type
							// call query(l,r)
    struct node zero;
    zero = {-MOD,-MOD,0,-MOD};
    // cout<<x<<" "<<y<<"-"<<id<<"-"<<l<<"-"<<r<<endl;
	if( x >= r or l >= y )  return zero;	// no overlap
	if( x <= l and r <= y )  return s[id];      // complete overlap
	ll mid = l + (r-l)/2;			  // partial overlap
    struct node n1,n2,n3;
    n1 = query(x, y, id*2, l, mid) ;
    n2 = query(x, y, id*2+1, mid, r);

    n3.pre= max(n1.total+n2.pre,n1.pre);
	n3.total= n1.total + n2.total;	// put values in non-leaf nodes
    n3.suff= max(n2.total+n1.suff,n2.suff);
    n3.mx =  max(  max(n1.mx, n2.mx),n1.suff+ n2.pre  );
	return n3;
}
void print_node(struct node n)
{
    cout<<n.pre<<" "<<n.mx<<" "<<n.total<<" "<<n.suff<<endl;
}
int main()
{
	gi(n);
	rep(i,n)
	{
		gi(a[i]);
	}
    build();
    // rep(i,n*2+1)
    // {
    //     print_node(s[i]);
    // }

	int q;
	gi(q);
	int x,y;

	while(q--)
	{	int o;
        gi(o);
        if(o==0)
        {
            gi(x);
            gi(y);
            modify(x-1,y);
        }
        else
        {
            gi(x);
    		gi(y);
            struct node n = query(x-1,y);
    		pin(n.mx);
        }


	}
}
