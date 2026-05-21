# Производственная практика: структуры данных и страница организации

Учебный проект подготовлен для выполнения кейс-задач производственной практики по направлению 09.03.02 «Информационные системы и технологии», профиль «Тестирование и DevOps».

## Состав проекта

```text
practice-4-session-synergy/
├── CMakeLists.txt
├── include/
│   └── data_structures.hpp
├── tests/
│   └── data_structures_test.cpp
└── web/
    ├── index.html
    └── style.css
```

## Кейс-задача № 4

Реализованы учебные классы и модульные тесты GoogleTest:

- `SimpleQueue` — очередь FIFO с методами `push`, `pop`;
- `SimpleHeap` — минимальная куча с методами `push`, `pop`;
- `BinarySearchTree` — бинарное дерево поиска с методами `push`, `pop`, `search`.

## Запуск тестов

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build
```

## Кейс-задача № 5

В каталоге `web` находится простая HTML/CSS-страница с информацией об организации.
