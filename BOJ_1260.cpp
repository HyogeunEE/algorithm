// BOJ 1260 DFS와 BFS
#include <bits/stdc++.h>

using namespace std;

vector<int> node[1001]; // 그래프
bool visited[1001];     // 방문 체크
queue<int> qq;         // BFS용 큐

void dfs(int num) {
    if (!visited[num])
        sort(node[num].begin(), node[num].end());
    visited[num] = true;
    for (int i : node[num]) {
        if (!visited[i]) {
            cout << i << " ";
            dfs(i);
        }
    }
}

void bfs(int num) {
    qq.push(num);
    visited[num] = true; // 첫항
    while (!qq.empty()) {
        int nn = qq.front();
        qq.pop(); // poll
        if (!visited[nn])
            sort(node[nn].begin(), node[nn].end());
        for (int i: node[nn]) {
            if (!visited[i]) {
                visited[i] = true;
                cout << i << " ";
                qq.push(i);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("../input.txt", "r", stdin);

    // 입력
    int num, edg, ptr;
    cin >> num >> edg >> ptr;
    int a, b;
    for (int i = 0; i < edg; i++) {
        cin >> a >> b;
        // 양방향 그래프 만들기
        node[a].push_back(b);
        node[b].push_back(a);
    }

    memset(visited, false, sizeof(visited));
    cout << ptr << " ";
    dfs(ptr);
    cout << "\n";

    memset(visited, false, sizeof(visited));
    cout << ptr << " ";
    bfs(ptr);

    return 0;
}