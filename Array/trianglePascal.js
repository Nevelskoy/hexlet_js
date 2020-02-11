const generate = (size) => {
  let arr = [1];   
  for(let i = 1; i <= size; i++) {
    arr.unshift(0);
    for (let j = 0; j < arr.length - 1; j++) {
      arr[j] += arr[j + 1]
    }
  }
  return arr;
};
