#include <bits/stdc++.h>
using namespace std;
int main()
{

    int a[10] = {1, 1, 1, 2, 2, 2, 3, 3, 3, 4};

    int i, j;
    for (i = 0, j = 0; j < 10; j++)
    {
        if (a[j] != a[i])
        {
            a[++i] = a[j];
        }
    }

    for (j = 0; j <= i; j++)
    {
        cout << a[j] << " ";
    }
    return 0;
}