// BOJ 1915 가장 큰 정사각형
#include <bits/stdc++.h>

using namespace std;

int min(int a, int b, int c){
    return a > b ? (b > c ? c : b) : (a > c ? c : a);
}
int max(int a, int b){
    return a < b ? b : a;
}

#define MAXNUM 1001
char arr[MAXNUM][MAXNUM];
int dp[MAXNUM][MAXNUM];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("../input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> arr[i] + 1;

    int result = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] == '1') {
                // 한 점을 기준으로 내 주변 3개 좌표의 점으로 사격형 만들 수 있는지?
                // D[i][j] = min(D[i-1][j], D[i-1][j-1], D[i][j-1]) + 1
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]) + 1;
                result = max(dp[i][j], result);
            }
        }
    }
    cout << result * result;

    return 0;
}