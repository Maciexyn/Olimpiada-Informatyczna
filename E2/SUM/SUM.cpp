#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    string number,d;
    int digits[100];
    int n,sumsquares,l;
    cin >> n;
    for (int i=0;i<n;i++)
    {
        cin >> number;
        cout << number << " ";
        sumsquares = 0;
        if (number=="1" || number=="4")
        {
            cout << endl;
            continue;
        }
        while (sumsquares != 1 && sumsquares != 4)
        {
            sumsquares = 0;
            l = number.length();
            for (int i =0;i<l;i++)
                {
                    d = number[i];
                    digits[i] = stoi(d);
                }
            for (int i =0;i<l;i++)
            {
                sumsquares = sumsquares + digits[i]*digits[i];
            }
            number = to_string(sumsquares);
            cout << number << " ";   
        }
        cout << endl;
    }
}