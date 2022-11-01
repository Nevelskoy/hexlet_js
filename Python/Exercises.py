#1) === Списки - Создание списков и добавление элементов ===
#2) === Списки - Ссылки и изменяемость ===
#3) === Списки - Модификация списков поэлементно, сортировка ... ===
#4) === Списки - Срезы ===
#5) === Списки - Цикл for ===
#6) === Списки - Итераторы ===
#7) === Списки - Вес Хэмминга ===
#8) ===  Списки - Треугольник Паскаля ===
#10) ===  Списки - Длина последнего слова ===
#9) ===  Списки - Увеличение двумерного списка ===
#11) ===  Списки - Чанкование ===
#12) ===  Списки - Возрастающая последовательность ===
#13) ===  Списки - Самая длинная подстрока ===
#14) ===  Списки - Сравнение версий ===
#15) ===  Списки - Список диапазонов ===
#16) ===  Списки - Зеркалирование матрицы ===
#17) ===  Списки - Сумма интервалов ===
#18) ===  Списки - Обратная польская запись ===
#19) ===  Словари - defaultdict ===
#20) ===  Словари - Преобразование DNA в RNA ===
#21) ===  Словари - Сборщик строки запроса ===
#22) ===  Словари - Детектирование ===
#23) ===  Словари - Слияние словарей ===
#24) ===  Словари - Вычислитель различий ===
#25) ===  Списки - Улитка ===
#26) ===  Функции - Больше о декораторах ===
#27) ===  Функции - Рекурсия ===
#28) ===  Функции - Счётчик одногодок ===
#29) ===  Функции - Композиция функций ===
#30) ===  Функции - Поиск ближайшего соседа ===
#31) ===  Функции - Конвертер цветов ===
#32) ===  Функции - Фильтр анаграмм ===
#33) ===  Функции - Одинаковая чётность ===





#1) === Списки - Создание списков и добавление элементов ===
# BEGIN
def get_square_roots(argument):
    if argument < 0:
        return []
    elif argument:
        root = math.sqrt(argument)
        return [-root, root]
    return [0]
# END
# BEGIN
def get_range(up_to):
    result = []
    counter = 0
    while counter < up_to:
        result.append(counter)
        counter += 1
    return result
# END

#2) === Списки - Ссылки и изменяемость ===
# BEGIN
def duplicate(items):
    items.extend(items)
# END

#3) === Списки - Модификация списков поэлементно, сортировка ... ===
# BEGIN
def rotate(items):
    if items:
        items.insert(0, items.pop(-1))
# END

#4) === Списки - Срезы ===
# BEGIN
def rotated_right(items):
    return items[-1:] + items[:-1]

def rotated_left(items):
    return items[1:] + items[:1]
# END

#5) === Списки - Цикл for ===
# BEGIN
def find_index(value, items):
    for index, item in enumerate(items):
        if item == value:
            return index
# END

#6) === Списки - Итераторы ===
# BEGIN
def find_second_index(value, items):
    iterator = iter(items)
    first = find_index(value, iterator)
    second = find_index(value, iterator)
    if second is not None:
        return first + second + 1
# END

#7) === Списки - Вес Хэмминга ===
# BEGIN
def hamming_weight(number):
    weight = 0
    digits = bin(number)[2:]

    for num in digits:
        weight += int(num)

    return weight


# Alternative solutions
# def hamming_weight(x):
#     s = 0
#     while x:
#         x, r = divmod(x, 2)
#         s += r
#     return s


# def hamming_weight(number):
#     return bin(number).count('1')
# END

#8) ===  Списки - Треугольник Паскаля ===
# BEGIN (write your solution here)
# Определяем функцию для вычисления факториала
def fact(n):
    if n == 0:
        return 1
    return n * fact(n - 1)


def triangle(row_number):
    numbers_count = row_number + 1
    line = []
    for i in range(numbers_count):
        # Для вычисления числа заданной строки используем формулу
        # расчёта биноминальных коэффициентов С(n, k) = n! / (k! * (n - k)!)
        line.append(fact(row_number) / (fact(i) * fact(row_number - i)))
    return line


