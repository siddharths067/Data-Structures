#include <bits/stdc++.h>
#define node pair<pair<ll,ll>,ll>

typedef long long int ll;
using namespace std;

/**** Heap Condition Specifier ****/
class prio
{
public:
    bool operator()(const node &a,const node &b)
    {
        //In Priority Queue Inverse condition is used
        // A<B for Max Fibonacci heap
        return a.first.second < b.first.second;
    }
};
/**** Heap Condition Specifier ends here ****/

map<ll,vector<ll> > edge;
map<pair<ll,ll>,ll> capacity; // Stores the original and the augmenting netowork
vector<ll> visi,from;
ll N,M,source,sink;
ll PFS();
//N - Number of Nodes , M - Number of Edges
int main()
{
    freopen("in2.txt","r",stdin);
    cin>>N>>M>>source>>sink;
    source--,sink--; // zero index the source and sink
    for(ll i=0; i<M; i++) // input the edges
    {
        ll u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        edge[u].push_back(v);
        capacity[ {u,v}] = w; // enter the weight of the network here
        capacity[ {v,u}] = 0; // the augmenting path,helps to find disconnection
    }
    ll ans=0;
    while(1)
    {
        ll path_cap = PFS(); // current max path found
        if(path_cap==0)break; // termination
        ans+=path_cap;

    }
    cout<<"The Path Capacity is >>"<<ans<<endl;
    for(auto u : edge)
        for(auto v : u.second)
            cout<<u.first+1<<" "<<v+1<<" "<<capacity[ {v,u.first}]<<endl;
    return 0;
}

ll PFS()
{
    visi.resize(N); //visited nodes information
    from.resize(N); //the from section helps to find the previous pipes
    fill(visi.begin(),visi.end(),0);
    fill(from.begin(),from.end(),-1);
    priority_queue<node,vector<node>,prio> Q; // Heap for pipes
    ll path_cap = 0;
    Q.push({{source,INT_MAX},-1}); // store <curr node, path cap, the from node
    ll d = 0;
    while(!Q.empty()&&!d) // terminate if you reach sink
    {
        node aux = Q.top(); // get the current pipe with maximum flow capacity
        Q.pop();
        ll where = aux.first.first; // the current node
        ll cost = aux.first.second; // the current pipe capacity
        ll fro = aux.second; // the from node
        if(visi[where])continue; //if visited ignore it
        visi[where] = 1; //mark node is visited
        from[where] = fro; //store the from node
        if(where == sink) // if we have reached the sink assign path capacity
        {
            path_cap = cost;
            d=1;
        }
        for(auto z : edge[where])
            if(capacity[ {where,z}]>0)
            {
                ll new_cost = min(cost,capacity[ {where,z}]);
                Q.push({{z,new_cost},where});
            }

    }
    ll u = sink; // backtrack from sink
    while(from[u]>-1)
    {
        ll prev = from[u];
        capacity[ {prev,u}] -=path_cap;
        capacity[ {u,prev}] +=path_cap;
        u = prev;
    }
    return path_cap;
}
