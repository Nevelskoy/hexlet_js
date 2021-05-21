const flatten = (list) => list.reduce((acc, element) => {
  const result = (Array.isArray(element) ? [...acc, ...flatten(element)] : [...acc, element]);
  return result;
}, []);

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
const flatten = (nested) => {
  const result = [];

  const iter = (element) => {
    if (!Array.isArray(element)) {
      return result.push(element);
    }

    return element.forEach(iter);
  };

  iter(nested);
  return result;
};
