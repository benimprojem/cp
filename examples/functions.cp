#include "io.h"

i32 add(i32 x, i32 y) {
    return x + y;
}

i32 factorial(i32 n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

void print_numbers(i32 start, i32 end) {
    for (i32 i = start : i <= end : i++) {
        print(i, " ");
    }
    print(n);
}

int main() {
    i32 result = add(5, 3);
    print("5 + 3 = ", result, n);
    
    i32 fact = factorial(5);
    print("5! = ", fact, n);
    
    print("1'den 10'a kadar sayılar: ");
    print_numbers(1, 10);
    
    return 0;
}
