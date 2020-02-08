const openingSymbols = ['(', '[', '{', '<'];
const closingSymbols = [')', ']', '}', '>'];

const isBracketStructureBalanced = (expression) => {
  let index = 0;
  const stack = [];
  for (const symbol of expression) {
    if (openingSymbols.includes(symbol)) {
      index = openingSymbols.indexOf(symbol);
      stack.push(index);
    } else if (closingSymbols.includes(symbol)) {
      if (stack[stack.length - 1] === closingSymbols.indexOf(symbol)) {
        stack.pop();
      } else if (!stack.pop()) {
        return false;
      }
    }
  }
  return stack.length === 0;
}
console.log(isBracketStructureBalanced('<><<{[()]}>>>'));
