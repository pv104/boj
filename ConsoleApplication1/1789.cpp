#include <iostream>
using namespace std;
int main()
{
    cin.tie(0); ios::sync_with_stdio(0);
    long long res = 0, s = 0;
    cin >> s;
    for (long long i = 1; i <= s; i++)
    {
        res += i;
        if (s <= res)
        {
            if (s == res)
                cout << i;

            else cout << i - 1;
            return 0;
        }
    }
}