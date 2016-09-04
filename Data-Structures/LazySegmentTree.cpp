#include <iostream>
#define MAX 10000
typedef long long int ll;
using namespace std;
ll arr[MAX],Tree[3*MAX],lazy[2*MAX];
  
/**** The Recursive Segment Tree ****/

void Build(ll s, ll start, ll end)
{
	if(start==end)
		Tree[s] = arr[start];
	else
	{
		ll mid = (start+end)/2;
		Build(2*s+1,start,mid);
		Build(2*s+2,mid+1,end);
		Tree[s] = Tree[2*s+1]+Tree[2*s+2];
	}
}

void Update(ll s,ll start,ll end,ll left,ll right,ll value)
{
	if(lazy[s]!=0)
	{
		Tree[s]+=(lazy[s]*(end-start+1));
		if(start!=end)lazy[2*s+1]+=value,lazy[s*2+2]+=value;
		lazy[s]=0;
	}
	if(start>end||left>end||right<start)return;
	if(start>=left&&end<=right)
	{
		Tree[s] += (value*(end-start+1));
		if(start!=end)
		{
			lazy[2*s+1]+=value;
			lazy[2*s+2]+=value;
		}
		return ;
	}
	ll mid=(start+end)/2;
	Update(2*s+1,start,mid,left,right,value);
	Update(2*s+2,mid+1,end,left,right,value);
	Tree[s] = Tree[s*2+1]+Tree[2*s+2];
}

ll Read(ll s,ll start,ll end,ll left,ll right)
{
	if(start>end||start>right||end<left)return 0;
	if(lazy[s]!=0)
	{
		Tree[s]+=(lazy[s]*(end-start+1));
		if(start!=end)
		{
			lazy[2*s+1]+=lazy[s];
			lazy[2*s+2]+=lazy[s];
		}
		lazy[s]=0;
	}
	if(start>=left&&end<=right)return Tree[s];
	else return (Read(2*s+1,start,(start+end)/2,left,right)+Read(2*s+2,1+((start+end)/2),end,left,right));

}
int main() {
	// your code goes here
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++)cin>>arr[i];
	Build(0,0,n-1);
	Update(0,0,n-1,3,6,2);
	cout<<Read(0,0,n-1,0,n-1);
	cout<<endl;
	for(ll i=0;i<n;i++)cout<<Read(0,0,n-1,i,i)<<" ";
	return 0;
}
