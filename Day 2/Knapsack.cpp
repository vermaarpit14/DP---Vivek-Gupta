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

int f(int i, int w, vector<int> &W, vector<int> &V, vector<vector<int>> &dp)
{
    if (i < 0)
    {
        return 0;
    }
    if (dp[i][w] != -1)
    {
        return dp[i][w];
    }
    int not_take = f(i - 1, w, W, V, dp);
    if (W[i] <= w)
    {
        int take = V[i] + f(i - 1, w - W[i], W, V, dp);
        return max(take, not_take);
    }
    return not_take;
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
        int n, w;
        cin >> n >> w;
        vector<int> W(n), V(n);
        rep(i, 0, n) cin >> W[i] >> V[i];
        vector<vector<int>> dp(n, vector<int>(w + 1, -1));
        cout << f(n - 1, w, W, V, dp) << "\n";
    }
}