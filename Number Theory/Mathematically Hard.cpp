/*
 Problem Link : https://lightoj.com/problem/mathematically-hard
 */

#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

#define endl '\n'
#define PB push_back
#define F first
#define S second


ll gcd ( ll a, ll b )
{
    return __gcd ( a, b );
}
ll lcm ( ll a, ll b )
{
    return a * ( b / gcd ( a, b ) );
}

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX=1e7+123;
bitset<MX>is_prime;
vector<ll>primes;
void primeGen(ll n)
{
    ll sq=sqrt(n);
    for(ll i=3; i<=n; i+=2)is_prime[i]=1;

    for(ll i=3; i<=sq; i+=2)
    {
        if(is_prime[i]==1)
        {
            for(ll j=i*i; j<=n; j+=(i+i))
                is_prime[j]=0;
        }
    }
    primes.PB(2);
    is_prime[2]=1;
    for(ll i=3; i<=n; i+=2)
    {
        if(is_prime[i]==1)primes.PB(i);
    }
}
ll NOD(ll n)
{
    ll ans=1;
    for(auto u : primes)
    {

        if(u*u > n)break;
        if(n%u==0)                          // 12=====2^2^3^1    1 2 3 4 6 12
        {
            ll cnt=0;
            while(n%u==0)
            {
                n/=u;
                cnt++;
            }
            cnt++;
            ans*=cnt;
        }
    }
    if(n>1) ans*=2;
    return ans;
}
vector<ll>v;
const int mx=5000123;
unsigned long long phi[mx];
int main()
{
    optimize();
    ll limt=5000123;
    //primeGen(limt);
    for(ll i=1;i<limt;i++)phi[i]=i;
    for(ll i=2;i<limt;i++)
    {
        if(phi[i]==i)
        {

            for(ll j=i;j<limt;j+=i)
            {
                phi[j]*=(i-1);
                phi[j]/=i;
            }
        }
    }
    for(ll i=1;i<limt;i++)phi[i]*=phi[i];
    for(ll i=1;i<limt;i++)phi[i]+=phi[i-1];

    ll tc;
     cin>>tc;
    for(ll test=1;test<=tc;test++)
    {
        ll a,b;
        cin>>a>>b;
      ll ans=phi[b]-phi[a-1];
      cout<<"Case "<<test<<": "<<ans<<endl;
    }
}

//Alhamdulillah..



