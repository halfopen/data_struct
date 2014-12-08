#include "nprimes.h"
#include <cstdio>
#include <cmath>

/* 判断一个整数是否为素数 */
bool IsPrime(int n) {
/* --------------  请在此处写你的实现  -------------- */
/* ------------ 你不用修改此区域外的内容 ------------ */
/* --------------- 也不要打印任何信息 --------------- */


	
    return false; 
/* -------------------------------------------------- */
}

/* 打印 n 以内 (包括 n) 的素数, 每 10 个换行, 返回素数的个数 */
int PrintPrimes(int n) {
    int prime_count = 0;

    for (int i = 0; i <= n; i++) {
        if (IsPrime(i)) {
            prime_count += 1;

#ifndef WORK_TEST
            printf("%7d ", i);
            if (prime_count % 10 == 0) {
                printf("\n");
            }
#endif
        } 
    }
#ifndef WORK_TEST
    // 若最后未满一行, 需额外输出一个换行符
    if (prime_count % 10 > 0) printf("\n");
#endif
    
    return prime_count;
}
