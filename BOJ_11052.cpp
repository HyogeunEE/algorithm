// BOJ 11052 붕어빵 판매하기
#include <bits/stdc++.h>

using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("../input.txt", "r", stdin);

    int num;
    cin >> num;
    vector<int> price(num + 1); // 개당 가격
    vector<int> dp(num + 1);    // 최대 값 저장

    for (int i = 1; i <= num; i++) {
        cin >> price[i];
        dp[i] = price[i]; // 초기 값
        for (int j = 1; j <= i - 1; j++)
            dp[i] = max(dp[i], dp[i - j] + price[j]);
    }
    cout << dp[num];

    return 0;
}