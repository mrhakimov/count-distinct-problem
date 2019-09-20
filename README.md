# count-distinct-problem

### Problem statement in English
---
Write an algorithm, which counts the number of different numbers in an array approximately, using a constant volume of memory. More formally you need to implement a class with two functions:

- ```void add(int x);``` — add number ```x``` to an array;
- ```int get_uniq_num();``` — returns approximate number of different numbers, which were passed to the function ```add``` as an argument.

Your class should use no more than 32 Kb of memory.

You can come up with an algorithm yourself, but you can also find some at the Internet (put URL to source in this case). The whole code shall be written by yourself.

In case of checking the main functionality of your solution, you can use the following test: [https://pastebin.com/ZZjg1MzV](https://pastebin.com/ZZjg1MzV)

### Algorithm's description
I used [Probabilistic Counting](http://www.cse.unsw.edu.au/~cs9314/07s1/lectures/Lin_CS9314_References/fm85.pdf) to count approximate number of different numbers, which I found at [StackOverFlow](https://stackoverflow.com/a/35219704). As hash-function [FNV-1a](https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function#FNV-1a_hash) was choosed, but with constants for 32-bit integer type from article [here](https://ru.wikipedia.org/wiki/FNV#%D0%9C%D0%BE%D0%B4%D0%B8%D1%84%D0%B8%D0%BA%D0%B0%D1%86%D0%B8%D0%B8).

### Alternatives
1. **Count-min sketch**. [This algorithm](https://en.wikipedia.org/wiki/Count%E2%80%93min_sketch) assumes, that frequencies of different numbers can not decrease eventually, which means that this algorithm solves some special case, but not the whole problem.
2. **Алгоритм LogLog**. This algorithm, according to comment from [StackOverFlow](https://stackoverflow.com/a/35219704) demands more memory and has a relatively large error.
3. **Алгоритм HyperLogLog**. This algorithm even uses less memory, has bigger error. 


### Условие задания на русском
---
Необходимо написать алгоритм, который приблизительно подсчитывает количество различных чисел в массиве, используя константный объём памяти.
Более формально, надо реализовать класс с двумя функциями:

- ```void add(int x);``` — добавить число ```x``` к набору;
- ```int get_uniq_num();``` — возвращает приблизительное количество различных чисел, которые были переданы в функцию ```add```.

Ваш класс должен использовать не более 32 Кб памяти. 

Идею алгоритма можно придумать самому или найти в интернете (при этом оставить ссылку на источник). Весь код должен быть написан вами.

Для проверки базовой функциональности вашего решения можете использовать следующий тест: [https://pastebin.com/ZZjg1MzV](https://pastebin.com/ZZjg1MzV)

### Описание алгоритма
Для подсчета приблизительного количества различных чисел использован алгоритм [Probabilistic Counting](http://www.cse.unsw.edu.au/~cs9314/07s1/lectures/Lin_CS9314_References/fm85.pdf), найденный мной на [StackOverFlow](https://stackoverflow.com/a/35219704). В качестве хэш-функции выбрана [FNV-1a](https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function#FNV-1a_hash), только с константами для 32-битного целочисленного типа из статьи по [ссылке](https://ru.wikipedia.org/wiki/FNV#%D0%9C%D0%BE%D0%B4%D0%B8%D1%84%D0%B8%D0%BA%D0%B0%D1%86%D0%B8%D0%B8).

### Альтернативы
1. **Count-min sketch**. Судя по [статье из Википедии](https://en.wikipedia.org/wiki/Count%E2%80%93min_sketch) данный алгоритм предполагает, что частоты различных типов не могут уменьшаться со временем, то есть является решением лишь для частного случая.
2. **Алгоритм LogLog**. Данный алгоритм, судя по комментарию на [StackOverFlow](https://stackoverflow.com/a/35219704), требует больше памяти и имеет относительно большую погрешность ошибки.
3. **Алгоритм HyperLogLog**. Этот алгоритм хоть и использует меньше памяти, его погрешность ошибки все же больше, чем у приведенного алгоритма.
