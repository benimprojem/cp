#include "io.h"

int main() {
    // Farklı veri tipleri
    i8 small_int = 100;
    i32 regular_int = 1000000;
    i64 big_int = 1000000000000;
    
    f32 small_float = 3.14;
    f64 big_float = 3.141592653589793;
    
    char letter = 'A';
    str message = "Merhaba CP Dili!";
    
    // Sabitler
    const i32 MAX_VALUE = 100;
    
    // Yazdırma
    print("Küçük tam sayı: ", small_int, n);
    print("Normal tam sayı: ", regular_int, n);
    print("Büyük tam sayı: ", big_int, n);
    
    print("Küçük ondalık: ", small_float, n);
    print("Büyük ondalık: ", big_float, n);
    
    print("Karakter: ", letter, n);
    print("Mesaj: ", message, n);
    
    print("Maksimum değer: ", MAX_VALUE, n);
    
    return 0;
}
