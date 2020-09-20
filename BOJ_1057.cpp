// BOJ_1057 토너먼트
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    int person1, person2;
    cin >> num >> person1 >> person2;

    // 1~N 범위를 0~N-1로 변환
    person1--;
    person2--;

    int round = 0;
    // 두 수가 각각 2n과 2n+1이면 정답
    // 이때, 2로 나눴을 때 두 수가 같아지므로 탈출 조건으로 설정
    while(person1 != person2){
        round++;
        person1 >>= 1;
        person2 >>= 1;
    }
    cout << round;

    return 0;
}