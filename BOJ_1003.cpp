// BOJ 1003 피보나치 함수
#include <bits/stdc++.h>

using namespace std;
int fbnc[40];

int fib(int num) {
    if (fbnc[num] != 0)
        return fbnc[num];
    return fbnc[num] = fib(num - 1) + fib(num - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        int input;
        cin >> input;
        fbnc[0] = 1;
        fbnc[1] = 1;

        if (input == 0)
            cout << "1 0\n";
        else if (input == 1)
            cout << "0 1\n";
        else {
            fib(input);
            cout << fbnc[input - 2] << " " << fbnc[input - 1] << "\n";
        }
    }

    return 0;
}
