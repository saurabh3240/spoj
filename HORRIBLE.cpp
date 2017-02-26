/* user :saurabh3240
    contest : practice
    problem:  A
    platform :spoj
    date: 25-02-2017
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

#define INF 1000000000
#define MAX 400005
#define ull unsigned long long
// Ideally, we should not use global variables and large
// constant-sized arrays, we have done it here for simplicity.
ll tree[MAX] = {0ll};  // To store segment tree
ll lazy[MAX]={0ll};
ll arr[100005];
 
void updateRangeUtil(int si, int ss, int se, int us,
                     int ue, ll diff)
{
					 
    int ind1 = (si<<1)+1;
    int  ind2 = (si<<1)+2;
          
    if (lazy[si] != 0ll)
    {
        // Make pending updates using value stored in lazy
        // nodes
        ll A = lazy[si];
        tree[si] = tree[si]+ ((se-ss+1)*A) ;
        
 
        // checking if it is not leaf node because if
        // it is leaf node then we cannot go further
        if (ss != se)
        {
            // We can postpone updating children we don't
            // need their new values now.
            // Since we are not yet updating children of si,
            // we need to set lazy flags for the children
            
            lazy[ind1]+=A;
 
 
    		lazy[ind2]+=A;
            
        }
 
        // Set the lazy value for current node as 0 as it
        // has been updated
        lazy[si] = 0ll;
    }
 
    // out of range
    if (ss>se || ss>ue || se<us)
        return ;
 
    // Current segment is fully in range
    if (ss>=us && se<=ue)
    {
       // cout<<"overlapped"<<endl;
        // Add the difference to current node
        {   // adddition only;
            tree[si] += (se-ss+1)*diff;
            if (ss != se)
            {
                // This is where we store values in lazy nodes,
                // rather than updating the segment tree itelf
                // Since we don't need these updated values now
                // we postpone updates by storing values in lazy[]
                lazy[ind1]  += diff;
                
                lazy[ind2]  += diff;
            }
            return;
        }
        
    }
 
    // If not completely in rang, but overlaps, recur for
    // children,
    int mid = (ss+se)/2;
    updateRangeUtil(ind1, ss, mid, us, ue, diff);
    updateRangeUtil(ind2, mid+1, se, us, ue, diff);
    // And use the result of children calls to update this
    // node
    tree[si] = (tree[ind1] + tree[ind2]);
}
 
// Function to update a range of values in segment
// tree
/*  us and eu -> starting and ending indexes of update query
    ue  -> ending index of update query
    diff -> which we need to add in the range us to ue */
void updateRange(int n, int us, int ue, ll diff)
{
   updateRangeUtil(0, 0, n-1, us, ue, diff);
}
ll getSumUtil(int ss, int se, int qs, int qe, int si)
{
    int ind1 = (si<<1)+1;
    int  ind2 = (si<<1)+2;
       
    if (lazy[si] != 0ll)
    {
        // Make pending updates to this node. Note that this
        // node represents sum of elements in arr[ss..se] and
        // all these elements must be increased by lazy[si]
        ll A = lazy[si];
        tree[si] = tree[si]+ ((se-ss+1)*A) ;
        
 
        // checking if it is not leaf node because if
        // it is leaf node then we cannot go further
        if (ss != se)
        {
            // Since we are not yet updating children os si,
            // we need to set lazy values for the children
            
         
            lazy[ind1]+=A;
 
 
            
         
            lazy[ind2]+=A;
        }
 
        lazy[si] = 0ll;
    }
 
    // Out of range
    if (ss>se || ss>qe || se<qs)
        return 0ll;
 
    // At this point we are sure that pending lazy updates
    // are done for current node. So we can return value 
    // (same as it was for query in our previous post)
 
    // If this segment lies in range
    if (ss>=qs && se<=qe)
        return tree[si];
 
    // If a part of this segment overlaps with the given
    // range
    int mid = (ss + se)/2;
    return (getSumUtil(ss, mid, qs, qe, 2*si+1) +
           getSumUtil(mid+1, se, qs, qe, 2*si+2));
}
 
// Return sum of elements in range from index qs (quey
// start) to qe (query end).  It mainly uses getSumUtil()
ll getSum(int n, int qs, int qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
       // printf("Invalid Input");
        return 0ll;
    }
 
    return getSumUtil(0, n-1, qs, qe, 0);
}
 
// A recursive function that constructs Segment Tree for
//  array[ss..se]. si is index of current node in segment
// tree st.
void constructSTUtil(ll arr[], int ss, int se, int si)
{
    // out of range as ss can never be greater than se
    if (ss > se)
        return ;
 
    // If there is one element in array, store it in
    // current node of segment tree and return
    if (ss == se)
    {
        tree[si] = arr[ss];
        lazy[si]=0ll;
        return;
    }
 
    // If there are more than one elements, then recur
    // for left and right subtrees and store the sum
    // of values in this node
    int mid = (ss + se)/2;
    constructSTUtil(arr, ss, mid, si*2+1);
    constructSTUtil(arr, mid+1, se, si*2+2);
 
    tree[si] = (tree[si*2 + 1] + tree[si*2 + 2]);
}
 
/* Function to construct segment tree from given array.
   This function allocates memory for segment tree and
   calls constructSTUtil() to fill the allocated memory */
void constructST(ll arr[], int n)
{
    // Fill the allocated memory st
    constructSTUtil(arr, 0, n-1, 0);
}
 
void printtree()
{
    cout<<"tree-----------------------------"<<endl;
        
        rep(i,7)
            cout<<tree[i]<<" "; 
        cout<<"\n add"<<endl;
        rep(i,7)
            cout<<lazy[i]<<" ";
        cout<<"\n mul"<<endl;
        //rep(i,7)    
         //   cout<<mul[i]<<" ";
        cout<<endl; 
}
int main() {
    
	int t;
	gi(t);
while(t--)
{
	
	int n,Q;
    gi(n);
    gi(Q);
    for(int i = 0; i < n; i++) 
        arr[i]=0;
    rep(i,4*n+1)
    {
       	lazy[i]=0ll; 	
	}
    constructST(arr, n);
    
    
    //printtree();
    while(Q--)
    {
        int type;
        gi(type);
        if(type==0)
        {
            // range addition
    	//	cout<<"Addition"<<endl;
	        int x,y;
            ll v;
            
            gi(x);
            gi(y);
            gl(v);
            updateRange(n, x-1, y-1, v);// Increment range [0, 6] by 5
       // printtree();
        }
        else
        {
            int x,y;
            gi(x);
            gi(y);
            pln(getSum( n, x-1, y-1) );      
       // printtree();
        }        
    }
    
}
}


