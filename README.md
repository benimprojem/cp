CPlus_Compiler 
CPlus Lang ayrıntıları ve yapısı: 
// dosya yapısı:
```
CPlus_Compiler/
│
├── src/                     # Kaynak kodlar       
│   ├── lexer.c  			 # Tokenizer ve lexer ile ilgili dosyalar
│   ├── parser.c      		 # Sözdizimi analizörü (parser)
│   ├── semantic.c      	 # Anam çözümleme ve doğrulama
│   ├── codegen.c        	 # Kod üretimi 
│   ├── optimizer.c       	 # Optimizasyon modülleri 
│   ├── utils.c              # Yardımcı fonksiyonar
│ 	└── main.c	             # Derleyiciyi başlatan ana dosya
│
├── include/                 # Başlık dosyaları (headers)
│   ├── lexer.h
│   ├── parser.h
│   ├── semantic.h
│   ├── codegen.h
│   ├── optimizer.h
│ 	└── utils.h 
│
├── lib/                     # Harici kütüphaneler veya bağımlılıklar
│   ├── io.h
│   ├── math.h
│   ├── string.h
│   ├── array.h
│   ├── memory.h
│   └── ... 
│
├── tests/                   # Tester ve örnek projeler
│
├── build/                   # Derleme çıktı dosyaları
│   ├── host/                # Yerel sistem için derleme dosyaları
│   ├── target/              # Hedef platform için derleme dosyaları
│   └── configs/             # Çeşiti platform konfigürasyonarı
│
├── configs/                 # Farklı platformlara özel yapılandırma dosyaları
│   ├── windows_config.json
│   ├── linux_config.json
│   ├── embedded_config.json
│   └── ... 
│
├── tools/                   # Çapraz derleme araçları veya scripter
│
├── docs/                    # Belgeler ve dökümantasyon
│   ├── examples/            # Kullanım örnekleri
│   └── ... 
│
├── README.md                # Proje açıklaması
│
└── Makefile   				 # Derleme yapısı
```

Her Dosyanın Rolü
main.c: Derleyiciyi başlatır, giriş alınır, ve diğer aşamaları yönetir.
lexer.c/h: Kaynak kodu karakter karakter okur, token'lara ayırır.
parser.c/h: Token'ları kullanarak sözdizimi ağacı (AST) oluşturur.
semantic.c/h: Anam kurallarını uygular, hata kontrolü.
codegen.c/h: Hedef kodu veya ara kodu üretir (ASM).
optimizer.c/h: Kod optimizasyonarı yapar.
utils.c/h: Yardımcı fonksiyonar (dizgi işlemleri, hata mesajları).



Eklenecekler:
0: diğer dillerin en iyi yöneri tek bir dilde birleşmeli. 
1: cp dil genişlentilmesi: sistem, ai, data manipülasyonu, oyun .. gibi bir çok alanda kullanılacak kütüphane dosyaları hazırlanmalı.
2: ASM kodları oluşturduğunda yeniden optimizasyon ve optimazasyon enaz 3 kez tekrarlanmalı. 
3: Çapraz derleme: linux, windows, .... heryerde çalışmalı.
4: Yapay zeka entegresi ve görsel derleyici IDE , ide kendine ait bir sistemi olmalı ve çapraz derleme bu sistemden çerilerek yapılmalı.
5: 

////////////////////////////////////////////////////////////////////

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

Bitwise operators  
Operators	Meaning of operators
```
&	Bitwise AND
|	Bitwise OR
^	Bitwise exclusive OR
~	Bitwise complement
<<	Shift left
>>	Shift righ
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



makrolar için
```
# derleyici makroları için
```




Değişkenere isim vermenin genel kuralları şunardır :

İsimler harf, rakam ve alt çizgi içerebilir
İsimler bir harf ile başlamalıdır
İsimler büyük/küçük harfe duyarlıdır ( myVar ve myvar farklı değişkenerdir)
İsimler boşluk veya !, #, %, vb. gibi özel karakterler içeremez.
Ayrılmış kelimeler (örneğin int) isim olarak kullanılamaz

//Types :
```
i8, i16, i32, i64, i128
u8, u16, u32, u64, u128
f8, f16, f32, f64, f128

