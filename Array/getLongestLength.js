const getLongestLength = (str) => {

  if (str === '') {
    return 0;
  }

  const getLonges = (string) => {
    const measure = [];
    let arr = [];
    let newString = '';
    const lengthArray = (array) => {
      const size = arr.length;
      measure.push(size);
      return measure;
    };
    for (let i = 0; i < string.length; i += 1) {
      newString = string.slice(i);
      arr = [];
      for (const char of newString) {
        if (!arr.includes(char)) {
          arr.push(char);
        } else if (arr.includes(char)) {
          lengthArray(arr);
          break;
        }
        lengthArray(arr);
      }
    }
    function getMaxOfArray(numArray) {
      return Math.max.apply(null, numArray);
    }
    const result = getMaxOfArray(measure);
    return result;
  };
  return getLonges(str);
};
