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
    int arr[30003];
    int p[1000005];
    // Essential part of Mo's algorithm: comparator, which we will
    // use with std::sort. It is a function, which must return True
    // if query x must come earlier than query y, and False otherwise.
    inline bool mo_cmp(struct query &x,struct query &y)
    {
        return x.r < y.r;
    }
    int a[50005];
    int N,Q,n;

    int getMid(int s, int e) {  return s + (e -s)/2;  }


    int getSumUtil(int *st, int ss, int se, int qs, int qe, int si)
    {
        // If segment of this node is a part of given range, then return
        // the sum of the segment
        if (qs <= ss && qe >= se)
            return st[si];

        // If segment of this node is outside the given range
        if (se < qs || ss > qe)
            return 0;

        // If a part of this segment overlaps with the given range
        int mid = getMid(ss, se);
        return getSumUtil(st, ss, mid, qs, qe, 2*si+1) +
               getSumUtil(st, mid+1, se, qs, qe, 2*si+2);
    }

    /* A recursive function to update the nodes which have the given
       index in their range. The following are parameters
        st, si, ss and se are same as getSumUtil()
        i    --> index of the element to be updated. This index is
                 in input array.
       diff --> Value to be added to all nodes which have i in range */
    void updateValueUtil(int *st, int ss, int se, int i, int diff, int si)
    {
        // Base Case: If the input index lies outside the range of
        // this segment
        if (i < ss || i > se)
            return;

        // If the input index is in range of this node, then update
        // the value of the node and its children
        st[si] = st[si] + diff;
        if (se != ss)
        {
            int mid = getMid(ss, se);
            updateValueUtil(st, ss, mid, i, diff, 2*si + 1);
            updateValueUtil(st, mid+1, se, i, diff, 2*si + 2);
        }
    }

    // The function to update a value in input array and segment tree.
    // It uses updateValueUtil() to update the value in segment tree
    void updateValue(int arr[], int *st, int n, int i, int diff)
    {
        // Check for erroneous input index
        if (i < 0 || i > n-1)
        {
            printf("Invalid Input");
            return;
        }

        // Get the difference between new value and old value

        // Update the value in array
        arr[i] += diff;

        // Update the values of nodes in segment tree
        updateValueUtil(st, 0, n-1, i, diff, 0);
    }

    // Return sum of elements in range from index qs (quey start)
    // to qe (query end).  It mainly uses getSumUtil()
    int getSum(int *st, int n, int qs, int qe)
    {
        // Check for erroneous input values
        if (qs < 0 || qe > n-1 || qs > qe)
        {
            printf("Invalid Input");
            return -1;
        }

        return getSumUtil(st, 0, n-1, qs, qe, 0);
    }

    // A recursive function that constructs Segment Tree for array[ss..se].
    // si is index of current node in segment tree st
    int constructSTUtil(int arr[], int ss, int se, int *st, int si)
    {
        // If there is one element in array, store it in current node of
        // segment tree and return
        if (ss == se)
        {
            st[si] = arr[ss];
            return arr[ss];
        }

        // If there are more than one elements, then recur for left and
        // right subtrees and store the sum of values in this node
        int mid = getMid(ss, se);
        st[si] =  constructSTUtil(arr, ss, mid, st, si*2+1) +
                  constructSTUtil(arr, mid+1, se, st, si*2+2);
        return st[si];
    }

    /* Function to construct segment tree from given array. This function
       allocates memory for segment tree and calls constructSTUtil() to
       fill the allocated memory */
    int *constructST(int arr[], int n)
    {
        // Allocate memory for segment tree

        //Height of segment tree
        int x = (int)(ceil(log2(n)));

        //Maximum size of segment tree
        int max_size = 2*(int)pow(2, x) - 1;

        // Allocate memory
        int *st = new int[max_size];

        // Fill the allocated memory st
        constructSTUtil(arr, 0, n-1, st, 0);

        // Return the constructed segment tree
        return st;
    }

    int main()
    {
        rep(i,1000005)
        {    p[i]=-1;
        }
        gi(N);
        n = N+1;
        //BLOCK_SIZE = static_cast<int>(sqrt(N));

        for(int i = 1; i <=N; i++)
            gi(arr[i]);

        int *st = constructST(a, n);
        // buld segment tree;
        gi(Q);
        queries[0].r=0;
        queries[0].l=0;
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

            // rep(j,16)
            // {
            //     cout<<st[j]<<" ";
            // }
            // cout<<endl;
            if(p[arr[i]]!=-1)
                updateValue(arr,st,n,p[arr[i]],-1);
            p[arr[i]]=i;
            updateValue(a,st,n,i,1);

            while(queries[x].r==i&& x<=Q)
            {
                int xx = getSum(st,n,queries[x].l,queries[x].r);

                answers[queries[x].i] =xx;
                x++;
            }
        }

        // We output answers *after* we process all queries.
         for(int i = 1; i <=Q; i++)
             pin(answers[i]);
        return 0;
    }
