#include <iostream>

using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    double x,y,t,a,b,c;
    char z;
    cin >> x >> z >> y;
    a = x/y;
    cin >> x >> z >> y;
    b = x/y;
    cin >> x >> z >> y;
    c = x/y;
    if (a>c)
    {
        swap(a,c);
    }
    if (b>c)
    {
        swap(b,c);
    }
    if (a>b)
    {
        swap(a,b);
    }
    for (int i = 2; i<n; i++)
    {
        cin >> x >> z >> y;
        t = x/y;
        b = min(t,b);
        c = max(t,c);
        if (a>b)
        {
            swap(a,b);
        }
    }
    if (a+b>c)
    {
        cout << "TAK\n";
    }
    else
    {
        cout << "NIE\n";
    }
    return 0;
}
