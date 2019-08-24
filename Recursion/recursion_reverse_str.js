const reverse = (str) => {
  const lgth = str.length;
  if (lgth < 1) {
    return str;
  } 
  return str[lgth - 1] + reverse(str.substr(0, lgth - 1));
};
