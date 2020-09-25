// BOJ 1463 1로 만들기
#include <bits/stdc++.h>

using namespace std;

int min(int a, int b) {
    return a > b ? b : a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("../input.txt", "r", stdin);

    int num;
    cin >> num;
    vector<int> dp(num + 1);

    // 초기 기저 값
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 4; i <= num; i++) {
        dp[i] = dp[i - 1] + 1;
        if (i % 3 == 0)
            dp[i] = min(dp[i], dp[i / 3] + 1);
        else if (i % 2 == 0)
            dp[i] = min(dp[i], dp[i / 2] + 1);
    }
    cout << dp[num];

    return 0;
}