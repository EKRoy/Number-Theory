#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);
int main()
{
    fast_io;
    ll n;
    cin >> n;
    map<ll, ll> cnt;
    // Prime factorization using trial division
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                cnt[i]++;
                n /= i;
            }
        }
    }
    // If remaining n is greater than 1, it is prime
    if (n > 1)
    {
        cnt[n]++;
    }
    // Print prime factors and their counts
    for (auto [primeFactor, frequency] : cnt)
    {
        cout << primeFactor << " " << frequency << "\n";
    }
    return 0;
}
