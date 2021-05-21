const getIntersectionOfSortedArray = (arr1, arr2) => {
  let one = 0;
  let two = 0;
  let flag;
  const result = [];

  do {
    flag = true;
    if (one >= arr1.length || two >= arr2.length) {
      return result;
    }

    if (arr1[one] === arr2[two]) {
      result.push(arr1[one]);
      count1 += 1;
      count2 += 1;
    }

    if (arr1[one] > arr2[two]) {
      count2 += 1;
    }

    if (arr1[one] < arr2[two]) {
      count1 += 1;
    }
  } while (flag);

  return result;
};

export default getIntersectionOfSortedArray;
