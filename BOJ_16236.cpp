// BOJ_16236 아기 상어
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

struct pt {
    int x, y;
    int len; // 상어의 이동거리

    const bool operator<(const pt &p) const {
        // 1. len 비교
        if (len == p.len) {
            // 2. x 좌표 비교
            if (x == p.x)
                // 3. y 좌표 비교
                return y > p.y;
            return x > p.x;
        }
        return len > p.len;
    }
};

struct shark {
    int x, y;
    int cnt = 0;
    int size = 2;

    shark() {}

    shark(int x, int y) {
        this->x = x;
        this->y = y;
    }

    void sizeUp() {
        cnt = 0;
        size++;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("../input.txt", "r", stdin);

    int N;
    cin >> N;

    vector<vector<int> > arr(N + 2, vector<int>(N + 2, INT32_MAX));
    vector<vector<bool> > visited(N + 2, vector<bool>(N + 2, false));

    shark baby;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 9) {
                baby = {i, j}; // 상어 좌표 저장
                arr[i][j] = 0;  // 해당 자리는 빈칸으로
            }
        }
    }

    int result = 0;
    priority_queue<pt> Q;
    Q.push({baby.x, baby.y, 0});
    visited[baby.x][baby.y] = true;

    while (!Q.empty()) {
        pt cur = Q.top();
        Q.pop();
        // 먹을 수 있는 물고기라면
        if (arr[cur.x][cur.y] != 0 && baby.size > arr[cur.x][cur.y]) {
            // 좌표 이동
            baby.x = cur.x;
            baby.y = cur.y;
            // 물고기 냠냠
            baby.cnt++;
            arr[cur.x][cur.y] = 0;
            // 물고기 먹은 갯수가 몸집에 도달시
            if (baby.cnt >= baby.size)
                baby.sizeUp();
            // 방문 초기화
            visited = vector<vector<bool> >(N + 2, vector<bool>(N + 2, false));
            // 큐 초기화
            while(!Q.empty()) Q.pop();
            // 정답 저장
            result = cur.len;
        }
        for (int i = 0; i < 4; i++) {
            // 다음 4방향 이동 좌표
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            // 아기 상어의 사이즈보다 크거나 방문했으면
            if (arr[nx][ny] > baby.size || visited[nx][ny])
                continue;
            // 방문 체크
            visited[nx][ny] = true;
            Q.push({nx, ny, cur.len + 1});
        }
    }
    cout << result;

    return 0;
}