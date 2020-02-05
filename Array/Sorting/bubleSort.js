const bubbleSort = (array) => {
  let size = array.length;
  let change;
  do {
    change = false;
    for (let i = 0; i < size; i += 1) {
      if (array[i] > array [i + 1]) {
        let item = array[i];
        array[i] = array [i + 1];
        array [i + 1] = item
        change = true
      }
    }
    size -= 1;
  } while (change)
  return array;
}
