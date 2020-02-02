const buildDefinitionList = (array) => {

  if (array.length === 0) {
    return '';
  }

  const parts = [];
  for (const value of array) {
    parts.push(`<dt>${value[0]}</dt><dd>${value[1]}</dd>`);
  }
  const innerValue = parts.join('');
  const result = `<dl>${innerValue}</dl>`;
  return result;
};

export default buildDefinitionList;
