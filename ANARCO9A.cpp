
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
#define limit 10000006

int get_ans(string s)
{
  int n = s.size();
  int l =0;
  int r =0;
  int ans =0;
  rep(i,n)
  {
    if(s[i]=='{')
    {
       if(r>0)
       {
         ans+=(r+1)/2;
         l+=(r%2);
         r = 0 ;
       }
       l++;
    }
    else
    {
      if(l>0)
      {
        l--;
      }
      else
      {
        r++;
      }
    }
  //  cout<<l<<" "<<r<<" "<<ans<<endl;
  }
  //cout<<l<<" "<<r<<endl;
  ans+= r/2;
  ans+= l/2;
  return ans;
}
int main()
{
	int t=1;
  while(1)
  {
    string s;
    cin>>s;
    if(s[0]=='-')
      break;
    cout<<t++<<". "<<get_ans(s)<<endl;
  }
}
