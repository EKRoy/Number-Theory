#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;
// Fast Modular Exponentiation (Binary Exponentiation)
ll power_mod(ll base, ll power)
{
    ll result = 1;
    base %= MOD; // Handle large base
    while (power > 0)
    {
        if (power & 1)
        { // If power is odd
            result = (result * base) % MOD;
        }
         base = (base * base) % MOD; // Square the base
        power >>= 1;             // Divide power by 2
    }
    return result;
}
int main()
{
    ll a, b;
    cin >> a >> b;
    ll ans = power_mod(a, b);
    cout << ans << "\n";
    return 0;
}
