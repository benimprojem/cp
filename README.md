

aritmatik oparatörler
```
+	Addition	Adds together two values	x + y	
-	Subtraction	Subtracts one value from another	x - y	
*	Multiplication	Multiplies two values	x * y	
/	Division	Divides one value by another	x / y	
%	Modulus	Returns the division remainder	x % y	
++	Increment	Increases the value of a variable by 1	x++
--	Decrement	Decreases the value of a variable by 1	x--
```

atama oparatörleri
```
=	x = 5	x = 5	
+=	x += 3	x = x + 3	
-=	x -= 3	x = x - 3	
*=	x *= 3	x = x * 3	
/=	x /= 3	x = x / 3	
%=	x %= 3	x = x % 3	
&=	x &= 3	x = x & 3	
|=	x |= 3	x = x | 3	
^=	x ^= 3	x = x ^ 3	
>>=	x >>= 3	x = x >> 3	
<<=	x <<= 3	x = x << 3
```
karşılaştırma oparatörleri
```
==	Equal to	x == y	Returns 1 if the values are equal	
!=	Not equal	x != y	Returns 1 if the values are not equal	
>	Greater than	x > y	Returns 1 if the first value is greater than the second value	
<	Less than	x < y	Returns 1 if the first value is less than the second value	
>=	Greater than or equal to	x >= y	Returns 1 if the first value is greater than, or equal to, the second value	
<=	Less than or equal to	x <= y	Returns 1 if the first value is less than, or equal to, the second value
```
mantıksal oparatörler
```
&& 	AND	x < 5 &&  x < 10	Returns 1 if both statements are true	
|| 	OR	x < 5 || x < 4	Returns 1 if one of the statements is true	
!	NOT	!(x < 5 && x < 10)	Reverse the result, returns 0 if the result is 1	
```
oparatör önceliği
en yüksek öncelikten en düşük önceliğe doğru,
öncelik eşit ise soldan sağa doğru işlenir.
```
()		- Parantezler
*, /, %	- Çarpma, Bölme, Modül
+, -	- Toplama, Çıkarma
>, <, >=, <=	- Karşılaştırmak
==, !=	- Eşitik
&&		- Mantıksal VE
||		- Mantıksal VEYA
=  		- Atama
```

```
# derleyici makroları için
```


Değişkenere isim vermenin genel kuralları şunardır :

İsimler harf, rakam ve alt çizgi içerebilir
İsimler bir harf ile başlamalıdır
İsimler büyük/küçük harfe duyarlıdır ( myVar ve myvar farklı değişkenerdir)
İsimler boşluk veya !, #, %, vb. gibi özel karakterler içeremez.
Ayrılmış kelimeler (örneğin int) isim olarak kullanılamaz
```
//Types :
i8, i16, i32, i64, i128, i256, i512 
u8, u16, u32, u64, u128, u256, u512 
f8, f16, f32, f64, f128, f256, f512 

char 	// Tek karakter
str 	// Karakter dizisi
arr		// Array
array   // Array
varName[]	// varName Array variable
...		// Array..?
```


// değişkener.
```
type variableName = value;
// number, char, text, array 
i32 myNum = 15;
char myText = "H";
char myText[] = "Hello";
str myText = "Hello";
arr myArray = (1,2,2,3,58); 
myArray[] = (1,2,2,3,58); 
```
```
// Create variables
i32 myNum = 15;            // Integer (whole number)
f32 myFloatNum = 5.99;   // Floating point number
char myLetter = 'D';       // Character

const	// Sabiter   const i32 myNum = 15; vb.
true 	//  true  = 1
false 	//  false = 0
void 	// null değer döndürmeyen
int     //  int = i32 
```

// keywords
```
def
new
continue
break
goto
func

return
not
or
and
xor

...
```
Yorum satırları
çok satırlı  yorum için
```
/*   */  

/* 
çok satırlı
yorumlar
 */
```
tek satırlı yorum içinde
```
//  tek satırlık 
```

