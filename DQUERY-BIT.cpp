    #include <bits/stdc++.h>
    #include <cstdio>
    #include <cstring>
    #include <cmath>
    #include <cstring>
    #include <chrono>
    #include <complex>
    #define endl "\n"
    #define ll long long int
    #define vi vector<int>
    #define vll vector<ll>
    #define vvi vector < vi >
    #define pii pair<int,int>
    #define pll pair<long long, long long>
    #define mod 1000000007
    #define limit 100005
    #define inf 1000000000000000001;
    #define all(c) c.begin(),c.end()
    #define mp(x,y) make_pair(x,y)
    #define mem(a,val) memset(a,val,sizeof(a))
    #define eb emplace_back
    #define forup(i,a,b) for(int i=a; i<b; ++i)
    #define fordn(i,a,b) for(int i=a; i>b; --i)
    #define rep(i,a) for(int i=0; i<a; ++i)
    #define dforup(i,a,b) for(i=a; i<b; ++i)
    #define dfordn(i,a,b) for(i=a; i>b; --i)
    #define drep(i,a) for(i=0; i<a; ++i)
    #define gi(x) fastRead_int(x)
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
    #define pb push_back
    using namespace std;

    inline void fastRead_int(int &x) {
        register int c = getchar();
        x = 0;
        int neg = 0;

        for(; ((c<48 || c>57) && c != '-'); c = getchar());

        if(c=='-') {
            neg = 1;
            c = getchar();
        }

        for(; c>47 && c<58 ; c = getchar()) {
            x = (x<<1) + (x<<3) + c - 48;
        }

        if(neg)
            x = -x;
    }


    // We will represent each query as three numbers: L, R, idx. Idx is
    // the position (in original order) of this query.

    struct query{
        int l,r,i;
    };
    struct query queries[200002];
    int answers[200002];
    int a[30003];
    // Essential part of Mo's algorithm: comparator, which we will
    // use with std::sort. It is a function, which must return True
    // if query x must come earlier than query y, and False otherwise.
    inline bool mo_cmp(struct query &x,struct query &y)
    {
        return x.r < y.r;
    }



    #define LOGSZ 20  //2^17

    int tree[(1<<LOGSZ)+1];
    int N ,Q;
    int p[1000005];
    // add v to value at x
    void update(int x, int v) {
      while(x <= N) {
        tree[x] += v;
        x += (x & -x);
      }
    }

    // get cumulative sum up to and including x
    int get(int x) {
      ll res = 0;
      while(x) {
        res += tree[x];
        x -= (x & -x);
      }
      return res;
    }



    int main()
    {
        rep(i,1000005)
            p[i]=-1;

        gi(N);
        //BLOCK_SIZE = static_cast<int>(sqrt(N));

        for(int i = 1; i <=N; i++)
            gi(a[i]);

        gi(Q);
        queries[0].r=-1;
        queries[0].l=-1;
        queries[0].i=0;
        for(int i = 1; i <=Q; i++) {
            int x,y;
            gi(x);
            gi(y);
            queries[i].l = x;
            queries[i].r = y;
            queries[i].i = i;
        }

        // Sort queries using Mo's special comparator we defined.
        sort(queries, queries + Q+1, mo_cmp);

        int x = 1;
        for(int i = 1 ;i <=N; i++) {

            if(p[a[i]]!=-1)
                update(p[a[i]],-1);

            p[a[i]]=i;
            update(i,1);

            while(queries[x].r==i&& x<=Q)
            {
                int xx = get(queries[x].r)-get(queries[x].l-1);

                answers[queries[x].i] =xx;
                x++;
            }
        }

        // We output answers *after* we process all queries.
         for(int i = 1; i <=Q; i++)
             pin(answers[i]);
        return 0;
    }