# Alternative solutions
#
#
# def triangle(row):
#     line = [1]
#     for i in range(row):
#         line.append(line[i] * ((row - i) / (i + 1)))
#     return line
#
#
# from operator import add
#
#
# def triangle(row_number):
#     row = [1]
#     for _ in range(row_number):
#         row = list(map(  # [x,y,z]
#             add,         # x y z 0
#             row + [0],   # + + + +
#             [0] + row,   # 0 x y z
#         ))
#     return row
# END

#9) ===  Списки - Увеличение двумерного списка ===
# BEGIN
def enlarge(image):
    output = []
    for line in image:
        row = []
        for pixel in line:
            # expand horizontally
            row.extend([pixel, pixel])
        row = ''.join(row)
        # expand verticaly
        output.extend([
            row,
            row,
        ])
    return output
# END

#10) ===  Списки - Длина последнего слова ===
# BEGIN
def length_of_last_word(string):
    words = string.split()
    if not words:
        return 0
    last_word = words[-1]
    return len(last_word)
# END

#11) ===  Списки - Чанкование ===
# BEGIN
def chunked(size, source):
    result = []
    index = 0
    while index < len(source):
        result.append(source[index:index + size])
        index += size
    return result
# END

#12) ===  Списки - Возрастающая последовательность ===
# BEGIN
def is_continuous_sequence(source):
    if len(source) < 2:
        return False
    for x, y in zip(source, source[1:]):
        if (y - x) != 1:
            return False
    return True
# END

#13) ===  Списки - Самая длинная подстрока ===
# BEGIN
def unique_sequence_length(string):
    unique_sequence = set()
    length = 0
    for char in string:
        if char in unique_sequence:
            break
        unique_sequence.add(char)
        length += 1
    return length

def find_longest_length(string):
    longest_length = 0
    for i, _ in enumerate(string):
        substring_length = unique_sequence_length(string[i:])
        if longest_length < substring_length:
            longest_length = substring_length
    return longest_length
# END

#14) ===  Списки - Сравнение версий ===
# BEGIN
def sign(x):
    if x > 0:
        return 1
    elif x < 0:
        return -1
    return 0

def compare_version(first, second):
    [a1, b1] = first.split('.')
    [a2, b2] = second.split('.')

    major = sign(int(a1) - int(a2))
    minor = sign(int(b1) - int(b2))

    return major if major != 0 else minor
# END

#15) ===  Списки - Список диапазонов ===
# BEGIN
def summary_ranges(numbers):
    if not numbers:
        return []

    ranges = []
    current_sequence = [numbers[0]]
    sequences = [current_sequence]

    for x, y in zip(numbers, numbers[1:]):
        if (y - x) == 1:
            current_sequence.append(y)
        else:
            current_sequence = [y]
            sequences.append(current_sequence)

    # здесь [0, 1, 2, 7, 5, 6] уже преобразован
    # в [[0, 1, 2], [7], [5, 6]]

    for sequence in sequences:
        if len(sequence) > 1:
            first, last = sequence[0], sequence[-1]
            ranges.append(f'{first}->{last}')

    return ranges
# END

#16) ===  Списки - Зеркалирование матрицы ===
# BEGIN
def mirror_matrix(matrix):
    if matrix:
        half_len = len(matrix[0]) // 2
        for line in matrix:
            line[half_len:] = line[-half_len - 1::-1]
# END

#17) ===  Списки - Сумма интервалов ===
# BEGIN
def sum_of_intervals(intervals):
    values = []
    for start, end in intervals:
        for i in range(start, end):
            if i not in values:
                values.append(i)
    return len(values)
# END

#18) ===  Списки - Обратная польская запись ===
import operator

# BEGIN
get_operator = {
    '+': operator.add,
    '-': operator.sub,
    '*': operator.mul,
    '/': operator.truediv,
}.get


def rpn_calc(rpn):
    stack = []
    for elem in rpn:
        op = get_operator(elem)
        if op is not None:
            x = stack.pop()
            y = stack.pop()
            elem = op(y, x)
        stack.append(elem)
    return stack[0]
# END

#19) ===  Словари - defaultdict ===
# BEGIN
from collections import defaultdict


def collect_indexes(items):
    result = defaultdict(list)
    for index, item in enumerate(items):
        result[item].append(index)
    return result
# END

