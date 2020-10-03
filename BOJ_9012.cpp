// BOJ 9012 괄호
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("../input.txt", "r", stdin);
    int T;
    cin >> T;

    while(T--){
        string str;
        cin >> str;
        int cnt = 0;

        for(int i = 0; i < str.size(); i++){
            if(str[i] == '(')
                cnt++;
            else
                cnt--;
            if(cnt < 0)
                break;
        }
        cout << (cnt == 0? "YES\n" : "NO\n");
    }

    return 0;
}