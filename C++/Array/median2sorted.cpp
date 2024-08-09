#include <bits/stdc++.h>
using namespace std;
int median(vector<int> &a, vector<int> &b)
{
    int na = a.size();
    int nb = b.size();
    // apply bs on smaller array to reduce complexity
    // let a be smaller array
    if (na > nb)
    {
        return median(b, a);
    }
    int lowA = 0, highA = na;
    while (lowA <= highA)
    {
        // midA-> elements to pick from a
        // set l1,r1 as boundary elements of a around midA
        int midA = (lowA + highA) / 2;
        // midB-> elements to pick from b
        // set l2,r2 as boundary elements of b around midB
        int midB = ((na + nb + 1) / 2) - midA;
        // set l1 l2 r1 r2
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (midA > 0)
        {
            l1 = a[midA - 1];
        }
        if (midB > 0)
        {
            l2 = b[midB - 1];
        }
        if (midA < na)
        {
            r1 = a[midA];
        }
        if (midB < nb)
        {
            r2 = b[midB];
        }
        // check for valid symmetry
        if (l1 > r2)
        {
            highA = midA - 1;
        }
        else if (l2 > r1)
        {
            lowA = midA + 1;
        }
        else
        { // if valid symmetry
            if ((na + nb) & 1)
            { // odd
                return max(l1, l2);
            } // even
            return ((max(l1, l2) + min(r1, r2)) / 2);
        }
    }
    return 0;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    vector<int> a = {7, 12, 14, 15, 16};
    vector<int> b = {1, 2, 3, 4, 9, 11};
    cout << median(a, b);
    return 0;
}