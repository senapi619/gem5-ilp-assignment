#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
int main() {
    const size_t N = 50 * 1024 * 1024; // 50MB
    char *a = (char*)malloc(N);
    if (!a) return 1;

    for (size_t i = 0; i < N; i += 64) a[i] = (char)(i);
    volatile uint64_t sum = 0;
    for (size_t r = 0; r < 20; r++) {
        for (size_t i = 0; i < N; i += 64) sum += a[i];
    }

    printf("%llu\n", (unsigned long long)sum);
    free(a);
    return 0;
}
