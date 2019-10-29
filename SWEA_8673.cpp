// SWEA_8673 코딩 토너먼트1
#include<stdio.h>

#define MAXN 1025

inline int max(int a, int b){
    return a > b ? a : b;
}

inline int abs(int a){
    return a > 0 ? a : -a;
}

int num[MAXN];

int main() {
	int test_case;
	int T;
	
	scanf("%d", &T);
    
	for(test_case = 1; test_case <= T; ++test_case) {
        int N, total, sum = 0;
        scanf("%d", &N);
        total = 1 << N;
        for(int i = 0; i < total; i++)
            scanf("%d", &num[i]);
        
        for(int i = 0; i < N; i++){
            total >>= 1;
            for(int t = 0; t < total; t++){
                int& a = num[t*2];
                int& b = num[t*2+1];
                sum += abs(a-b);
                num[t] = max(a,b);
            }
        }
        printf("#%d %d\n", test_case, sum);
	}
	return 0;
}
