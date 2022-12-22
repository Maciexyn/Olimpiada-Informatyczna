#include <iostream>

using namespace std;
int* v = new int[1000001];
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1;i<=n;i++)
    {
        cin >> v[i];
    }
    for (int i = 1;i<=n;i++)
    {
        cout << v[i];
    }
}