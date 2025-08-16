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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //code here
    int n; cin>>n;
    vector<int> a(n), pre(n+1, 0);
    rep(i, 0, n) cin>>a[i];
    rep(i, 1, n+1) pre[i] = pre[i-1] + a[i-1];
    auto sum = [&](int l, int r){
        return (pre[r+1]-pre[l])%100;
    };
    vector<vector<int>> dp(n, vector<int>(n, 0));
    rep(len, 2, n+1){
        rep(i, 0, n+1-len){
            int j = i+len-1;
            dp[i][j] = INT_MAX;
            rep(k, i, j) dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+sum(i, k)*sum(k+1, j));
        }
    }
    cout<<dp[0][n-1]<<"\n";
    return 0;
}