int     // int = i32 
char 	// Tek karakter  utf8
str 	// Karakter dizisi  utf8
arr		// Array
array   // Array
varName[]	// varName Array variable
...		// Array.?
const	// Sabiter   const i32 myNum = 15; vb.
true 	//  true  = 1
false 	//  false = 0
void 	// değer döndürmeyen
as		//
<<		//  tür dönüşümleri için  u32 myNum << myNumber;

n		// print : new line
t		// print : tab


```


// Create variables
```
type variableName = value;

// number, char, text, array 

i32 myNum = 15;          // Integer (whole number)
f32 myFloatNum = 5.99;   // Floating point number

char myLetter = 'H';     // Character  utf8

char myText[] = "Hello"; // String  utf8

str myText = "Hello";	 // String  utf8

arr myArray = ([1,2,2,3,58]); // Array

myArray[2][5] = ([1,2,2,3,58],[1,2,2,3,58]);   // Array

```

// keywords
```
def   |  default
new
continue
break
go
main
func
return | ret
not
or
and
xor
if
elseif  | elif
else    | el
for
while
do
switch
group
match
try
catch
bool
this
register  | reg
export
nullptr

in
to
by
out
put




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

tür dönüşümleri
örnek:
```
i32 mynum = 22;
f32 myNum = 12.32

f32 mynum << mynum;
f32 sum = mynum + myNum;

i32 sum << sum;
print(sum);
```


// main() fonksiyonu çalıştıracak ana fonksiyon..

```
// derleyici başlık dosyaları. / lib/   klasörü içerisinde aranır.
#include(io, memory, string); // dosya_adı  .h yazılmaz. Gerçekte doyanın adı örnek olarak: io.h dir, bu isimle aranır. virgül ile ayrılarak birden fazla dosya eklenebilir.

// kullanıcı başlık dosyaları. / include/  yada inc/  klasörü içerisinde aranır.
#include (test.h, deneme.h, header.h); // dosya_adı.h  .h mutaka yazılmalıdır. kullanıcı tanımlı dosya demektir.
// dosyalar bulunamıyor ise hata üretir.


int main() {
	print("Hello World!");
	print("Hello World!",n); // texti ekrana bastıktan sonra yeni satıra geçer.
	print("Hello World! <n>am learning C <n>And it is awesome!"); // text içerisinde yeni satır anahtarı kullanımı.
	return 0;
}
```



koşullu ifadeler:

if		
else	
elseif	

kısa yazılış:
```
variable = (condition) ? expressionTrue : expressionFalse;

// iç içe geçmiş ifade 

variable = (condition) ? expression1True : ((condition) ? expression2True : expression2False);

```


Döngü, while belirtilen koşul sağlandığı sürece bir kod bloğunu tekrarlar true:
```
// örnek
int i = 0;
while (i < 5) {
  print(i, n);
  i++;
}
```

For Döngüsü
Bir kod bloğunda kaç kez döngü yapmak istediğinizi tam olarak bildiğinizde, döngü foryerine döngüyü kullanın while:

Sözdizimi
```
for (expression 1: expression 2: expression 3) {
  // code block to be executed
}
```
İfade 1, kod bloğunun yürütülmesinden önce (bir kez) yürütülür.

İfade 2, kod bloğunun yürütülmesi için koşulu tanımlar.

Kod bloğu yürütüldükten sonra ifade 3, (her seferinde) yürütülür.
```
// Örnek
i32 i;
for (i = 0: i < 5: i++) {
  print(i, n);
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
  print(i, n);
}
```


// switch fonksiyonu
```
switch (expression) {
	x:{
		// code block
    }
	y:{
		// code block
    }
	def:{
		// default code block
	}
}
```


