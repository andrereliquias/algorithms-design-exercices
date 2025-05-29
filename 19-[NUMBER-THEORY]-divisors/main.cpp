#include <iostream>
#include <vector>

using namespace std;

int MAXX = 1000000;
vector<int> LeastPrimeFactor(MAXX + 1);

void crivo()
{
    for (int i = 0; i <= MAXX; i++)
        LeastPrimeFactor[i] = i;
    LeastPrimeFactor[0] = 0;
    LeastPrimeFactor[1] = 1;
    for (int i = 2; i * i <= MAXX; i++)
    {
        if (LeastPrimeFactor[i] == i)
        {
            for (int j = i * i; j <= MAXX; j += i)
            {
                if (LeastPrimeFactor[j] == j)
                    LeastPrimeFactor[j] = i;
            }
        }
    }
}

int count_divisors(int x)
{
    int acc = 1;
    while (x > 1)
    {
        int p = LeastPrimeFactor[x];
        int count = 0;
        while (x % p == 0)
        {
            x /= p;
            count++;
        }
        acc *= (count + 1);
    }

    return acc;
}

int main()
{
    crivo();

    int n;
    cin >> n;

    for (int i = n; i > 0; i--)
    {
        int x;
        cin >> x;
        cout << count_divisors(x) << endl;
    }

    return 0;
}
