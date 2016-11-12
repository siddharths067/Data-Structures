#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0)
#define SLLD(x) scanf("%lld",&x);

#ifdef __MINGW32__||__MINGW64__
#define ll(x) scanf("%I64d",&x)
#define pll(x) printf("%I64d",x)
#else
#define ll(x) scanf("%lld",&x)
#define pll(x) printf("%lld
",x)
#endif

#define in(x) cin>>x
#define ins(x) cin>>x;cin.get();

#define all(X) X.begin(),X.end()
#define rall(X) X.rbegin(),X.rend()
#define FOR(a,n) for(long long int  a=0;a<n;a++)
#define FORI(a,b,c) for(long long int a=b;a<=c;a++)
#define FORD(a,b,c) for(long long int a=b;a>=c;a--)
#define ITER(a,b) for(auto &a : b)
#define INC(a,b,c,d) for(long long int a=b;a<=c;a+=d)
#define DEC(a,b,c,d) for(long long int a=b;a>=c;a-=d)

#define SORT(a) sort(all(a))
#define RSORT(a) sort(rall(a))
#define MP make_pair
#define PB push_back
#define PF push_front
#define DB pop_back
#define DF pop_front
#define cx first
#define cy second
#define MOD 1000000000+7
#define MADD(a,b) (a+b>=M):a+b-MOD?a+b
#define MDEC(a,b)  MADD(a-b,MOD)


using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lld;
/******** Math based Functions ******/
ll binpow(ll a, ll b, ll c)
{
    ll r =1 ;
    while (b)
    {
        if (b&1) r*=a;
        a*=a;
        r%=c;
        a%=c;
        b>>=1;
    }
    return r;
}

ll inverse(ll a, ll m)
{
    return binpow(a, m-2, m);
}
/*** Math Section Ends***/


int main()
{
     freopen("in6.txt","w",stdout);
     ll t = 10;
     cout<<10<<endl;
     while(t--){
          ll n = ((rand())%INT_MAX) + 23;
          cout<<n<<endl;
          for(ll i=0;i<n;i++)cout<< 1+rand()<<" ";
          cout<<endl;

          for(ll i=0;i<n;i++)cout<< 1+rand()<<" ";
          cout<<endl;
     }
    return 0;
}
