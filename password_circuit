const secret = 'qwerty';

const savePassword = password => passwordForCheck => password === passwordForCheck;

const isCorrectPassword = savePassword(secret);

console.log(isCorrectPassword('wrong password')); // => false
console.log(isCorrectPassword('qwerty')); // => true
