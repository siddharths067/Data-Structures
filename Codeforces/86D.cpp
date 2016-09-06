/***** 86-D Division One - Powerful Array
Athough Mo's Algorithm is the solution , yet my code fails to qualify.
Needs Implementative or Asymtotic Improvement.
 *****/
#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0)
#define SLLD(x) scanf("%lld",&x);

#define ll(x) scanf("%I64d",&x)
#define pll(x) printf("%I64d",x)

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
typedef struct{
     ll l,r,i;
} query;
ll _count[1000000+1]={0};
ll arr[200000];
ll ans = 0;
ll n,t;
query q[200000];
ll res[200000];
ll sq;
void add(ll position){
     //cout<<"added - > "<<arr[position] <<" == " << _count[arr[position]]+1<<endl;
     ans-=(_count[arr[position]]*_count[arr[position]]*arr[position]);
     _count[arr[position]]++;
     ans+=(_count[arr[position]]*_count[arr[position]]*arr[position]);
}
void del(ll position){

     //cout<<"deleting - > "<<arr[position] <<" == " << _count[arr[position]]-1<<endl;
     /*
     ans-=(_count[arr[position]]*_count[arr[position]]*arr[position]);
     _count[arr[position]]--;
     ans+=(_count[arr[position]]*_count[arr[position]]*arr[position]);
     */
     ans -= (2*_count[arr[position]]-1)*arr[position];
        _count[arr[position]]--;
}
bool comp(query a,query b){
     if((a.l/sq) != (b.l/sq))
          return (a.l/sq) < (b.l/sq);
     else return (a.r) < (b.r);
}
int main()
{
     FIO;
     cin.tie(0);
     ll(n),ll(t);
     sq = (ll)sqrt(n+ .0) + 1;
     FOR(i,n)ll(arr[i]),_count[arr[i]]=0;

          query temp;
     FOR(i,t){
          ll(temp.l),ll(temp.r);
          temp.l--,temp.r--;
          temp.i = i;
          q[i] = temp;
     }
     sort(all(q),comp);
     //ITER(a,q)
     //     cout<<a.l<<" "<<a.r<<" "<<a.i<<endl;
     //cout<<endl;
     ll cur_l = q[0].l ,cur_r = q[0].l;
     add(q[0].l);
     for(query z : q){
          //FOR(i,n)cout<<_count[arr[i]]<<" ";
          //if((cur_r<z.l)||(z.r<cur_l))ans = 0 ,cur_l=cur_r=z.l,add(z.l);
          while(cur_l < z.l)
               del(cur_l),cur_l++;
          while(cur_l>z.l)
               add(cur_l-1),cur_l--;
          while(cur_r < z.r)
               add(cur_r+1),cur_r++;
          while(cur_r > z.r)
               del(cur_r),cur_r--;
          res[z.i] = ans;
     }
     FOR(i,t)pll(res[i]),putchar('\n');
     return 0;
}
