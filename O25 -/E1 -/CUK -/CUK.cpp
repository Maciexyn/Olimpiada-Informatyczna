#include <iostream>

using namespace std;

long a[3];
long b[3];
long c[3];
long d[3];
long long aa = 0;
long long bb = 0;
long long cc = 0;
void check()
{
    if (a[1]+a[2]+b[0]+b[2]>b[1]+b[2]+a[0]+a[2])
    {
        swap(a,b);
    }
    if (a[1]+a[2]+c[0]+c[1]>c[1]+c[2]+a[0]+a[1])
    {
        swap(a,c);
    }
    if (b[0]+b[2]+c[0]+c[1]>c[0]+c[2]+b[0]+b[1])
    {
        swap(b,c);
    }
}

int main()
{
    int n;
    cin >> n;
    long d[3];
    cin >> a[0] >> a[1] >> a[2];
    cin >> b[0] >> b[1] >> b[2];
    cin >> c[0] >> c[1] >> c[2];
    aa+=a[0]+b[0]+c[0];
    bb+=a[1]+b[1]+c[1];
    cc+=a[2]+b[2]+c[2];
    long long y = 0;
    check();
    for (int i = 3;i<n;i++)
    {
        cin >> d[0] >> d[1] >> d[2];
        aa+=d[0];
        bb+=d[1];
        cc+=d[2];
        if (d[1]+d[2]<a[1]+a[2])
        {
            swap(a,d);
            check();
        }
        if(d[0]+d[2]<b[0]+b[2])
        {
            swap(b,d);
            check();
        }
        if(d[0]+d[1]<c[0]+c[1])
        {
            swap(c,d);
            check();
        }
        y+=d[0]+d[1]+d[2]-max(d[0],max(d[1],d[2]));
    }
    if (aa==0)
    {
        y+=min(a[1],a[2]);
    }
    else
    {
        y+=a[1]+a[2];
    }
    if (bb==0)
    {
        y+=min(b[0],b[2]);
    }
    else
    {
        y+=b[0]+b[2];
    }
    if (cc==0)
    {
        y+=min(c[0],c[1]);
    }
    else
    {
        y+=c[0]+c[1];
    }
    cout << y;
    return 0;
}