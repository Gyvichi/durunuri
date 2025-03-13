#import<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct Point{LL i, x, y;};
int s[100005];
Point p[100005];
int C(Point a, Point b){return a.x < b.x || a.x == b.x && a.y < b.y;}
LL ccw(LL x1, LL y1, LL x2, LL y2, LL x3, LL y3)
{
    LL t =  (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
    if(t > 0)return 1;
    else if(t < 0)return -1;
    else return 0;
}
int main()
{
    int k = 0, n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        p[i].i = i + 1;
        cin >> p[i].x >> p[i].y;
    }
    sort(p, p + n, C);
    for(int i = 0; i < n;)
    {
        if(k < 2 || ccw(p[s[k - 2]].x, p[s[k - 2]].y, p[s[k - 1]].x, p[s[k - 1]].y, p[i].x, p[i].y) < 0)s[k++] = i++;
        else k--;
    }
    s[k++] = n - 2;
    for(int i = n - 1; i >= 0;)
    {
        if(s[k - 1] == n - 1 || ccw(p[s[k - 2]].x, p[s[k - 2]].y, p[s[k - 1]].x, p[s[k - 1]].y, p[i].x, p[i].y) < 0)s[k++] = i--;
        else k--;
    }
    k--;
    for(int i = 0; i < k; i++)s[i] = p[s[i]].i;
}
