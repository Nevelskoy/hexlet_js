class Counter(object):
    """A simple integral counter."""

    def __init__(self):
        """Initialize a new counter with zero as starting value."""
        self.value = 0

    def inc(self, amount=1):
        """Increment counter's value."""
        self.value = max(self.value + amount, 0)

    def dec(self, amount=1):
        """Decrement counter's value."""
        self.inc(-amount)

# BEGIN
# Решение основано на замене атрибута value на свойство,
# setter которого ограничивает значение счетчика.
# Такой подход позволяет сохранить свойства класса даже
# если пользователь будет менять значение счетчика через
# присваивание напрямую атрибуту value.
#
# Если вы просто унаследуете Counter и переопределите
# метод inc, то такое решение тоже будет правильным.
# Данное решение нарочно демонстрирует альтернативный подход :)
class LimitedCounter(Counter):
    """A counter with limited maximal value."""

    def __init__(self, limit):
        """Initialize a new counter with some limit."""
        self.limit = limit
        # Свойство должно где-то хранить фактическое значение
        # счетчика, для чего вводится "скрытый" ("приватный")
        # атрибут _actual_value:
        self._actual_value = 0
        # Инициализация методом родителя делается в конце,
        # потому что предок уже в __init__ присваивает атрибуту
        # value значение 0. А это значит, что будет вызван setter,
        # который использует атрибуты limit и _actual_value.
        super().__init__()

    @property
    def value(self):
        return self._actual_value

    @value.setter
    def value(self, new_value):
        self._actual_value = min(max(new_value, 0), self.limit)
# END
