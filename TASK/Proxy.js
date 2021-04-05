Реализуйте и экспортируйте по умолчанию функцию, которая принимает объект и позволяет обращаться 
только к "публичным" свойствам и методам. При попытке прочитать или перезаписать приватное или 
несуществующее свойство должно выбрасываться исключение.


class Course {
  constructor(name) {
    this._name = name;
  }

  getName() {
    return this._name;
  }
}

const course = new Course('Object-oriented design');
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

const validateProperty = (target, prop) => {
  if (!(prop in target)) {
    throw new Error(`Property "${prop}" doesn't exist`);
  }
  if (prop.startsWith('_')) {
    throw new Error(`Property "${prop}" is protected`);
  }
};
 
const protect = (obj) => new Proxy(obj, {
  get: (target, prop) => {
    const property = target[prop];
    validateProperty(target, prop);
 
    return (typeof property === 'function') // если свойство - это метод, то необходимо привязать его
      ? property.bind(obj) // к контексту оригинального объекта, иначе метод вызовется на прокси
      : property;
  },
  set: (target, prop, value) => {
    validateProperty(target, prop);
    target[prop] = value;
 
    return true;
  },
});

const protectedCourse = protect(course);
console.log(protectedCourse.getName());
