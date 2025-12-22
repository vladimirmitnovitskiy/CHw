# Optimal Sort
Программа сортировки входящего потока целых чисел.

## Стурктура проекта
* `optimalSort.c` - главный файл, где производится ввод чисел
* `sort.c` - файл с реализацией сортировки
* `sort.h` - заголовочный файл

## Cборка и запуск

### Тркбования
* GCC
* CMake

### Способ 1 (CMake)
Заходим в дирректорию CHw
```bash
cmake . -B build
cmake --build build
cd build/src/optimalSort
./optimalSort
```


### Способ 2 (GCC)
```bash
gcc optimalSort.c sort.c -o oprimalSort 
./optimalSort
```

### Для сборки бинарника сортировки
```bash
gcc sort.c -S -O1
```