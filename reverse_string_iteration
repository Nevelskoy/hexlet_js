export default (str) => {
  const lastIndex = str.length - 1;
  // BEGIN (write your solution here)
     const iter = (ind, acc) => {
          if (ind > lastIndex) {
              return acc;
           }
            return iter(ind + 1, `${str[ind]}${acc}`);
        
  };
  // END
  return iter(0, '');
};
