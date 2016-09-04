#include<stdio.h>
#include<stdlib.h>
#include <limits.h>

/****  Articulation Points ****/


#define min(a,b) ((a)<(b))?(a):(b)
#define N  300+10
#define s(x) scanf("%lld",&x)
typedef long long int ll;
ll edge[N][5000],disc[N],low[N],parent[N],adj[N];
int visited[N],articulated[N];
ll _time=0;
ll ans=0;
void init()
{
//	freopen("kingcon.txt","r",stdin);
	ll i,j;
	for(i =0;i<N;i++)
	{
		adj[i] =0;
		disc[i] = 0;
		parent[i] = -1;
		low[i] = INT_MAX;
		visited[i] = articulated[i] = 0;
		for(j=0;j<N;j++)
			edge[i][j] = 0;
	}
//	printf("initialization done...\n");
	_time=0;
}
void dfs(ll u)
{
//	printf("at node %lld \n",u);
	visited[u] =1;
	disc[u]= low[u] = ++_time;
	ll num_child=0;
	ll i,j;
	for(i=0;i<adj[u];i++)
	{
		if(!visited[edge[u][i]])
		{
			num_child++;
			parent[edge[u][i]]= u;
			dfs(edge[u][i]);
			low[u] = min(low[u],low[edge[u][i]]);
			if(parent[u]==-1&&num_child>1)
				articulated[u]=1,ans++;//printf("articulation set root %lld\n",u);
			else if(parent[u]!=-1&&low[edge[u][i]]>=disc[u])
				articulated[u]=1,ans++;//printf("articulation set  %lld\n",u);

		}
		else if(edge[u][i]!=parent[u])
			low[u] = min(low[u],disc[edge[u][i]]);
	}
}
int main()
{
//	ll t;
//	s(t);
//	while(t--)
//	{
		init();
		ll n,e,k,i=0;
		s(n);s(e);//s(k);
		for(i=0;i<e;i++)
		{
			ll u,v;
			s(u);s(v);
            u--;v--;
            edge[u][adj[u]++]=v;
			edge[v][adj[v]++] = u;
		}
		//printf("input done....\n");
		for(i=0;i<n;i++)
			if(!visited[i])
				dfs(i);
		ans=0;
for(i=0;i<n;i++)
			if(articulated[i])ans++;
        printf("%lld\n",ans);
		for(i=0;i<n;i++)
			if(articulated[i])printf("%lld\n",i+1);
				//printf("%lld\n",i);
		//printf("%lld\n",ans*k);
//	}
	return 0;
}
