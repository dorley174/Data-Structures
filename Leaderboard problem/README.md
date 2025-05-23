# Задание: Топ K записей по значению с использованием быстрой сортировки

## Цель
Реализовать программу на языке C++, которая находит и выводит K записей с наибольшими значениями из входного набора, используя алгоритм быстрой сортировки.

## Условия задачи

### Входные данные
- Целое число `n` — количество записей (не более 1 000 000).
- Целое число `k` — количество записей, которые необходимо вывести.
- Далее `n` строк, каждая из которых содержит:
  - Имя (строка без пробелов)
  - Целое число `stat` (положительное или отрицательное)

### Выходные данные
- `k` записей с наибольшими значениями `stat`, отсортированные по убыванию `stat`.
- Если `k > n`, вывести все `n` записей, начиная с наибольшей.

## Пример

**Ввод:**
5 3
Alice 100
Bob 250
Charlie 150
David 300
Eve 200


**Вывод:**
David 300
Bob 250
Eve 200


## Требования к реализации

### Функциональные
- Определить структуру для хранения имени и значения (`name`, `stat`).
- Использовать алгоритм быстрой сортировки для сортировки по `stat` (по возрастанию).
- После сортировки вывести `k` записей с конца массива (то есть с наибольшими значениями).

### Технические
- Использовать язык C++.
- Поддержка больших объемов данных: до 1 000 000 записей.
- Оптимизация по времени: сортировка должна быть эффективной (используется QuickSort).

## Рекомендации
- Убедитесь, что сортировка работает корректно для различных значений `stat`, включая отрицательные.
- Обработайте случай, когда `k > n`.

## Формат сдачи
- Один `.cpp` файл с полной реализацией программы.
- Код должен быть читаемым и содержать базовые комментарии.
