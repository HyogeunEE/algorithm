// BOJ 1949 우수 마을
#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("../input.txt", "r", stdin);

    int num;
    cin >> num;
    vector<int> person(num + 1);
    vector<vector<int> > vilage(num + 1);
    int a, b;
    for (int i = 1; i <= num; i++)
        cin >> person[i];
    for (int i = 1; i <= num; i++) {
        cin >> a >> b;
        vilage[a].push_back(b);
        vilage[b].push_back(a);
    }
    // [0] 우수마을이 아닐경우
    // [1] 우수마을 일경우
    vector<int[2]> ws(num + 1);
    ws[1][0] =
    for(int i = 1; i <= num; i++){

    }

    return 0;
}