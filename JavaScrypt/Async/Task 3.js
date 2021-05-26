export const reverse = (filepath) => fs.readFile(filepath, 'utf-8')
  .then((data) => {
    const preparedData = data.split('\n').reverse().join('\n');
    return fs.writeFile(filepath, preparedData);
  });
