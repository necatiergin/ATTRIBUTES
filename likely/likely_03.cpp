


<!---
Standart [[likely]] ve [[unlikely]] öznitelikleri deyimlerde ve etiketlerde (labels) kullanılabilmektadır. Bu öznitelik C++20 ile eklenmiştir. Örneğin:

	if (koşul) [[likely]] {
		//...
	}
	else {
		//...
	}

	Burada if deyimim doğruysa ksımından sapması çok daha muhtemel bir durum olarak belirtilmiştir. derleyiciler bu tür durumlarda daha iyi makine komutları 
	üretebilmektedir. Bu konu "instruction scheduling", "instruction reordering" ve "jump prediction" denilen optimizasyon temalarıyla ilgilidir. İşlemciler bir
	makine komutunu yaparken aynı zamanda sonraki komutlar üzerinde de birtakım hazırlık işlemlerini yapabilmektedir. Bu nedenle if deyimlerinde mümkün olan 
	durumun makine komutları olarak öne yerleştirilmesi önemlidir. Örneğin:

	if (foo() == -1) [[unlikely]] {
		//...
	}

	Burada foo başarısız olduğunda -1 değerine geri dönüyor olsun. Programcı derleyiciye "bu fonksiyonun başarsız olma olasılığı çok düşük" demek istemektedir.
	Bu bilgiyi elde eden derleyici daha etkin makine komutları üretebilmektedir. 

--->
