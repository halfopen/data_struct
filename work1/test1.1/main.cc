#include <cstdlib>
#include <cstdio>
#include <ctime>
#include "nprimes.h"

int main(int argc, char* argv[]) {
    // 判断参数是否为空
    if (argc < 2) {
        fprintf(stderr, "usage: %s <n>\n", argv[0]); 
        exit(-1);
    }

    // 将每一个参数作为输入 n
    int n = atoi(argv[1]);
    
    clock_t start_clock = clock();
    int n_primes = PrintPrimes(n);
    clock_t end_clock = clock();
    
    // 输出素数个数
    printf("-----------------------------\n");
    printf("find %d primes in %.3f s.\n", n_primes, 
            1.0 * (end_clock - start_clock) / CLOCKS_PER_SEC);

    // 正常结束
    return 0;
}
