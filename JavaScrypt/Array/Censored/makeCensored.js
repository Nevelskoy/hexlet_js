const sentence = 'When you play the game of thrones, you win or you die';

const makeCensored = (sentence, array) => {

  const separator = ' ';
  const words = sentence.split(separator);
  const dataCensored = [];
  for (let word of words) {
    if (word === array[0] || word === array[1]) {
      word = '$#%!'
    }
    dataCensored.push(word);
  }
  return dataCensored.join(separator);
};