Ters eğik çizgi ( \) kaçış karakteri özel karakterleri dize karakterlerine dönüştürür:

Escape character	Result	Description
```
\'	'	Single quote
\"	"	Double quote
\\	\	Backslash
```


// Print variables
Bir text alanı "" içerisinde değişkeneri " {variable} " şeklinde veya " <variable>"  şeklinde kullan. 
/nl 
/tl
/0  
gibi kaçış karakteri için <nl>, <tl>, <0>  kullan.. 

```
print("number: {myNum}", nl);
print("Float number: {myFloatNum}", nl);
print("character: {myLetter}", nl);

// new print func echo "";
//  <n> new line code.  <2nl>  
//  <t> tab line code.  <3tl> 
echo"number: {myNum} <nl> Float number: {myFloatNum} <nl> character: {myLetter}";

int x = 5;
int y = 6;
int sum = x + y;
print(sum);
```

```
#include "io.h"

int main() {
	print("Hello World!");
	print("Hello World!",nl); // texti ekrana bastıktan sonra yeni satıra geçer.
	print("Hello World! <nl>am learning C <nl>And it is awesome!"); // text içerisinde yeni satır anahtarı kullanımı.
	return 0;
}
```

koşullu ifadeler bulunur:

if		Belirtilen bir koşul yerine getirildiğinde yürütülecek kod bloğunu belirtmek için kullanılırtrue
else	Aynı koşul sağlandığında yürütülecek kod bloğunu belirtmek için kullanılırfalse
elseif	İlk koşul doğruysa, test edilecek yeni bir koşulu belirtmek için kullanılırfalse
```
variable = (condition) ? expressionTrue : expressionFalse;
```

switch	Yürütülecek birçok alternatif kod bloğunu belirtmek için kullanılır
```
switch (expression) {
	x:{
    // code block
    }
	y:{
    // code block
    }
	def:{
    // code block default
	}
}
```
// group fonksiyonu tanımlanması:
```
group group_name1(...veriable) {
	// tanımlı fonsiyonar tüm değişkener yerine gerekli olanları kullanır.
    y:{
        print(" adasd {veriable[2]}  swf {veriable[3]}");
		 // kod bloğu 2
		...
    }    
    z: func(veriable[1], veriable[2]){
        // kod bloğu 3
		...
    }
    x: group group_name1(...veriable) {
		// iç içe group tanımlanabilir.
		xx:{ 
			// kod bloğu 1
			...
		}    
		yy:{
			print(" adasd {veriable[2]}  swf {veriable[3]}");
			 // kod bloğu 2
			...
		}    
		zz: func(veriable[1], veriable[2]){
			// kod bloğu 3
			...
		}
	}
}
```
/ Kullanımı: ama bir farkı vardır. 
/ ifade karşılaştırması yapmaz bunun yerine ifadeyi direkt olarak 
/ groupadı.etiket  gurubismi.  nokta işaretinden sonra etiket ile işaret edilen kod bloğunu çalıştırır.
/ group_name1.x group_name1  gurubun adını x de çalıştırılacak kod bloğunu ifade eder, ikisi nokta ile ayrılır.
/ tanımlanmamış bir etiket olursa hata verir. 
/ yukarıda ki örneğe göre group_name1.a(); hata verir.
```
group_name1.x(değişkener); // x deki kod bloğunu çalıştıracak.
group_name1.y(değişkener); // y deki kod bloğunu çalıştıracak.
group_name1.z(değişkener); // z deki kod bloğunu çalıştıracak.


group_name1.a(değişkener); // hata üretirir. 

group_name1.x.yy(değişkenler); // iç içe group örneği.

group_name1."(etiket=group_name)".etiket(veriables);
```


Döngü, while belirtilen koşul sağlandığı sürece bir kod bloğunu tekrarlar true:
```
// örnek
int i = 0;
while (i < 5) {
  print(i, nl);
  i++;
}
```

