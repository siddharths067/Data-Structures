#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll bit[10000000+2]={0};

void update(ll s){
     for(;s<10000000+2;s+=s&-s)bit[s]+=1;
}

ll read(ll s){
     ll sum=0;
     for(;s;s-=s&-s)sum+=bit[s];
     return sum;
}

int main(){
     ll n;
     cin>>n;
     for(ll j=0;j<n;j++){
          ll temp;
          cin>>temp;
          for(ll i=2;temp>1;i++)
               if(!(temp%i)){
                    update(i);
                    while(!(temp%i))temp/=i;
               }
     }
     ll m;
     cin>>m;
     while(m--){
          ll l,r;
          cin>>l>>r;
          cout<<read(min(10000000LL,r))  - read(l-1)<<endl;
     }
     return 0;
}
