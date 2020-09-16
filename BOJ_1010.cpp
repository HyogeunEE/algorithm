// BOJ 1010 다리 놓기
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("../input.txt", "r", stdin);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        long long result = 1;
        cin >> n >> m;

        // nCr을 위해 n-r과 r 중에 작은 값 선택
        n = n > m - n ? m - n : n;
        // nCr
        for (int i = 0; i < n; i++)
            result *= m - i; // n! / (n-r)!
        for (int i = 2; i <= n; i++)
            result /= i; // r!
        cout << result << '\n';
    }

    return 0;
}