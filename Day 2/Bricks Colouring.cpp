/************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define each(x, a) for (auto &x : a)

const int INF = 1e18;
const int MOD = 1e9 + 7;

vector<bool> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    return isPrime;
}
/************************************************************************************/

int n, m, k;
vector<vector<int>> dp;

int f(int i, int j)
{
    if (j < 0)
        return 0;
    if (i == 1)
        return ((j == 0) ? m : 0);

    if (dp[i][j] != -1)
        return dp[i][j];

    int same = f(i - 1, j);
    int diff = f(i - 1, j - 1) * (m - 1);
    return dp[i][j] = (same + diff) % MOD;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // code here
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;
        dp.assign(n + 1, vector<int>(k + 1, -1));
        cout << f(n, k) << "\n";
    }
}