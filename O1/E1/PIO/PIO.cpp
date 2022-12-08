#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    bool stepsblack[100][100];
    bool whitesteps[100][100];
    bool black[100];
    bool white[100];
    char z;
    for (int i = 0;i<64;i++)
    {
        cin >> z;
        if (z==*"C")
        {
            black[i] = true;
            white[i] = false;
        }
        else
        {
            black[i] = false;
            white[i] = true;
        }
    }
    for (int i = 1;i<=64;i++)
    {
        for (int j=0;j<65;j++)
        {
            stepsblack[i][j] = false;
            whitesteps[i][j] = false;
        }
    }
    for (int x = 0;x<8;x++)
    {
        for(int y = 0;y<8;y++)
        {
            if(black[8*x+y])
            {
                stepsblack[8*x+y][64]=true;
            }
            if(white[8*x+y])
            {
                whitesteps[8*x+y][64]=true;
            }
            for (int a = max(0,x-1);a<min(8,x+2);a++)
            {
                for (int b = max(0,y-1);b<min(8,y+2);b++)
                {
                    if (a == x && b == y)
                    {
                        continue;
                    }
                    stepsblack[8*x+y][8*a+b] = true;
                    whitesteps[8*x+y][8*a+b] = true;
                }
            }
        }
    }
    for (int i=0;i<64;i++)
    {
        if (!stepsblack[i][i])
        {
            for (int j=i+1;j<64;j++)
            {
                if (stepsblack[j][i])
                {
                    swap(stepsblack[i],stepsblack[j]);
                }
            }
        }
        for (int j=0;j<64;j++)
        {
            if (i==j)
            {
                continue;
            }
            if (stepsblack[j][i])
            {
                for(int k=0;k<65;k++)
                {
                    if (stepsblack[i][k])
                    {
                        stepsblack[j][k] = !stepsblack[j][k];
                    }
                }
            }
        }
    }
    for (int i=0;i<64;i++)
    {
        if (!whitesteps[i][i])
        {
            for (int j=i+1;j<64;j++)
            {
                if (whitesteps[j][i])
                {
                    swap(whitesteps[i],whitesteps[j]);
                }
            }
        }
        for (int j=0;j<64;j++)
        {
            if (i==j)
            {
                continue;
            }
            if (whitesteps[j][i])
            {
                for(int k=0;k<65;k++)
                {
                    if (whitesteps[i][k])
                    {
                        whitesteps[j][k] = !whitesteps[j][k];
                    }
                }
            }
        }
    }
    int steps1 = 0;
    int steps2 = 0;
    for (int i=0;i<64;i++)
    {
        if (stepsblack[i][64])
        {
            steps1++;
        }
        if (whitesteps[i][64])
        {
            steps2++;
        }
    }
    if (steps1<steps2)
    {
        cout << steps1 << "\n";
        for (int i=0;i<64;i++)
        {
            if (stepsblack[i][64])
            {
                cout << i+1 << " ";
            }
        }
    }
    else
    {
        cout << steps2 << "\n";
        for (int i=0;i<64;i++)
        {
            if (whitesteps[i][64])
            {
                cout << i+1 << " ";
            }
        }
    }
}