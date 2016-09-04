#include <bits/stdc++.h>

typedef long long int ll;
using namespace std;
/**** This would be the first project in the repo ****/
/**** Now Seriously I need to learn git ****/

ll rangesum(vector<ll> data,vector<ll> decomp,ll len,ll l,ll r){
          ll sum=0;
          l--,r--; //adjust for zero indexing

          for(ll i=l;i<=r;)
               if(i%len==0 && i+len-1 <= r)
                    sum+=decomp[i/len],i+=len; //block reading
               else
                    sum+=data[i++]; //individual item reading

          return sum;
}

int main(){
     ll n;
     cin>>n;
     vector<ll> data(n);
     ll len = (ll)sqrt(n + .0) + 1;
     vector<ll> decomp(len);
     for(ll i=0;i<n;i++)
          cin>>data[i],decomp[i/len]+=data[i];


     /***** Range Query -SUM  Example *****/
     while(1){
          ll l,r;
          cin>>l>>r;
          if(l==-1&&r==-1)break;
          else cout<<rangesum(data,decomp,len,l,r)<<endl;
     }
     /***** Range Query - SUM Example End *****/

}
