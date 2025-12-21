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
Заходим в дирректорию CHw/build
```bash
cmake ..
make
cd src/optimalSort
./optimalSort
```


### Способ 2 (GCC)
```bash
gcc optimalSort.c sort.c -o oprimalSort
./optimalSort