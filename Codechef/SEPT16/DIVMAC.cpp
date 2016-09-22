#include <bits/stdc++.h>
#define ll(x) scanf("%lld",&x)
#define pll(x) printf("%lld ",x)
using namespace std;
typedef long long int ll;
ll pd[1000000+1],sieve[1000000+1],tree[3*100000],arr[100000];
void siev(){
     for(ll i=0;i<1000000+1;i++)sieve[i] = 1,pd[i] = 0;
     pd[0] = 1,pd[1] = 1;

     for(ll i=2;i<=1000000;i++)
          if(sieve[i]){
               pd[i] = i;
               for(ll j=i<<1;j<=1000000+1;j+=i){
                    if(!pd[j])
                         pd[j] = i;
                    sieve[j] = 0;
               }
          }
}

void build(ll s,ll left,ll right){
     if(left==right){
          tree[s] = arr[left];
          return;
     }
     ll m = (left+right)>>1;
     build(2*s+1,left,m);
     build(2*s+2,m+1,right);
     tree[s] = max(pd[tree[2*s+1]],pd[tree[2*s+2]]);
}

ll query(ll s,ll left,ll right,ll l,ll r){
     //cout<<l<<" "<<r<<" "<<s<<"-> "<<left<<" "<<right<<endl;
     if(l > right || r < left || left>right )return 1;
     if(l<=left && r>=right)
          return tree[s];
     if(tree[s]!=1){
          ll m = (left+right)>>1;
          return max(pd[query(2*s+1,left,m,l,r)],pd[query(2*s+2,m+1,right,l,r)]);

     }
     return 1;
}

void modify(ll s,ll left,ll right,ll l,ll r){
     //cout<<l<<" "<<r<<" "<<s<<"-> "<<left<<" "<<right<<endl;
     if(l > right || r < left || left>right)return;
     if(left==right){
          tree[s] = tree[s]/pd[tree[s]];
          return ;
     }
     if(tree[s]!=1){
          ll m = (left+right)>>1;
          modify(2*s+1,left,m,l,r),modify(2*s+2,m+1,right,l,r);
          tree[s] = max(pd[tree[2*s+1]],pd[tree[2*s+2]]);
          return;
     }
     return;
}


int main(){
     ios_base::sync_with_stdio(0);
     siev();
     ll t;
     ll(t);
     while(t--){
          ll n,m;
          ll(n),ll(m);
          for(ll i=0;i<n;i++)ll(arr[i]);
          build(0,0,n-1);
          //cout<<"done"<<endl;
          while(m--){
               ll a,b,c;
               ll(a),ll(b),ll(c);
               if(!a) modify(0,0,n-1,b-1,c-1);
               else pll(query(0,0,n-1,b-1,c-1));
          }
          printf("\n");
     }
     return 0;
}