For Döngüsü
Bir kod bloğunda kaç kez döngü yapmak istediğinizi tam olarak bildiğinizde, döngü foryerine döngüyü kullanın while:

Sözdizimi
```
for (expression 1; expression 2; expression 3) {
  // code block to be executed
}
```
İfade 1, kod bloğunun yürütülmesinden önce (bir kez) yürütülür.

İfade 2, kod bloğunun yürütülmesi için koşulu tanımlar.

Kod bloğu yürütüldükten sonra ifade 3 (her seferinde) yürütülür.
```
// Örnek
int i;
for (i = 0: i < 5: i++) {
  print(i, nl);
}
```

break= döngüyü tamamen durdur.
continue= bu turu ata ama döngüye devam et.
```
// Örnek
int i;
for (i = 0: i < 6: i++) {
  if (i == 2) {
    continue;
  }
  if (i == 4) {
    break;
  }
  print(i, nl);
}
```
foreach, hem dizini dizilerle hem de ilişkisel dizilerle kullanılabilir. 
İki tür kullanım söz dizimi mevcuttur:
Dizini Diziler için Sözdizimi
Sözdizimi aşağıdadır:
```
foreach (array as $value) {
   statements
}
```
Yukarıdaki yöntem, dizini bir diziyi yinelemek istediğinizde kullanışlıdır. 
Aşağıdaki sözcükleri ise ilişkisel diziler için daha uygundur.

İlişkisel Diziler için Sözdizimi
Aşağıdaki kelimeleri inceleyin –
```
foreach (array as $key => $value) {
   statements
}
```
Ancak her iki yaklaşım da dizini dizilerde iyi çalışır, çünkü dizideki bir öğenin dizisi aynı zamanda anahtar işlevini görür.





Bir Dizinin Elemanarına Erişim
Bir dizi öğesine erişmek için, onun dizin numarasına bakın .
Dizi dizineri 0 ile başlar : [0] ilk öğedir. [1] ikinci öğedir, vb.
Bu ifade , şu öğenin ilk öğesinin [0] değerine erişir : myNumbers
```
Örnek
int myNumbers[] = (25, 50, 75, 100);
print(myNumbers[0]);

// Outputs 25
```

// Declare an array of four integers:
```
int myNumbers[4];

// Add elements
myNumbers[0] = 25;
myNumbers[1] = 50;
myNumbers[2] = 75;
myNumbers[3] = 100;
```
```
int myNumbers = ([10, 25, 50, 75, 100]);

print( sizeof(myNumbers));  // Prints 20
```
sizeof operatör bir türün boyutunu bayt cinsinden döndürür 
```
int myNumbers = ([10, 25, 50, 75, 100]);
int length = arrlen(myNumbers);

print(length);  // Prints 5
```

arrlen operatörü dizideki eleman sayısını döndürür 

```
i64 veriable = ...veriables;

// iki diziyi birleştirmek.
i64 myNumber = ([ 70, 120, ...myNumbers]);
```



2B Dizinin Öğelerine Erişim
İki boyutu bir dizinin bir elemanına erişmek için hem satırın hem de sütunun indeks numarasını belirtmeniz gerekir.

Bu ifade, matris dizisinin ilk satırındaki (0) ve üçüncü sütunundaki (2) elemanın değerine erişir .

Örnek 1 
```
int matrix[2][3] = ([1, 4, 2], 
					[3, 6, 8]
					);

print( matrix[0][2]);  // Outputs 2
```

Örnek 2 
```
int matrix2=( [1, 4, 2], 
			  [3, 6, 8]
			);

print( matrix2[0][2]);  // Outputs 2
```

3B Boyutu Diziler
İki boyuttan fazlasına sahip dizileri de bildirebilirsiniz, boyut sayısında belirli bir sınırlama yoktur.