#20) ===  Словари - Преобразование DNA в RNA ===
# BEGIN
MAPPING = {
    "G": "C",
    "C": "G",
    "T": "A",
    "A": "U",
}


def to_rna(nucleotide):

    rna = []
    for item in nucleotide:
        rna.append(MAPPING[item])

    return ''.join(rna)


# Альтернативный вариант с использованием map
# def to_rna(nucleotide):
#     return ''.join(map(MAPPING.get, nucleotide))
# END

#21) ===  Словари - Сборщик строки запроса ===
# BEGIN
def build_query_string(params):
    items = []
    for key, value in sorted(params.items()):
        items.append(f'{key}={value}')
    return '&'.join(items)
# END

#22) ===  Словари - Детектирование ===
# BEGIN (write your solution here)
def find_where(books, query_book):
    for book in books:        
        if set(book.values()).issuperset(set(query_book.values())):
            return book
# END

# BEGIN
def find_where(items, search_request):
    # Значение object() в качестве умолчательного используется для того,
    # чтобы не получилось получить от get значение None и случайно
    # успешно сравнить с value == None.
    # Каждое значение object() всегда равно только самому себе.
    default = object()
    for item in items:
        for key, value in search_request.items():
            # Здесь можно было бы использовать
            # что-то вроде "key in book and book[key] !=..." и обойтись
            # без всяких object(). Но хочется обращаться по ключу
            # ровно один раз!
            if item.get(key, default) != value:
                break
        else:
            return item
# END

#23) ===  Словари - Слияние словарей ===
from collections import defaultdict


def merged(*dicts):
    aggregate = defaultdict(set)
    for source in dicts:
        for key, value in source.items():
            aggregate[key].add(value)
    return aggregate
# END

def merged(*args):
    answer = {}
    for arg in args:
        for key in arg.keys():
            if key not in answer:
                answer[key] = set()
            answer[key].add(arg[key])
    return answer

#24) ===  Словари - Вычислитель различий ===
# BEGIN
def gen_diff(data1, data2):
    keys = data1.keys() | data2.keys()  # https://youtu.be/vkUTX1hruF8?t=929
    result = {}
    for key in keys:
        if key not in data1:
            result[key] = 'added'
        elif key not in data2:
            result[key] = 'deleted'
        elif data1[key] == data2[key]:
            result[key] = 'unchanged'
        else:
            result[key] = 'changed'
    return result
# END

#25) ===  Списки - Улитка ===
# BEGIN (write your solution here)
def to_left(array):
    result = []
    if len(array) == 0:
        return array
    while len(array[0]) > 0:
        buff = []
        for lst in array:
            buff.append(lst.pop(-1))
        result.append(buff)
    return result


def snail_path(array):
    res = []
    while len(array) > 0:
        res.extend(array.pop(0))
        array = to_left(array)
    return res
# END

# BEGIN
def rotate(matrix):
    """
    Rotate the matrix counter-clockwise.

    >>> rotate([[1]])
    [(1,)]
    >>> rotate([[1, 2, 3]])
    [(3,), (2,), (1,)]
    >>> rotate([[1, 2], [3, 4]])
    [(2, 4), (1, 3)]
    """
    return list(reversed(list(zip(*matrix))))


def snail_path(matrix):
    path = []

    def trace(submatrix):
        if not submatrix:
            return
        path.extend(submatrix[0])
        trace(rotate(submatrix[1:]))
    trace(matrix)
    return path
# END

# BEGIN (write your solution here)
def snail_path(item):
    result = []
    res = item[:]
    while res:
        result.extend(res.pop(0))
        res = list(zip(*res))
        res.reverse()
    return result
# END

#26) ===  Функции - Больше о декораторах ===

from functools import wraps


def memoizing(arg):
    mem = {}
    ind = []
    count = [0]

    def dec(func):
        @wraps(func)
        def inner(num):
            if count[0] == arg:
                count[0] = 0
            if num in mem.keys():
                print("будет вспомнено")
                return mem[num]
            else:
                result = func(num)
                if len(ind) >= arg:
                    print(f"вытеснит запомненный результат для {ind[count[0]]}")
                    mem.pop(ind[count[0]])
                    mem[num] = result
                    ind[count[0]] = num
                    count[0] += 1
                else:
                    count[0] += 1
                    mem[num] = result
                    ind.append(num)
                return result
        return inner
    return dec

