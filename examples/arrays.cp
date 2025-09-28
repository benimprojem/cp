#include "io.h"

int main() {
    // Dizi tanımlamaları
    i32 numbers[5] = (1, 2, 3, 4, 5);
    char chars[] = ('A', 'B', 'C', 'D');
    str names[] = ("Ali", "Veli", "Ayşe");
    
    // Dizi elemanlarına erişim
    print("İlk sayı: ", numbers[0], n);
    print("Son sayı: ", numbers[4], n);
    
    // Dizi uzunluğu
    i32 count = arrlen(numbers);
    print("Sayı dizisinin uzunluğu: ", count, n);
    
    // Dizi elemanlarını döngü ile yazdırma
    print("Sayılar: ");
    for (i32 i = 0 : i < arrlen(numbers) : i++) {
        print(numbers[i], " ");
    }
    print(n);
    
    print("Karakterler: ");
    for (i32 i = 0 : i < arrlen(chars) : i++) {
        print(chars[i], " ");
    }
    print(n);
    
    print("İsimler: ");
    for (i32 i = 0 : i < arrlen(names) : i++) {
        print(names[i], " ");
    }
    print(n);
    
    return 0;
}
