#include <stdio.h>
#include <stdint.h>
int main() {
    volatile uint64_t sum = 0;
    for (uint64_t i = 0; i < 200000000ULL; i++) {
        sum += (i * 3) ^ (i >> 2);
    }
    printf("%llu\n", (unsigned long long)sum);
    return 0;
}