Örnek 1 
```
// A 3D array with 2 blocks, each with 3 rows and 4 columns
int example[2][3][4] =(	[ 
							[3, 6, 8, 7], 
							[3, 6, 8, 7], 
							[3, 6, 8, 7]
						],[ 
							[3, 6, 8, 7], 
							[3, 6, 8, 7], 
							[3, 6, 8, 7]
						]
					);
```

strings  
```
char myText[] = "Hello";
str myText = "Hello";
```
her ikiside aynıdır bir bakıma. string lere array gibi işlemler yapabilirsiniz.


örnek:
```
str txt = "We are the so-called \"Vikings\" from the north.";
```
bir dizenin uzunuğunu almak için şu fonksiyonu kullanabilirsiniz strlen()
```
str alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
print(strlen(alphabet),nl);   // 26
```


Kullanıcıdan girdi almak için şu fonksiyonu kullanabilirsiniz input(type değişken):
```
// Create an integer variable that will store the number we get from the user
int myNum;

// Ask the user to type a number
print("Type a number: ", nl);

// Get and save the number the user types
input(int myNum);

// Output the number the user typed
print("Your number is: <myNum>",nl);
```

bir değişken oluşturulduğunda, değişkene bir bellek adresi atanır.
Bellek adresi değişkenin bilgisayarda saklandığı yerdir.
Değişkene bir değer atadığımızda bu değer bu bellek adresinde saklanır.
Buna erişmek için referans operatörünü ( &) kullanın ve sonuç değişkenin nerede saklandığını gösterir:

Örnek
```
int myAge = 43;
print(&myAge); // Outputs 0x7ffe5367e044
```

İşaretçi , başka bir değişkenin bellek adresini değeri olarak saklayan bir değişkendir 
Bir işaretçi değişkeni, aynı türdeki bir veri türünü (örneğin int*) işaret eder ve operatör ile oluşturulur.
Çalıştığınız değişkenin adresi işaretçiye atanır:

Örnek
```
int myAge = 43;     // An int variable
int* ptr = &myAge;  // A pointer variable, with the name ptr, that stores the address of myAge

// Output the value of myAge (43)
print(myAge);

// Output the memory address of myAge (0x7ffe5367e044)
print(&myAge);

// Output the memory address of myAge with the pointer (0x7ffe5367e044)
print(ptr);

// Dereference: Output the value of myAge with the pointer (43)
print(*ptr);
```


Kendi fonksiyonunuzu oluşturmak için (genellikle declare olarak adlandırılır ), 
fonksiyonun adını belirtin, ardından parantez () ve süslü parantezler kullanın {}:

Sözdizimi
```
returnType functionName(type parameter1, type parameter2, type parameter3) {
  // code to be executed
}
```

örnek1
```
int myFunction(int x, int y) {
  return x + y;
}
```
örnek2
```
void myFunction() {
  // code to be executed
}
```
Örnek2 Açıklaması
myFunction()fonksiyonun adıdır
void fonksiyonun bir dönüş değeri olmadığı anamına gelir. Dönüş değerleri hakkında daha fazla bilgiyi bir sonraki bölümde öğreneceksiniz.
Fonksiyonun (gövde) içine, fonksiyonun ne yapması gerektiğini tanımlayan kodu ekleyin.


başka bir tanımlama şekli geri dönüşleri bir değişkene veya fonksiyona aktaran 
isimsiz fonksiyon tanımlaması
genel bir fonksiyon olmadığı veya 
sadece tek bir yerde çalışması gerektiğinde, hız için iyi kullanımı şeklidir.

bir değişkene atama..
```
int myFunction = func() {
  return x + y;
}
```
fonksiyon içerisinde kullanma daha kısa..
```
print(int func(){return x + y;});
```



Yapılar

Yapılar birbiriyle ilişkili birkaç değişkeni tek bir yerde gruplandırmanın bir yoludur.
Yapıdaki her değişkene yapının bir üyesi denir
Bir dizininint aksine, bir yapı birçok farklı veri türünü ( char, float, int, vb.) içerebilir .

