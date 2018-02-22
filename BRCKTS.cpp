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


// Classic Segment Tree

int a[50005];
struct node
{
    int left;
    int right;
};
struct node s[4*50005];
string str;
int n;
void build(int id = 1,int l = 0,int r = n)         //root index 1,children 2x,2x+1
{						   // root = [0,n)
	if( l+1 == r )
	{
        if(str[l]=='(')
        {
            s[id].left =1;
            s[id].right=0;
        }
        else
        {
            s[id].left =0;
            s[id].right=1;
        }
        return;				// comes from array
	}

	ll mid = l + (r-l)/2;
	build( id*2, l, mid);			// interval = [left,right)
	build( id*2+1, mid, r);

    int li = id*2;
    int ri = id*2+1;

    s[id].left = s[li].left+s[ri].left;
    s[id].right = s[li].right+s[ri].right;
    if(s[li].left>0 && s[ri].right>0)
    {
        int z = min(s[li].left,s[ri].right);
        s[id].left-=z;
        s[id].right-=z;
    }				// comes from child nodes
}
void modify(int p, int id=1, int l=0, int r=n)    // call modify(p,x)
{
				    //x is the value to which a[p] is changed
	if( l+1 == r){
        			// l=r-1=p
	   if(str[p]=='(')                 // change the value in the array
       {
           str[p]=')';
           s[id].left =0;
           s[id].right=1;
       }
       else
       {
           str[p]='(';
           s[id].left =1;
           s[id].right=0;

       }
	   return;
	}
	ll mid = l + (r-l)/2;

	if( p < mid )
	{
	   modify(p, id*2, l, mid);
	}
	else
	{
	   modify(p, id*2+1, mid, r);
	}

    int li = id*2;
    int ri = id*2+1;
    s[id].left = s[li].left+s[ri].left;
    s[id].right = s[li].right+s[ri].right;
    if(s[li].left>0 && s[ri].right>0)
    {
        int z = min(s[li].left,s[ri].right);
        s[id].left-=z;
        s[id].right-=z;
    }				// comes from child nodes

}
// struct node query(int x,int y,int id=1,int l=0,int r=n){		//verify return type
// 							// call query(l,r)
//     struct node zero;
//     zero = {-MOD,-MOD,0,-MOD};
//     // cout<<x<<" "<<y<<"-"<<id<<"-"<<l<<"-"<<r<<endl;
// 	if( x >= r or l >= y )  return zero;	// no overlap
// 	if( x <= l and r <= y )  return s[id];      // complete overlap
// 	ll mid = l + (r-l)/2;			  // partial overlap
//     struct node n1,n2,n3;
//     n1 = query(x, y, id*2, l, mid) ;
//     n2 = query(x, y, id*2+1, mid, r);
//
//     n3.pre= max(n1.total+n2.pre,n1.pre);
// 	n3.total= n1.total + n2.total;	// put values in non-leaf nodes
//     n3.suff= max(n2.total+n1.suff,n2.suff);
//     n3.mx =  max(  max(n1.mx, n2.mx),n1.suff+ n2.pre  );
// 	return n3;
// }
// void print_node(struct node n)
// {
//     cout<<n.pre<<" "<<n.mx<<" "<<n.total<<" "<<n.suff<<endl;
// }
int main()
{
    int t;
    t=0;
    while(gi(n))
    {
        printf("Test %d:\n",++t);
    	cin>>str;
        build();

        int q;
    	gi(q);
    	int x,y;

    	while(q--)
    	{
            int x;
            gi(x);
            if(x==0)
            {   if(n%2==1)
                {
                    printf("NO\n");
                }
                else if(s[1].left==0 && s[1].right==0)
                {
                    printf("YES\n");
                }
                else
                    printf("NO\n");
            }
            else
            {
                modify(x-1);
            }
        //    cout<<str<<endl;

    	}
    }
}
