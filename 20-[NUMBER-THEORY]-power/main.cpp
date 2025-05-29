#include <iostream>

using namespace std;

using ll = long long;

ll pot(ll a, ll b, ll p)
{
    if (b == 0)
        return 1 % p;
    ll x = pot(a, b / 2, p);
    x = (x * x) % p;
    if (b % 2 == 1)
        x = (x * a) % p;
    return x;
}

int main()
{
    const ll MOD = 1000000007;

    int n;

    cin >> n;
    for (int i = n; i > 0; i--)
    {
        ll a, b;
        cin >> a >> b;
        cout << pot(a % MOD, b, MOD) << endl;
    }

    return 0;
}
