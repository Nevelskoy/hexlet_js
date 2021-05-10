const convert = (arr) => arr.reduce((acc, item) => {
    const [key, value] = item;
    const newValue = Array.isArray(value) ? convert(value) : value;
    return { ...acc, [key]: newValue };
  }, {});
  

console.log(convert([['key', [['key2', 'anotherValue']]],
['key2', 'value2']]));
 // obj { key: { key2: 'anotherValue' }, key2: 'value2' }