// group fonksiyonu tanımlanması:
```
group group_name1(veriables) {
	// tanımlı fonsiyonar tüm değişkener yerine gerekli olanarı kullanır.
    y:{
        print(" adasd {veriable2}  swf {veriable3}");
		 // kod bloğu 2
		...
    }    
    z: func(veriable1, veriable2){
        // kod bloğu 3
		...
    }
    x: group(veriables) {
		// iç içe group tanımlanabilir.
		xx:{ 
			// kod bloğu 1
			...
		}    
		yy:{
			print(" adasd {veriable2}  swf {veriable3}");
			 // kod bloğu 2
			...
		}    
		zz: func(veriable1, veriable2){
			// kod bloğu 3
			...
		}
	}
	def:{
		// kod bloğu default
		...
		print("grouplamada hiçbir etiket olmazsa default olarak çalışır.");
	}
}
```
/ Kullanımı: 
/ ifade karşılaştırması yapmaz bunun yerine ifadeyi direkt olarak 
/ groupadı.etiket  gurubismi.  nokta işaretinden sonra etiket ile işaret edilen kod bloğunu çalıştırır.
/ group_name1.x group_name1  gurubun adını x de çalıştırılacak kod bloğunu ifade eder, ikisi nokta ile ayrılır.
/ tanımlanmamış bir etiket olursa hata verir. 
/ yukarıda ki örneğe göre group_name1.a(); hata verir.
```
group_name1.x(); // x deki kod bloğunu çalıştıracak.
group_name1.y(); // y deki kod bloğunu çalıştıracak.
group_name1.z(); // z deki kod bloğunu çalıştıracak.

group_name1.a(); // hata üretirir. 

group_name1();  // default kod bloğu..

group_name1.x.yy(); // iç içe group örneği.
group_name1.etiket.etiket(veriables);
```






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
bir dizenin uzunuğunu almak için şu fonksiyonu kullanabilirsiniz 

strlen()
```
str alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
print(strlen(alphabet),n);   // 26
```




2B Dizinin Öğelerine Erişim
İki boyutu bir dizinin bir elemanına erişmek için hem satırın hem de sütunun indeks numarasını belirtmeniz gerekir.

Bu ifade, matris dizisinin ilk satırındaki (0) ve üçüncü sütunundaki (2) elemanın değerine erişir .

Örnek 1 
```
arr matrix[2][3] = ([1, 4, 2], 
					[3, 6, 8]
					);

print( matrix[0][1]);  // 4
```

Örnek 2 
```
arr matrix2=( [1, 4, 2], 
			  [3, 6, 8]
			);

print( matrix2[0][2]);  // 2
```

3B Boyutu Diziler
İki boyuttan fazlasına sahip dizileri de bildirebilirsiniz, boyut sayısında belirli bir sınırlama yoktur.

Örnek 1 
```
// A 3D array with 2 blocks, each with 3 rows and 4 columns
arr example[2][3][4] =(	[ 
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


Kullanıcıdan girdi almak için şu fonksiyonu kullanabilirsiniz input(type değişken):
```
// Create an integer variable that will store the number we get from the user
int myNum;

// Ask the user to type a number
print("Type a number: ", n);

// Get and save the number the user types
input(int myNum);

// Output the number the user typed
print("Your number is: <myNum>", n);
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
int myFunction(i32 x, i32 y) {
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
print(int func(){ret x + y;});
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
  print("My number: {s1.myNum}<n>");
  print("My letter: {s1.myLetter}<n>");

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













io.h

// Print variables
Bir text "" içerisinde değişkeneri " {variable} " şeklinde veya " <variable>"  şeklinde kullan. 
/n
/t
/0  
gibi kaçış karakteri için <n>, <t>, <0>  kullan.. 

tüm string ler karakterler UTF8 olarak kodlanır kaydedilir.

Ters eğik çizgi ( \) kaçış karakteri özel karakterleri dize karakterlerine dönüştürür:

Escape character	Result	Description
```
\'	'	Single quote
\"	"	Double quote
\\	\	Backslash

```

```

print("number: {myNum}", n);
print("Float number: {myFloatNum}", n);
print("character: {myLetter}", n);
//  <n> new line code.  <2n>  2 new line
//  <t> tab line code.  <3t> 
\b	<b> Backspace
\f	<f> Form feed
\r	<r> Return
\v	<v> Vertical tab
\0	<0> Null character

print("number: {myNum} <n> Float number: {myFloatNum} <n> character: {myLetter}");

int x = 5;
int y = 6;
int sum = x + y;
print(sum); // just veriable
```

// input 
```
i32 myNum;
input(i32 myNum );
myNum = myNum * 2; 
print("Sayının karesi: {myNum}<n>");
```

/////////////////////////////////////////////////////////////////
