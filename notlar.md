_C++11_ standardı ile birlikte C++ diline _"attribute"_ (öznitelik) denilen bir sentaks öğesi eklendi.<br>  
_Attribute_'lar derleyici programa hitaben yazılan direktiflerdir. (Önişlemci programına değil).

attribute'ların temel amaçları
- derleyinin daha iyi bir kod üretmesine (daha iyi optimizasyon yapmasına) olanak sağlamak.
- kodlama hatası olabilecek bazı durumlarda derleyiciyi uyarı mesajı vermeye teşvik etmek.
- kodlama hatası gibi görünebilecek ama bilinçli olarak yazılmış bazı kodlarda derleyicinin uyarı meaajı vermemesini sağlamak.
- kodun daha anlaşılır olmasını sağlamak
- Derleyicilerin bazı "implementation defined" durumlarına yönelik açıklama yapmak


<!---



C'de derleyicinin kimi davranışları komut satırı argümanlarıyla ya da #pragma direktifi yardımıyla değiştirilebilmektedir. 
#pragma direktifi C'de standart bir direktif olmasına karşın direktifin	yanındaki komutlar derleyiciden derleyiciye değişebilmektedir.


44) C++11 ile birlikte diğer bazı dillerde çeşitli biçimlerde bulunan "öznitelikler (attributes)" konusu dile eklenmiştir. 
Öznitelikler derleyici için kullanılan direktiflerdir. 
Özniteliklerin temel amacı derleyicinin daha iyi kod üretmesini sağlamak, uyarı mekanizması üzerinde etkili olmak ve derleyicinin bazı davranışlarını değiştirmektir. 
C'de derleyicinin kimi davranışları komut satırı argümanlarıyla ya da #pragma direktifi yardımıyla değiştirilebilmektedir. 
#pragma direktifi C'de standart bir direktif olmasına karşın direktifin	yanındaki komutlar derleyiciden derleyiciye değişebilmektedir. Örneğin:

#pragma pack(1)

struct SAMPLE {
char a;
short b;
int c;
};

#pragma pack komutu yapı elemanlarının hizalanması üzerinde etkili olmaktadır. 
Bu pragma komutu pek çok derleyici tarafından desteklenmektedir. 
Ancak pek çok pragma direktifi ilgili derleyiciye hatta ilgili platforma özgü olabilmektedir.
C'de pragma direktifleri önişlemci aşamasında parse edilmektedir. 
Dolayısıyla zayıf bir kullanım alanına sahiptir. 
İşte öznitelikler bu pragram direktiflerinin standart ve genel bir biçimi gibi düşünülebilir. 

C++11 ile dile eklenen öznitelikler zaman içerisinde neredeyse tüm sentaktik öğelerde kullanılabilir duruma getirilmiştir. 
İzleyen paragraflarda tipik olarak bu özniteliklerin hangi sentaktik öğelerde kullanılabileceğinin bir listesini (ayrıntılı olmayan listesini) vereceğiz. 

Bir öznitelik oluşturmanın genel biçimleri şöyledir:

[[öznitelik_ismi]]
[[öznitelik_ismi()]]
[[öznitelik_ismi(argüman_listesi)]]
[[öznitelik_isim_alanı::öznitelik_ismi]]
[[öznitelik_isim_alanı::öznitelik_ismi()]]
[[öznitelik_isim_alanı::öznitelik_ismi(argüman_listesi)]]
[[using öznitelik_isim_alanı: öznitelik_ismi, öznitelik_ismi, ...]]

Yukarıdaki iki köşeli parantezler içerisindeki çznitelik isimleri birden fazla olabilir. Bu durumda öznitelikler ',' atomu ile ayrılmalıdır. Aşağıda 
bazı geçerli öznitelik oluşturma örnekleri vermek istiyoruz:

[[xxx]]
[[xxx, yyy]]
[[xxx(aaa, bbb)]]
[[xxx(), yyy(aaa, bbb)]]
[[nnn::xxx]]
[[nnn::xxx(aaa, bbb)]]
[[nnn::xxx(aaa, bbb), kkk::yyy(cccc)]]
[[using N: xxx, yyy]]

Burada xxx, yyy, aaa, bbb, ccc gibi isimler herhangi bir isim olarak kullanılmıştır. Öznitelik isim alanı iç içe olamamaktadır. Örnepşn:

[[nnn::kkk::xxx]]		

Böyle bir öznitelik isim alanı geçerli değildir. Yani öznitelik bildiriminde en fazla bir tane :: atomu kullanılmalıdır. 

Bir sentaktik öğeye tek bir [[...]] yerleştirilmek zorunluluğu da yoktur. Birden fazla [[...]] aralarına başka bir atom bulundurulmadan yerleştirilebilir. 

