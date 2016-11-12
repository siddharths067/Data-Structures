#include <iostream>
#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
char a[11][11]={'\0'};
int main()
{
     freopen("in5.txt","r",stdin);
     freopen("out5.txt","w",stdout);
	for(ll i=0;i<10;i++)
		for(ll j=0;j<10;j++)
			a[i][j] = '.';
	ll n,m;
	cin>>n>>m;
	for(ll i=0;i<n;i++)
			for(ll j=0;j<m-i-1;j++)
				a[i][j] =  '*';
	for(ll i=0;i<n;i++,cout<<endl)
		for(ll j=0;j<m;j++)
			cout<<a[i][j];
    return 0;
}
