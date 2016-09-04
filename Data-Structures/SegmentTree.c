#include<stdio.h>
#include<stdlib.h>

typedef long long int ll;   
/*** The really complicated iterative one ***/
ll tree[100000]={0};
ll n;
void build()
{

	for(ll i = n-1 ;i>0;i--)tree[i] = tree[i<<1] + tree[i<<1|1];
}

void update(ll e,ll val)
{
    e--;
	for(tree[e+=n]=val;e>0;e>>=1)tree[e>>1] = tree[e]+tree[e^1];
}
ll read(ll l,ll r)
{
    l--;
	ll res=0;
	for(l+=n,r+=n;l<r; l>>=1,r>>=1)
	{
		if(l&1)res+=tree[l++];
		if(r&1)res+=tree[--r];
	}
	return res;
}


int main()
{

	scanf("%lld",&n);
	for(ll i=0;i<n;i++)
		scanf("%lld",tree+n+i);
	build();
	ll z =2;
	while(z--)
	{
		ll u,v;
		scanf("%lld %lld",&u,&v);
		printf("%lld\n",read(u,v));
	}
	update(3,9);
	printf("%lld\n",read(1,3));
	return 0;
}
