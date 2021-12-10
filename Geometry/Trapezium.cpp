/*
 Problem Link : https://lightoj.com/problem/trapezium
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
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int MX=1e7+123;

int main()
{
    optimize();
    ll limt=1e6+123;
    //primeGen(limt);
    ll t;
    cin>>t;
    for(ll tc=1; tc<=t; tc++)
    {
        double a,b,c,d;
        cin>>a>>b>>c>>d;
        double two_triangle_x_value;
        if(a>c)two_triangle_x_value=a-c;
        else two_triangle_x_value=c-a;
        //combining two triangle first_side=b,second_side=d,third_side=two_triangle_x_value=a-c;
        double first_side=b,second_side=d,third_side=two_triangle_x_value;
        double s=(first_side+second_side+third_side)/2.0;
        double triangle_area=sqrt(s*(s-first_side)*(s-second_side)*(s-third_side));
        double height=(triangle_area*2.0)/two_triangle_x_value;
        double rectangle_area;
        if(a<c)rectangle_area=a*height;
        else  rectangle_area=c*height;
        double totall_area=rectangle_area+triangle_area;
        fraction();
        cout<<"Case "<<tc<<": "<<totall_area<<endl;
    }
}

//Alhamdulillah..



