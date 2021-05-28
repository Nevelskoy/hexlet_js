// Код на колбеках
import fs from 'fs';

fs.readFile('./first', 'utf-8', (error1, data1) => {
  if (error1) {
    console.log('boom!');
    return;
  }
  fs.readFile('./second', 'utf-8', (error2, data2) => {
    if (error2) {
      console.log('boom!');
      return;
    }
    fs.writeFile('./new-file', `${data1}${data2}`, (error3) => {
      if (error3) {
        console.log('boom!');
      }
    });
  });
});

// Код на промисах
import fsp from 'fs/promises';

let data1;
fsp.readFile('./first', 'utf-8')
  .then((d1) => {
    data1 = d1;
    return fsp.readFile('./second', 'utf-8');
  })
  .then((data2) => fsp.writeFile('./new-file', `${data1}${data2}`))
  .catch(() => console.log('boom!'));

// Код на async/await
import fsp from 'fs/promises';

// В реальной жизни чтение файлов лучше выполнять параллельно, как в функции unionFiles выше
const data1 = await fsp.readFile('./first', 'utf-8');
const data2 = await fsp.readFile('./second', 'utf-8');
await fsp.writeFile('./new-file', `${data1}${data2}`);
