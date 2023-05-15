# analizCprogYapilan
degisiklik olan yeni kod

Bu programın zaman karmaşıklığı aşağıdaki gibi hesaplanabilir:

--generate_random_array fonksiyonu: O(n) (n, dizi boyutunu temsil eder)
--bubble_sort fonksiyonu: O(n^2)
--find_avg_max_subarray_sum fonksiyonu: O(n)
--floyd_warshall fonksiyonu: O(n^3) (n, grafik boyutunu temsil eder)

Bu işlemler arasında en yüksek karmaşıklığa sahip olanı belirleyen kurala 
göre, bu programın toplam zaman karmaşıklığı O(n^3) olacaktır. Burada n, 
grafik boyutudur. Bu, Floyd Warshall algoritması için tipik bir karmaşıklıktır 
çünkü bu algoritma, her düğüm çifti için en kısa yolu hesaplar. Her düğüm için, 
tüm diğer düğümler üzerinden döngüler çalıştırılır, bu da n^3'lük bir karmaşıklığa neden olur.


Her iki kodun zaman karmaşıklıklarını ve çalışma sürelerini karşılaştırın:
1-İlk kodda, function1'deki çift döngü içerisinde bir bubble sort algoritması bulunuyor. Bu algoritmanın zaman karmaşıklığı genellikle O(n^2)'dir. n, burada dizi boyutunu temsil ediyor (A_SIZE).
2-function2'de, kod dizi üzerinde bir kez geçiyor ve bu n boyutunda bir dizi için O(n)'dir.
3-function3'de, Floyd-Warshall algoritması kullanılıyor. Bu algoritmanın zaman karmaşıklığı genellikle O(n^3)'tür. n burada grafik boyutunu temsil eder (G_SIZE).
4-İkinci kodda, fonksiyonların isimleri ve bazı değişkenler değişmiş olsa da, temel algoritmalarda bir değişiklik yok. Bu nedenle, zaman karmaşıklığı aynıdır.

her iki kod da aynı algoritmaları kullandığı için, genellikle aynı sürede çalışmalarını bekleriz.
