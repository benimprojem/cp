#include "io.h"

int main() {
    i32 number = 15;
    
    // If-else yapısı
    if (number > 10) {
        print("Sayı 10'dan büyük", n);
    } else {
        print("Sayı 10'dan küçük veya eşit", n);
    }
    
    // While döngüsü
    print("While döngüsü: ");
    i32 i = 1;
    while (i <= 5) {
        print(i, " ");
        i++;
    }
    print(n);
    
    // For döngüsü
    print("For döngüsü: ");
    for (i32 j = 1 : j <= 5 : j++) {
        print(j, " ");
    }
    print(n);
    
    // Break ve continue
    print("Break ve continue örneği: ");
    for (i32 k = 1 : k <= 10 : k++) {
        if (k == 3) {
            continue; // 3'ü atla
        }
        if (k == 8) {
            break; // 8'de dur
        }
        print(k, " ");
    }
    print(n);
    
    return 0;
}
