#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0)
#define SLLD(x) scanf("%lld",&x);

#ifdef __MINGW32__||__MINGW64__
#define ll(x) scanf("%I64d",&x)
#define pll(x) printf("%I64d",x)
#else
#define ll(x) scanf("%lld",&x)
#define pll(x) printf("%lld",x)
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
class prio{
     public :
     bool operator()(const pair<ll,ll> u, const pair<ll,ll> v){
          return u.cy > v.cy;
     }
};
priority_queue<pair<ll,ll> ,vector<pair<ll,ll> >,prio> Q1,Q2,Q3;
map<ll,vector<pair<ll,ll> > > _E;
ll dist1[100000],dist2[100000],dist3[100000];

int main()
{
     FIO;
     ll t;
     cin>>t;
     while(t--){
          _E.clear();
          ll n,m;
          cin>>n>>m;
          ll s,v,t;
          cin>>s>>t>>v;
          s--,t--,v--;
          for(ll i=0;i<m;i++){
               ll _u,_v,_w;
               cin>>_u>>_v>>_w;
               _u--,_v--;
               _E[_u].PB(MP(_v,_w));

               _E[_v].PB(MP(_u,_w));

          }
          for(ll i=0;i<n;i++)dist1[i] = dist2[i] = dist3[i] = INT_MAX;
          dist1[s] = 0;
          Q1.push(MP(s,0));
          while(!Q1.empty()){

               ll U = Q1.top().cx;
               ll W = Q1.top().cy;
               Q1.pop();
               for( auto z  : _E[U])
                    if(z.cy + W < dist1[z.cx]) dist1[z.cx] = z.cy + W,Q1.push(MP(z.cx,dist1[z.cx]));

          }

          Q2.push(MP(v,0));
          dist2[v] = 0;
          while(!Q2.empty()){

               ll U = Q2.top().cx;
               ll W = Q2.top().cy;
               Q2.pop();
               for( auto z  : _E[U])
                    if(z.cy + W < dist2[z.cx]) dist2[z.cx] = z.cy + W,Q2.push(MP(z.cx,dist2[z.cx]));


          }

          Q3.push(MP(t,0));
          dist3[t] = 0;
          while(!Q3.empty()){

               ll U = Q3.top().cx;
               ll W = Q3.top().cy;
               Q3.pop();
               for( auto z  : _E[U])
                    if(z.cy + W < dist3[z.cx]) dist3[z.cx] = z.cy + W,Q3.push(MP(z.cx,dist3[z.cx]));


          }
          ll ans  = INT_MAX;
          for(ll i=0;i<n;i++)
               ans = min(ans,dist1[i]+dist2[i]+dist3[i]);
               cout<<ans<<endl;

     }
    return 0;
}
