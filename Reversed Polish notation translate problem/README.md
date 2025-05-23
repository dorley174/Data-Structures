# Задание: Преобразование выражения в обратную польскую нотацию (ОПН)

## Цель
Реализовать программу на языке C++, которая преобразует математическое выражение из инфиксной записи в постфиксную (обратную польскую нотацию, ОПН).

## Описание
Программа должна принимать на вход выражение в инфиксной форме (с привычным порядком записи — операнды, операторы и скобки) и преобразовывать его в постфиксную запись, в которой порядок выполнения операций определяется только их порядком следования, а не скобками и приоритетами.

## Поддерживаемые элементы
- Числа (одиночные цифры от 0 до 9)
- Операторы: `+`, `-`, `*`, `/`
- Функции: `min`, `max`
- Скобки: `(` и `)`
- Разделители аргументов функций: `,`

## Входные данные
- Одна строка с арифметическим выражением.
- Все элементы (числа, операторы, скобки, запятые) разделены пробелами.

### Пример входа:
min ( 2 , max ( 3 , 4 ) )


## Выходные данные
- Строка, представляющая постфиксную запись (ОПН) эквивалентного выражения.

### Пример вывода:
2 3 4 max min


## Требования к реализации

### Функциональные
- Реализовать функцию `rpn(string input)`, которая:
  - Принимает строку с инфиксной записью.
  - Возвращает строку с соответствующей постфиксной записью.
- Использовать стек для хранения операторов и функций.
- Правильно учитывать приоритеты операций:
  - `+`, `-` — приоритет 1
  - `*`, `/` — приоритет 2
  - `min`, `max` — приоритет 3

### Технические
- Использовать язык C++.
- Реализация должна использовать стандартные библиотеки (`<stack>`, `<sstream>`, `<string>`).
- Разделители аргументов функций (`','`) обрабатываются аналогично закрывающей скобке: вызывают сброс операторов до открывающей скобки.

## Ограничения
- Все числа — однозначные (от `'0'` до `'9'`).
- В выражении не допускаются отрицательные числа или числа с плавающей точкой.
- Выражения считаются синтаксически корректными (обработка ошибок не требуется).

## Пример

**Ввод:**
