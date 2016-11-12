#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main(){
     string s1,s2,s3;
     ll n;
     cin>>s1>>s2>>s3>>n;
     string s;
     while(n--)s+= (s1+s2);
     cout<<s+s3<<endl;
     return 0;
}
