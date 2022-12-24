#include <iostream>
#include <string>
#include <sstream>

using namespace std;;

int main() {
    ios_base::sync_with_stdio(false);
    string line;
    int actions[20000];
    int intline[20000];
    int number,z,x;
    int y = 0;
    while (getline(cin, line)) 
    {
        istringstream iss(line);
        z=0;
        while (iss >> number)
        {
            intline[z] = number;
            z++;
        }
        x=0;
        for (int i=0;i<z;i++)
        {
            if (intline[i] == -99)
            {
                for (int j = i;j<z;j++)
                {
                    actions[j-x] = actions[j+1-x];
                }
                x++;
            }
            else
            {
                actions[i-x] = max(actions[i-x]+intline[i],intline[i]);
                y = max(actions[i-x],y);
            }
        }
    }
    cout << y;
    return 0;
}