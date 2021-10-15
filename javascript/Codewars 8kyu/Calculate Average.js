// Write a function which calculates the average of the numbers in a given list.
// Note: Empty arrays should return 0.

function find_average(array) {
  // your code here
  if (!array.length) {
    return 0;
  } else {
    return array.reduce((acc, cur) => acc + cur, 0) / array.length;
  }
}
