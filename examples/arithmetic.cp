#include "io.h"

int main() {
    i32 a = 10;
    i32 b = 5;
    
    i32 sum = a + b;
    i32 diff = a - b;
    i32 product = a * b;
    i32 quotient = a / b;
    i32 remainder = a % b;
    
    print("a = ", a, n);
    print("b = ", b, n);
    print("Toplam: ", sum, n);
    print("Fark: ", diff, n);
    print("Çarpım: ", product, n);
    print("Bölüm: ", quotient, n);
    print("Kalan: ", remainder, n);
    
    return 0;
}
