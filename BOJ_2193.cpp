// BOJ 2193 이친수
#include <bits/stdc++.h>

using namespace std;
long long dp[91];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("../input.txt", "r", stdin);

    int num;
    cin >> num;

    dp[0] = 1; // 0
    dp[1] = 1; // 1
    for (int i = 2; i <= num; i++)
        for (int j = 2; j <= i; j++)
            dp[i] += dp[i - j];

    cout << dp[num];

    return 0;
}