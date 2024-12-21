# Полигон с деревьями
Данный проект представляет собой (или должен будет представлять) набор программ на C++, позволяющий экспериментировать с такой замечательной структурой данных, как дерево.

## ВНИМАНИЕ
Проект переехал на [GitVerse](https://gitverse.ru/alexsm/tree-test)

## Состав
На данный момент проект содержит только класс `BinTree`, реализующий дерево с закрытой структурой. Все узлы передаются пользовательскому коду по целочисленным дескрипторам.

## Сборка
Данный проект создавался на ОС Debian GNU/Linux и планируется к использованию на машинах на базе операционных систем того же семейства. Сборка происходит посредством __Unix Makefiles__.

Для запуска процесса сборки необходимо ввести в консоль следующую команду, находясь в директории проекта.
```
$ make
```

Также для `make` можно задать множество параметров, модифицирующих процесс сборки проекта. Ниже представлен список переменных makefile'а, которые могут быть предварительно заданы как переменные среды (или в качестве аргумента команды `make`).

1. SOURCE_DIR - имя директории, содержащей исходный код (`src` по-умолчанию)
1. BUILD_DIR - имя директории, в которую будут сохранены исполняемые файлы и объектные модули (`build` по-умолчанию); данный каталог будет создан автоматически при запуске процесса сборки, если он еще не существует
1. CXX - имя компилятора (`clang++` по-умолчанию)
1. CXXFLAGS - флаги компилятора (если одноименная переменная среды уже определяет используемые флаги, к ним будут добавлены следующие `-Wall -std=c++17 -Iinclude`)
