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

int f(string s)
{
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i + len - 1 < n; i++)
        {
            int j = i + len - 1;
            if (s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    return dp[0][n - 1];
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
        string s;
        cin >> s;
        cout << f(s) << "\n";
    }
}