Bir Yapı Oluşturun
Anahtar kelimeyi kullanarak bir yapı oluşturabilir struct ve her bir üyesini süslü parantezler içinde bildirebilirsiniz:
```
struct MyStructure {   // Structure declaration
  int myNum;           // Member (int variable)
  char myLetter;       // Member (char variable)
}; // End the structure with a semicolon
```
Yapıya erişebilmek için, yapının bir değişkenini oluşturmanız gerekir.
structYöntemin içinde anahtar kelimeyi kullanın main(), ardından yapının adını ve yapı değişkeninin adını yazın:

"s1" adında bir yapı değişkeni oluşturun:
```
struct myStructure {
  int myNum;
  char myLetter;
};

int main() {
  struct myStructure s1;
  return 0;
}
```
Erişim Yapısı Üyeleri
Bir yapının üyelerine erişmek için nokta sözdizimini ( .) kullanın:

Örnek
```
// Create a structure called myStructure
struct myStructure {
  int myNum;
  char myLetter;
};

int main() {
  // Create a structure variable of myStructure called s1
  struct myStructure s1;

  // Assign values to members of s1
  s1.myNum = 13;
  s1.myLetter = 'B';

  // Print values
  printf("My number: %d\n", s1.myNum);
  printf("My letter: %c\n", s1.myLetter);

  return 0;
}
```
Artık tek bir yapı kullanarak farklı değerlere sahip birden fazla yapı değişkenini kolayca oluşturabilirsiniz:

Örnek
```
// Create different struct variables
struct myStructure s1;
struct myStructure s2;

// Assign values to different struct variables
s1.myNum = 13;
s1.myLetter = 'B';

s2.myNum = 20;
s2.myLetter = 'C';
```



Enum 
 sabiterin (değiştirilemeyen değerlerin) bir grubunu temsil eden özel bir türdür.
Bir enum oluşturmak için enumanahtar kelimeyi kullanın, ardından enum adını yazın ve enum öğelerini virgülle ayırın:
```
enum Level {
  LOW,
  MEDIUM,
  HIGH
};
```
Son maddede virgüle gerek olmadığını unutmayın.

Büyük harf kullanmak zorunu değildir, ancak çoğu zaman iyi bir uygulama olarak kabul edilir.
Enum, "özellikle listelenmiş" anamına gelen "enumerations" kelimesinin kısaltmasıdır.
Enuma erişmek için, onun bir değişkenini oluşturmanız gerekir.

Yöntemin içinde main(), enumanahtar kelimeyi belirtin, ardından enum ( ) adını Levelve enum değişkeninin adını ( myVarbu örnekte) belirtin:

enum Level myVar;
Artık bir enum değişkeni ( ) oluşturduğunuza göre myVar, ona bir değer atayabilirsiniz.
LOWAtanan değer, enum ( , MEDIUMveya ) içindeki öğelerden biri olmalıdır HIGH:

enum Level myVar = MEDIUM;
Varsayılan olarak, ilk öğe ( LOW) değerine 0, ikinci öğe ( MEDIUM) değerine 1vb. sahiptir.
Şimdi myVar'ı yazdırmaya çalışırsanız, 1şunu temsil eden çıktıyı alırsınız MEDIUM:
```
int main() {
  // Create an enum variable and assign a value to it
  enum Level myVar = MEDIUM;

  // Print the enum variable
  print(myVar);

  return 0;
}
```
Değerleri Değiştir
Bildiğiniz gibi, bir enum'un ilk öğesinin değeri 0'dır. İkinci öğenin değeri 1'dir ve bu böyle devam eder.

