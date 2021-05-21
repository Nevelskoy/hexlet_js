version 1.0_______________________________________________________

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

version 2.0_______________________________________________________

const getLongestLength = (str) => {
  const chars = str.split('');
  let sequence = [];
  let maxLength = 0;

  for (const char of chars) {
    const index = sequence.indexOf(char);
    sequence.push(char);
    if (index !== -1) {
      sequence = sequence.slice(index + 1);
    }
    const sequenceLength = sequence.length;
    if (sequenceLength > maxLength) {
      maxLength = sequenceLength;
    }
  }

  return maxLength;
};