Yukarıda da belrttiğimiz gibi öznitelikler (attributes) pek çok sentaktik öğede kullanılabilmektedir. Özniteliğin sentakstaki yerine göre kimin için yazıldığı 
belirlenebilmektedir. Örneğin:

[[xxx::yyy]] void foo()
{
  //...
}

Burada öznitelik fonksiyonun kendisi bulundurulmuştur. Örneğin:

[[xxx::yyy]] int a, b, c;

Burada öznitelik bildirimin tamamı için bulundurulmuştur. Örneğin:

int a [[xxx::yyy]], b, c;

Burada öznitelik a değişkeni için bulundurulmuştur. Örneğin:

namespace [[xxx::yyy]] CSD
{
  //...
}

Burada öznitelik CSD isim alanı için bulundurulmuştur. Özetle özniteliğin bulundurulduğu yer o özniteliğin sentaksın hangi parçasını nitelediğini belirtmektedir. 

Öznitelikler kabaca şu sentaktik öğelerde kullanılabilmektedir:

- İsim alanlarında isim alanı isimlerinden önce. Örneğin:

namespace [[xxx::yyy]] CSD
{
  //...
}

- Bildirimlerde tür belirleyicilerinden ve niteleyicilerinden önce (yani bildirimlerin başında). Örneğin:

[[xxx::yyy]] int a, b, c;

- Bildirimlerde dekleratördeki isimlerden sonra. Örneğin:

int a [[xxx::yyy]], b;

- Dizi dekleratörlerinde diziyi belirten köşeli parantezlerden sonra. Örneğin:

int a[10] [[xxx::yyy]];

- Gösterici ve referanslarda *, & ve && atomlarından sonra. Örneğin:

int * [[xxx::yyy]]pi;
int & [[xxx::yyy]] r = x;

- Fonksiyonlarda bildirimin başında. Örneğin:

[[xxx::yyy]] void foo()
{
  //...
}

- Fonksiyonlarda fonksiyonun parantezlerinden sonra. Örneğin:

void foo() [[xxx::yyy]]
{
  //...
}

- Fonksiyonlarda fonksiyon isimlerinden sonra. Örneğin:

void foo [[xxx::yyy]]()
{
  //...
}

- Parametre değişkenlerinde tür belirleyicisndne önce. Örneğin:

