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

int f(vector<int> &a, int n){
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    rep(i, 0, n) dp[i][i] = 1;
    rep(len, 2, n+1){
        rep(i, 0, n+1-len){
            int j = i+len-1;
            dp[i][j] = INT_MAX;
            if (a[i] == a[j]){
                if (i + 1 <= j - 1)
                    dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
                else
                    dp[i][j] = 1;
            }
            rep(k, i, j) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
        }
    }
    return dp[0][n-1];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //code here
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        rep(i, 0, n) cin>>a[i];
        cout<<f(a, n)<<"\n";
    }
    return 0;
}