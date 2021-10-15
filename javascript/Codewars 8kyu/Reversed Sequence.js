// Build a function that returns an array of integers from n to 1 where n>0.

// Example : n=5 --> [5,4,3,2,1]

const reverseSeq = (n) => {
  const num = [];
  for (let i = n; i >= 1; i--) {
    num.push(i);
  }
  return num;
};
