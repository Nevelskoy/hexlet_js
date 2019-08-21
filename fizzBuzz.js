//Version LOL
const fizzBuzz = (a, b) => {
  if (a > b) {
    return '';
  }
(a % 3 === 0 && a % 5 === 0) ? console.log('FizzBuzz') : (a % 3 === 0) ? console.log('Fizz') : (a % 5 === 0) ? console.log('Buzz') : console.log(a);
return fizzBuzz(a + 1, b); 
};

export default fizzBuzz;

//Hexlet version
const fizzBuzz = (begin, end) => {
  for (let i = begin; i <= end; i += 1) {
    const hasFizz = i % 3 === 0;
    const hasBuzz = i % 5 === 0;
    const fizzPart = hasFizz ? 'Fizz' : '';
    const buzzPart = hasBuzz ? 'Buzz' : '';
    console.log(hasFizz || hasBuzz ? `${fizzPart}${buzzPart}` : i);
  }
};

export default fizzBuzz;