from functools import wraps

# BEGIN (write your solution here)
def memoizing(limit):
    """
    Make decorator that will remember recent results of function (up to limit).

    Arguments:
        limit, maximum number of results to remember

    Returns:
        memoizing decorator

    """
    def wrapper(function):
        """
        Memoize function.

        Arguments:
            function, it will be memoized

        Returns:
            memoized version of function

        """
        memory = {}
        order = []

        @wraps(function)
        def inner(argument):
            memoized_result = memory.get(argument)
            if memoized_result is None:
                memoized_result = function(argument)
                memory[argument] = memoized_result
                order.append(argument)
                if len(order) > limit:
                    oldest_argument = order.pop(0)
                    memory.pop(oldest_argument)
            return memoized_result
        return inner
    return wrapper
# END

#27) ===  Функции - Рекурсия ===
# BEGIN
def is_odd(number):
    return False if number == 0 else is_even(number - 1)


def is_even(number):
    return True if number == 0 else is_odd(number - 1)
# END

#28) ===  Функции - Счётчик одногодок ===
# BEGIN (write your solution here)
from collections import Counter
from datetime import date


def get_men_counted_by_year(arr):
    arr_man = list(filter(lambda arr: arr['gender'] == 'male', arr))
    lst_year = []
    for data in arr_man:
        lst_year.append(date.fromisoformat(data['birthday']).year)
    return Counter(lst_year)
# END

# BEGIN
from collections import Counter
from datetime import datetime


def date_string_to_year(date_string):
    dt = datetime.strptime(date_string, '%Y-%m-%d')
    return dt.year


def get_men_counted_by_year(users):
    men = filter(lambda user: user['gender'] == 'male', users)
    birth_years = map(lambda man: date_string_to_year(man['birthday']), men)
    return dict(Counter(birth_years))
# END

# BEGIN (write your solution here)
from collections import Counter
from datetime import date


def get_men_counted_by_year(arr):
    return Counter(map(lambda man: date.fromisoformat(man['birthday']).year,
                   list(filter(lambda arr: arr['gender'] == 'male', arr))))
# END

#29) ===  Функции - Композиция функций ===
# BEGIN (write your solution here)
def compose(first, second):
    return (lambda x: first(second(x)))
# END

#30) ===  Функции - Поиск ближайшего соседа ===
# BEGIN (write your solution here)
def find_index_of_nearest(num, arr):
    if arr:
        diff = list(map(lambda x: abs(num - x), arr))
        return diff.index(min(diff))
# END

#31) ===  Функции - Конвертер цветов ===
# BEGIN (write your solution here)
def rgb2hex(r=0, g=0, b=0):
    return('#{0:02x}{1:02x}{2:02x}'.format(r, g, b))


def hex2rgb(hex_):
    lst_k = ['r', 'g', 'b']
    v = [int(hex_[1:][x:x+2], 16) for x in range(0, len(hex_[1:]), 2)]
    return {k: v for k, v in zip(lst_k, v)}
# END

# BEGIN
from textwrap import wrap


def hex2rgb(color):
    r, g, b = map(lambda channel: int(channel, 16), wrap(color[1:], 2))
    return {'r': r, 'g': g, 'b': b}

def rgb2hex(r=None, g=None, b=None):
    return f'#{r:02x}{g:02x}{b:02x}'
# END

#32) ===  Функции - Фильтр анаграмм ===
# BEGIN
def normalized(string):
    return list(sorted(string))


def filter_anagrams(word, words):
    norm = normalized(word)
    return filter(lambda item: normalized(item) == norm, words)
# END

# BEGIN (write your solution here)
def filter_anagrams(word, lists):
    result = []
    for item in lists:
        dub = list(word)
        for char in item:
            dub.remove(char) if char in dub else dub.append(char)
        if not dub:
            result.append(item)
    return result
# END

#33) ===  Функции - Одинаковая чётность ===
# BEGIN (write your solution here)
def same_parity_filter(arr):
    if not arr:
        return []
    parity = arr[0] % 2
    return list(filter(lambda x: x % 2 == parity, arr))
# END