Değerleri daha iyi anamak için onarı kolayca değiştirebilirsiniz:
```
enum Level {
  LOW = 25,
  MEDIUM = 50,
  HIGH = 75
};
print(myVar); // Now outputs 50
```
Belirli bir öğeye bir değer atarsanız, sonraki öğelerin numaralarının buna göre güncelleneceğini unutmayın:
```
enum Level {
  LOW = 5,
  MEDIUM, // Now 6
  HIGH // Now 7
};
```


Dynamic Memory
```
int* ptr = memnew int;
*ptr = 35;
print( *ptr);
```
Açıklama:
memnew int bir tam sayı için bellek alanı oluşturur
ptr o alanın adresini depolar
*ptr = 35; 35 sayısını depolar
print( *ptr); değeri yazdırır

Yani memnew hafızayı oluşturuyorduk ve ptr ona erişiyorduk.

memdel Anahtar Kelimesi
Bir şey yarattığınızda newişiniz bittiğinde onu kaldırmak sizin görevinizdir.

Bunu yapmak için şunu kullanın memdel:

Örnek
```
memdel ptr;
```

/////////////////////////////////////////////////////////////////
```
CPLang/
├── src/
│   ├── main.c               # Giriş noktası (derleyiciyi başlatır)
│   ├── parser.c             # Söz dizimi ve sözdizimi analizi
│   ├── lexer.c              # Tokenizer (söz çözücü)
│   ├── semantic.c           # Anlam analizi
│   ├── codegen.c            # Hedef kod üretimi
│   ├── optimizer.c          # Optimizasyon aşamaları
│   └── utils.c              # Yardımcı fonksiyonlar
├── include/
│   ├── parser.h
│   ├── lexer.h
│   ├── semantic.h
│   └── codegen.h
├── lib/                      # Dış kütüphaneler
│   ├── compiler.h
│   ├── io.h
│   ├── memory.h
│   └── string.h
├── examples/                 # Kullanım örnekleri
├── tests/                    # Testler
├── README.md
├── Makefile                  # Derleme scriptleri
└── docs/                     # Belgeler, dil söz dizimi ve kılavuzlar
```
Her Dosyanın Rolü
main.c: Derleyiciyi başlatır, giriş alınır, ve diğer aşamaları yönetir.
lexer.c/h: Kaynak kodu karakter karakter okur, token'lara ayırır.
parser.c/h: Token'ları kullanarak sözdizimi ağacı (AST) oluşturur.
semantic.c/h: Anlam kurallarını uygular, hata kontrolü.
codegen.c/h: Hedef kodu veya ara kodu üretir (örneğin, C kodu veya bytecode).
optimizer.c/h: Kod optimizasyonları yapar.
utils.c/h: Yardımcı fonksiyonlar (dizgi işlemleri, hata mesajları).

Basit Bir Derleyici İş Akışı (Özet)
Giriş: Kullanıcıdan .mlang uzantılı kaynak kod alınır.
Lexing: Kaynak kod, token'lara ayrılır.
Parsing: Token'lar kullanılarak AST oluşturulur.
Semantic Analysis: Değişkenler, fonksiyonlar ve anlam kuralları kontrol edilir.
Kod Üretimi: Hedef dil veya çalışma ortamına uygun kod üretilir.
Çıktı: Derlenmiş veya çalıştırılabilir bir dosya oluşturulur.







Eklenecekler:
0: diğer dillerin en iyi yönleri tek bir dilde birleşmeli. 
1: cp dil genişlentilmesi: sistem, ai, data manipülasyonu, oyun .. gibi bir çok alanda kullanılacak kütüphane dosyaları hazırlanmalı.
2: ASM kodları oluşturduğunda yeniden optimizasyon ve optimazasyon enaz 3 kez tekrarlanmalı. 
3: Çapraz derleme: linux, windows, .... heryerde çalışmalı.
4: Yapay zeka entegresi ve görsel derleyici IDE , ide kendine ait bir sistemi olmalı ve çapraz derleme bu sistemden çerilerek yapılmalı.
5: 
