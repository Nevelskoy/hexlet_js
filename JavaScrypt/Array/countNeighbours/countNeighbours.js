const countNeighbours = (data, row, col) => {
    let arr = [[-1, -1], [0, -1], [1, -1], [-1, 0], [1, 0], [-1, 1], [0, 1], [1, 1]];
    let count = 0;
    for (let a of arr) {
        let x = row + a[0]; let y = col + a[1];
        if (data[x] && data[x, y]) count += 1
        console.log(data[0] && data[0, 2])
    }
    return count
    
}

console.log(countNeighbours([[1, 1, 1],
    [1, 1, 1],
    [1, 1, 1]], 1, 2));
