// BOJ 11049 행렬 곱셈 순서
// 어떤 연산이 마지막이었을 때가 최적인지?????
// 중복 연산을 하지 않기 위하여 메모이제이션 기법 사용
// D[s][e] 결과를 저장
// start, end 잡고 mid 잡아서 계속 반복 연산하면 안됨
//
//
#include <bits/stdc++.h>

using namespace std;

#define MAXN 501
int mat[MAXN][2];
int calc[MAXN][MAXN];
int INF = (int) ((1ll << 31) - 1);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("../input.txt", "r", stdin);

    int N;
    for (int i = 1; i <= N; i++)
        cin >> mat[i][0] >> mat[i][1];
    // 일단 인접한 행렬끼리 계산
    for (int i = 1; i <= N - 1; i++)
        calc[i][i + 1] = mat[i][0] * mat[i][1] * mat[i + 1][1];

    for (int gap = 2; gap < N; gap++) {
        for (int s = 1; s + gap <= N; s++) {
            calc[s][s + gap] = INF;
            for (int mid = s; mid < s + gap; mid++) {
                calc[s][s + gap] = min(calc[s][s + gap],
                                       calc[s][mid] + calc[mid + 1][s + gap] +
                                       mat[s][0] * mat[mid][1] * mat[s + gap][1]);
            }
        }
    }
    cout << calc[1][N];

    return 0;
}