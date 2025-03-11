// boj 14327
#include <bits/stdc++.h>
#define lint long long int
using namespace std;

lint T; //Test case
lint M; //한 달 동안 열린 날
lint c[105]; //M+1개 양의 정수
double ans;
double threshold = 0.000000001;
double x1 = 2-threshold;

double power(double x, int M)
{
	if(M < 0) return 0;
	if(M == 0) return 1;
	
    double ret = 1;
    for (int i = 0; i < M; i++)
        ret *= x;
    
    return ret;
}

double f(double x1)
{
	double ret = 0;
    ret -= c[0]*power(x1, M);
    for (int i = 1; i <= M; i++)
        ret += c[i]*power(x1, M-i);
    
    return ret;   
}

double df(double x1)
{	
	double ret = 0;
	ret -= M*c[0]*power(x1, M-1);
	for (int i = 1; i <= M; i++)
        ret += (M-i)*c[i]*power(x1, M-1-i);
    return ret;   
}

double newtonRaphson(double x1)
{
    if(f(x1+threshold)*f(x1-threshold) <= 0) return x1;
    else
    {
        x1 -= f(x1)/df(x1);
        return newtonRaphson(x1);
    }
}

int main()
{
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cin >> M;
        for (int j = 0; j <= M; j++)
            cin >> c[j];
        
        printf("Case #%d: %.12lf\n", i, newtonRaphson(x1)-1);
    }
}
