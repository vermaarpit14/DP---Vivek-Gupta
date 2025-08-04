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

int f(int i, int j, vector<vector<int>> &a, vector<vector<int>> &dp){
    if(i==0 && j==0)
    return a[0][0];
    if(dp[i][j] != -1)
    return dp[i][j];
    int x=-1, y=-1;
    if(i-1 >= 0)
    x = a[i][j] + f(i-1, j, a, dp);
    if(j-1 >= 0)
    y = a[i][j] + f(i, j-1, a, dp);
    return dp[i][j] = max(x, y);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //code here
    int t; cin>>t;
    while(t--){
        int n, m; cin>>n>>m;
        vector<vector<int>> a(n, vector<int>(m, 0));
        vector<vector<int>> dp(n, vector<int>(m, -1));
        rep(i, 0, n){
            rep(j, 0, m) cin>>a[i][j];
        }
        cout<<f(n-1, m-1, a, dp)<<"\n";
    }
    return 0;
}