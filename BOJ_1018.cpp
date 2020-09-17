// BOJ_1018 체스판 다시 칠하기
#include <iostream>

using namespace std;

char board[52][52];

int min(int a, int b) {
    return a > b ? b : a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("../input.txt", "r", stdin);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    int result = INT32_MAX;
    // x, y 시작 좌표 설정
    for (int x = 0; x <= N - 8; x++) {
        for (int y = 0; y <= M - 8; y++) {
            // 8*8 칸 탐색 및 'B' 카운트
            int cnt = 0;
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    int xx = x + i;
                    int yy = y + j;
                    int sum = xx + yy;
                    // 좌표 합이 짝수
                    if (sum % 2 == 0 && board[xx][yy] == 'B')
                        cnt++;
                    // 좌표 합이 홀수
                    else if (sum % 2 == 1 && board[xx][yy] == 'W')
                        cnt++;
                }
            }
            // 카운트 누적 값 계산
            cnt = min(cnt, 64 - cnt);
            // 최소값 저장
            result = min(cnt, result);
        }
    }
    cout << result;

    return 0;
}