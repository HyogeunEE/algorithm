// BOJ 1012 유기농 배추
#include <bits/stdc++.h>

using namespace std;

vector<vector<bool> > cbg;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y){
    cbg[x][y] = false; // 방문 체크
    for(int i = 0; i < 4; i++) {
        if(cbg[x + dx[i]][y + dy[i]])
            dfs(x + dx[i], y + dy[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("../input.txt", "r", stdin);

    int tc;
    cin >> tc;
    while (tc--) {
        int X, Y, cbgCnt;
        cin >> X >> Y >> cbgCnt;
        // 배추가 심어진 위치를 담은 배열 (계산 편의상 +2씩 해줌)
        cbg = vector<vector<bool> >(X + 2, vector<bool>(Y + 2, false));
        int x, y;
        for (int i = 1; i <= cbgCnt; i++) {
            cin >> x >> y;
            cbg[x + 1][y + 1] = true; // 계산 편의상 +1씩 해줌
        }
        int result = 0;
        for(int i = 1; i <= X; i++){
            for(int j = 1; j <= Y; j++){
                if(cbg[i][j]) {
                    cbg[i][j] = false;
                    dfs(i, j);
                    result++;
                }
            }
        }
        cout << result << '\n';
    }

    return 0;
}