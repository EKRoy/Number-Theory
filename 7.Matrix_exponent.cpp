#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 101;
ll ar[N][N]; // Original matrix
ll I[N][N];	 // Identity matrix
// Matrix Multiplication: A = A × B
void multiply(ll A[][N], ll B[][N], ll n)
{
	ll result[N][N];
	for (ll i = 1; i <= n; i++)
	{
		for (ll j = 1; j <= n; j++)
		{
			result[i][j] = 0;

			for (ll k = 1; k <= n; k++)
			{
				result[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	// Copy result back to A
	for (ll i = 1; i <= n; i++)
	{
		for (ll j = 1; j <= n; j++)
		{
			A[i][j] = result[i][j];
		}
	}
}
// Matrix Exponentiation: A = A^p
void matrix_power(ll A[][N], ll n, ll p)
{
	// Initialize Identity Matrix
	for (ll i = 1; i <= n; i++)
	{
		for (ll j = 1; j <= n; j++)
		{
			I[i][j] = (i == j ? 1 : 0);
		}
	}
	while (p > 0)
	{
		if (p % 2 == 1)
		{
			multiply(I, A, n);
			p--;
		}
		else
		{
			multiply(A, A, n);
			p /= 2;
		}
	}
	// Copy Identity (final result) to A
	for (ll i = 1; i <= n; i++)
	{
		for (ll j = 1; j <= n; j++)
		{
			A[i][j] = I[i][j];
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin >> t;
	while (t--)
	{
		ll n, p;
		cin >> n >> p;
		// Input matrix
		for (ll i = 1; i <= n; i++)
		{
			for (ll j = 1; j <= n; j++)
			{
				cin >> ar[i][j];
			}
		}
		matrix_power(ar, n, p);
		// Output result
		for (ll i = 1; i <= n; i++)
		{
			for (ll j = 1; j <= n; j++)
			{
				cout << ar[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
