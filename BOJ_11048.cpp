// BOJ 11048 이동하기
#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}

int max(int a, int b, int c) {
    return max(max(a, b), c);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("../input.txt", "r", stdin);

    int N, M, input;
    cin >> N >> M;
    vector<vector<int> > dp(N + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> input;
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + input;
        }
    }
    cout << dp[N][M];

    return 0;
}