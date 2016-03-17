#include "endo/fib.hpp"

int fib(int n) {
    int cur = 1;
    int last = 0;
    for (int i = 1; i < n; ++i) {
        int tmp = cur;
        cur += last;
        last = tmp;
    }
    return cur;
}
