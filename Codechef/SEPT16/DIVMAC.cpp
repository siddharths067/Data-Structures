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
ll n,sq;
ll arr[100000+10][200] , ind[100000+100];
ll res[2*(100000+10)] = {INT_MIN};
void build(ll s,ll l,ll r){
     if(l==r){
          if(ind[l])res[s] = arr[l][ind[l]-1];
          else res[s] = 1;
     }
     else{
     build(2*s+1,l,(l+r)>>1);
     build(2*s+2,((l+r)>>1) + 1,r);
     res[s] = max(res[2*s+1],res[2*s+2]);
}
}
ll query(ll s,ll left,ll right,ll l ,ll r){
     if(l>right || r<left || l>r) return INT_MIN;
     if(l>=left && r<=right) return res[s];
     if(l==left&&r==right) return arr[l][ind[l]-1];
     else {
          res[s] = max(query(2*s+1,left,(left+right)>>1,l,r),query(2*s+2,(left+right)>>1|1,right,l,r));
          return res[s] ;

     }

}
int main()
{
     ll t,m;
     ll(t);
     while(t--){
          ll(n),ll(m);
          FOR(i,100000+100)ind[i] = 0;
          FOR(i,n){
               ll temp;
               ll(temp);
               if(temp%2==0){while(temp%2==0)temp/=2,arr[i][ind[i]++]=2;}
               INC(j,3,temp,2){
                    if(temp%j==0){
                         while(temp%j==0)temp/=j,
                         arr[i][ind[i]++] = j;
                    }
               }
               if(ind[i]>1){
               ll l= 0,r = ind[i] - 1;
               while(l<r)swap(arr[i][l++],arr[i][r--]);
               }
               /*
               FOR(z,ind[i])cout<<arr[i][z]<<" ";
               cout<<endl;
               */

          }
          build(0,0,n-1);
          while(m--){
               ll ty,l,r;
               ll(ty),ll(l),ll(r);
               l--,r--;
               if(ty==0){
                    while(l<=r){
                         if(ind[l])arr[l][ind[l]--];
                         l++;
                    }
                    build(0,0,n-1);
               }
               else{
                    printf("%lld ",query(0,0,n-1,l,r));
               }
          }
          printf("\n");
     }
    return 0;
}
