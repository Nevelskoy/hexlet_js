class Node {
  constructor(key = null, left = null, right = null) {
    this.key = key;
    this.left = left;
    this.right = right;
  }

  getLeft() {
    return this.left;
  }

  getRight() {
    return this.right;
  }

  getKey() {
    return this.key;
  }

  search(key) {
    const nodeKey = this.getKey();
    const right = this.getRight();
    const left = this.getLeft();

    if (key === nodeKey) {
      return this;
    }
    if (key < nodeKey && left) {
      return left.search(key);
    }
    if (key > nodeKey && right) {
      return right.search(key);
    }

    return null;
  }
}

//Реализуйте и экспортируйте по умолчанию класс, который реализует представление узла. Конструктор класса принимает на вход значение ключа (число), и двух детей, которые в свою очередь также являются узлами. Дерево может быть создано пустым.

Класс должен содержать методы:

Геттер getKey() — возвращает ключ. Если дерево пустое, возвращает null.
Геттеры getLeft(), getRight() — возвращают соответственно левого и правого ребёнка. Если ребёнок в узле отсутствует, геттер возвращает null.
search(key) — выполняет поиск узла в правильном двоичном дереве по ключу и возвращает узел. Если узел не найден, возвращается null.