void foo([[xxx::yyy] int a, int b)
{
  //...
}

- Parametre değişkenlerinde değişken isminden sonra. Örneğin:

void foo(int a [[xxx::yyy], int b)
{
  //...
}

- Deyimlerin başlarında. Örneğin:

[[xxx::yyy]]
if (ifade) {
  //...
}

[[xxx::yyy]]
{
  ifade1;
  ifade2;
  ifade3;
}

[[xxx::yyy]]
for (int i = 0; i < 10; ++i) {
  //...
}

- Boş deyimlerde. Örneğin:

[[xxx::yyy]];

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------
                          22. Ders 30/10/2023 - Pazartesi
--------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------
Belli bir sentaktik öğeye yerleştirilen özniteliklerin ne anlam ifade ettiği (yani semantiiği) derleyicileri yazanların isteğine bırakılmıştır. 
Yani 	derleyicilerin farklı öznitelikleri olabilmektedir. Her öznitelik her sentaktik öğede geçerli olmayabilir. Örneğin bazı öznitelikler yalnızca fonksiyon 
bidiriminde ya da tanımlamasında kullanılabilir. Bazı öznitelikler değişken tanımlamasında kullanılabilir. C++ standartlarında her derleyicinin desteklemesi 
gereken az sayıda öznitelik baştan belirlenmiştir. (C++'ın çeşitli sürümlerinde bu listeye eklemeler yapılmıştır.) Bunlara "standart öznitelikler" diyebiliriz. 
Standanrtlara göre isim alanı içermeyen tüm öznitelikler ve std isim alanı içeren öznitelikler "reserved" bırakılmıştır. 
Yani bunların programcılar tarafından 
ve derleyiciler tarafından kullanılması yasaklanmıştır. (Genel olarak standartlarda "reserved" özelliklerin kullanılması "tanımsız davranış" olarak ele 
alınmaktadır.) Örneğin [[xxx]] biçiminde isim alanı içermeyen bir öznitelik programcılar tarafından da derleyicleri yazanlar tarafından da kullanılmamalıdır. 
Benzer biçimde [[std:xxx]] biçimindeki bir öznitelik de "reserved" durumdadır. O halde derleyicileri yazanlar kendileri öznitelik isim alanı uydurup kendi 
özniteliklerini bu öznitelik isim alanı ile oluşturmalıdırlar. Örneğin [[gnu::xxx]] gibi, [[msvc::xxx] gibi. Ayrıca standartlar "derleyici tarafından tanınmayan"
bütün özniteliklerin derleyici tarafından "görmezden gelinmesi (ignore) gerektiğini" belirtmektedir. Bu durumda biz derleyicilerde olmayan bir öznitelik ismi 
uydursak programda herhangi bir hata ortaya çıkmayacaktır. (Tabii derleyiciler tanıyamadıkları öznitelikler için uyarı mesajları verebilirler.)
--------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------
Pekiyi özniteliklere neden gereksinimn duyulmaktadır? Temel nedenleri şöyle ifade edebiliriz:

- Derleyicilerde bazı davranışların değiştirilmesini sağlamak için
- Derleyiciye ipucu vererek daha etkin kod üretimini sağlamak için
- Derleyicilerin uyarı mekanizmalarında etkili olabilmek için
- Derleyicilerin bazı "implementation defined" durumlarına yönelik açıklama yapmak için
- Kodun okunabilirliğini artırmak için

Konunun başında de belirttiğimiz gibi yukarıdaki amaçların bazıları komut satırı argümanlarıyla ve #pragma direktifleriyle kısmen sağlanabilmektedir. Ancak
öznitelikler "daha genel ve çok daha spesifik" bir yöntem sunmaktadır. Öznitelikler neredeyse her sentaktik öğeye getirilebildiği için çok daha ince belirlemelerin
yapılmasına olanak sağlamaktadır. Standart özniteliklerin yanı sıra çalıştığınız derleyiciye özgü özniteliklere göz gezdirebilirsiniz. Biz bu bölümde 
bazı standart öznitelikleri gözden geçireceğiz. 
--------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------
Standart [[noreturn]] özniteliği yalnızca fonksiyonlarda kullanılabilmektedir. Bir fonksiyonu bu biçimde özniteliklendirirsek derleyiciye bu fonksiyonun 
geri dönmeyeceğini söylemiş oluruz. Böyle fonksiyonların geri dönmesi "tanımsız davranış" oluşturmaktadır. noreturn özniteliği herhangi bir argüman almamaktadır. 
Bu öznitelik C++11'den beri bulunmaktadır. Bir fonksiyonun prototipinde ya da tenımlamasında [[noreturn]] özniteliği kullanılmışsa bütün prototiplerinde ve
tanımlamasında bu özniteliğin kullanılması gerekmektedir. 


Pekiyi bir fonksiyonun geri dönmemesi nasıl mümkün olabilir? İşte aşağıda bazı senaryolaır görüyorsunuz:

[[noreturn]] void foo()
{
  //...

  exit(EXIT_SUCCESS);
}

[[noreturn]] void bar()
{
  //...

  for (;;) {			// sonsuz dönü
    //...
  }
}

[[noreturn]] void tar()
{
  //...

  throw exception();
}

Öte yandan standrat kütüphanedeki bazı fonksiyonlar da artık [[noreturn]] ile bildirilmiştir. Örneğin exit fonksiyonu böyledir:

[[noreturn]] void exit(int exit_code);


Bir fonksiyonun geri dönmeyeceğini derleyiciye söylemekle kim ne kazanmış olmaktadır? 
Derleyiciler fonksiyonları geri döndürebilmek için bazı makine komutlarını üretilen koda yerleştirmek zorundadır. 
Örneğin pek çok işlemcide geri dönüşü "ret" isimli makine komutu sağlamaktadır. 
Ancak tek başına bu "ret" 	makine komutu yeterli de olmayabilir. 
Derleyici bazı yazmaçları geri dönmeden önce girişteki değerlerle yeniden yüklemek zorunda kalabilmektedir. 
Dolayısıyla fonksiyonun geri dönmeyeceğini anlayan derleyici bu kodları fonksiyona eklemeyebilir. 
Bu da daha etkin bir kod üretimi anlamına gelmektedir. 
Öte yandan fonksiyon çağrısında da kodun geri dönmeyeceğini anlayan derleyici orada da bazı optimizasyonları yapabilmektedir. 
[[noreturn]] programcılar için okunabilirliği de artırmaktadır. 
--------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------
Standart [[deprecated]] özniteliği pek çok sentaktik öğeye getirilebilmektedir. 
Bu öznitelik ilgili özelliğin "deprecated" yapıldığını belirtir. Bu öznitelik 
C++14 ile eklenmiştir. Örneğin:

[[deprecated]] void foo();

Burada foo fonksiyonunun ilgili kütüphanede artık "deprecated" yapıldığı belirtilmiştir. Deprecated sözcüğü "hala desteklenen ancak ileri verisyonlarda 
artık kaldırılabilecek olan" öğeleri belirtmektedir. Yukarıdaki örnekte foo fonksiyonunu biz hala kullanabiliriz. Ancak ileride bu fonksiyon kaldırılabileceğine
göre bunu kullanmamaız daha uygun olacaktır. Genellikle "deprecated" öğeler için "daha iyi" alternatifler bulundurulmaktadır. Programcının bu daha iyi olan 
alternatifleri kullanması uygun olacaktır. Tipik olarak derleyiciler "deprecated" özellikleri gördüklerinde bir uyarı mesajıyla durumu programcıya bildirmektedir. 
--------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------
Standart [[likely]] ve [[unlikely]] öznitelikleri deyimlerde ve etiketlerde (labels) kullanılabilmektadır. 
Bu öznitelik C++20 ile eklenmiştir. Örneğin:

if (koşul) [[likely]] {
  //...
}
else {
  //...
}

Burada if deyimim doğruysa ksımından sapması çok daha muhtemel bir durum olarak belirtilmiştir. 
derleyiciler bu tür durumlarda daha iyi makine komutları 
üretebilmektedir. Bu konu "instruction scheduling", "instruction reordering" ve "jump prediction" denilen optimizasyon temalarıyla ilgilidir. İşlemciler bir
makine komutunu yaparken aynı zamanda sonraki komutlar üzerinde de birtakım hazırlık işlemlerini yapabilmektedir. Bu nedenle if deyimlerinde mümkün olan 
durumun makine komutları olarak öne yerleştirilmesi önemlidir. Örneğin:

if (foo() == -1) [[unlikely]] {
  //...
}

Burada foo başarısız olduğunda -1 değerine geri dönüyor olsun. Programcı derleyiciye "bu fonksiyonun başarsız olma olasılığı çok düşük" demek istemektedir.
Bu bilgiyi elde eden derleyici daha etkin makine komutları üretebilmektedir. 
--------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------
Standat [[assume(ifade)]] özniteliği belli bir noktada belli bir koşulun kesinlikle sağlanması gerektiğini belirtmektedir. 
Bu öznitelik boş deyime uygulanabilir. 
Yani bu öznitelikten sonra ';' atomunun gelmesi gerekir.
Eğer söz konusu koşul sağlanmazsa "tanımsız davranış" oluşmaktadır. Örneğin:

void foo(int a)
{
[[assume(a > 0)]];
//...
}

Burada fonksiyonun pozitif bir argümanla çağrılacağı derleyiciye bildirilmiştir. 
Derleyici bu varsayımı kullanarak daha etkin kod üretebilir. Eğer assume
özniteliğine geçirilen argüman virgül operatörü içeriyorsa bu virgül operatörü paranteze alınmalıdır. 
Bu durumda virgül operatörünün sol tarafı öncül işlemi
sağ tarafı koşulu belirtir. Örneğin:

[[assume((foo(), x > 0))]]

Burada foo çağrıldıktan sonra x değişkeninin değerinin pozitif olacağı belirtilmiştir. 
Tabii assume özniteliğindeki ifade işletilmez. 
Yani bu örnekte foo çağrılmayacaktır. 
Derleyici ileride foo çağrıldığında bu çağrıdan sonra x'in 0'dan büyük olacağını anlayacaktır. 
Örneğin (cppreference.com sitesinden 
alınmıştır):

x = 3;
int z = x;

[[assume((h(), x == z))]];	
              
h();
g(x); // Derleyici bu işlemi g(3) ile eşdeğer olarak ele alabilir
--------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------
Standart [[fallthrough]] özniteliği swith deyimlerinde case etiketleri için kullanılmaktadır. 
Öznitelik boş deyimlere uygulanabilmektedir. 
Fallthroug işleminin 
kasten yapıldığını belirtmektedir. 
Dolayısıyla derleyiciler bu tür durumlarda "yanlışlıkla yapılan fallthrough işlemlerinde" verdikleri uyarı mesajlarını 
vermezler. Bu öznitelik C++17 ile birlikte standartlara eklenmiştir. Örneğin:

void f(int n) 
{
  void g(), h();

  switch (n) {
    case 1:
    case 2:
      g();
      [[fallthrough]];
    case 3: 
      h();
  }
}
--------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------
standart [[maybe_unused]] özniteliği bildirilen bir değişkenin kullanılmadığında oluşabilecek uyarıyı ortadan kaldırmak için kullanılmaktadır. 
Bu öznitelik
değişken bildirimlerinde, sınıf bildirimlerinde enum bildirimlerinde, enum sabit bildiriminde, typedef isimlerinin bildiriminde sınıfın veri elemanlarının,
global fonksiyonların ve üye fonksiyonların (ileride görülecek) bildirimlerinde kullanılabilir. Örneğin:

[[maybe_unused]] int a;

void foo(int a, [[maybe_unused]] b)
{
  //...
}

--------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------
--->
