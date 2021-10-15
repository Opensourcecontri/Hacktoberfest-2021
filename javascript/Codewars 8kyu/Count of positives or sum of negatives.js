// For input [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -11, -12, -13, -14, -15], you should return [10, -65].

function countPositivesSumNegatives(input) {
  if (input && input.length) {
    let positive = 0;
    let negative = 0;
    input.forEach((num) => (num > 0 ? positive++ : (negative += num)));
    return [positive, negative];
  }
  return [];
}
