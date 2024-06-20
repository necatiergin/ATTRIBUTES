<!---
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





--->
