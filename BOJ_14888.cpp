// BOJ_14888 연산자 끼워넣기
#include <iostream>
#include <vector>

using namespace std;

int N; // 숫자 갯수
vector<int> arr; // 숫자 배열
int oper[4]; // + - * / 연산자 갯수

int maxNum = INT32_MIN;
int minNum = INT32_MAX;

int min(int a, int b) {
    return a > b ? b : a;
}

int max(int a, int b) {
    return a > b ? a : b;
}

struct info {
    int idx; // 현재 탐색중인 인덱스
    int pl; // 덧셈 연산자 갯수
    int mi; // 뺄셈 연산자 갯수
    int mul;// 곱셈 연산자 갯수
    int div;// 나눗셈 연산자 갯수
    int result; // 현재 누적 연산자 갯수

    // 초기화를 위한 생성자
    info(int a, int b, int c, int d, int e, int f)
            : idx(a), pl(b), mi(c), mul(d), div(e), result(f) {};

    // 다음 노드의 연산 결과를 만들어주는 생성자
    info(info &node, string a) {
        // node로 부터 받은 값 저장
        idx = node.idx;
        pl = node.pl;
        mi = node.mi;
        mul = node.mul;
        div = node.div;
        result = node.result;
        // 연산 결과를 저장함과 동시에 idx 증가
        if (a == "pl") {
            result += arr[++idx];
            pl--;
        }
        else if (a == "mi") {
            result -= arr[++idx];
            mi--;
        }
        else if (a == "mul") {
            result *= arr[++idx];
            mul--;
        }
        else if (a == "div") {
            result /= arr[++idx];
            div--;
        }
    }
};

void dfs(info node) {
    // 각 연산 수행
    if (node.pl > 0)
        dfs({node, "pl"});
    if (node.mi > 0)
        dfs({node, "mi"});
    if (node.mul > 0)
        dfs({node, "mul"});
    if (node.div > 0)
        dfs({node, "div"});
    // 최대값, 최소값 저장
    if (node.idx >= N - 1) {
        maxNum = max(maxNum, node.result);
        minNum = min(minNum, node.result);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("../input.txt", "r", stdin);

    cin >> N;
    arr = vector<int>(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    for (int i = 0; i < 4; i++)
        cin >> oper[i];

    info init = {0, oper[0], oper[1], oper[2], oper[3], arr[0]};
    dfs(init);

    cout << maxNum << "\n" << minNum;

    return 0;
}