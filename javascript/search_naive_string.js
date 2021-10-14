function naiveSearch(str, searchStr) {
    let count = 0
    for (let i = 0; i < str.length; i++) {
        for (let j = 0; j < searchStr.length; j++) {
            if (searchStr[j] != str[i+j]) break;
            if (searchStr.length - 1 == j) count++
        }
    }
    return count
}

console.log(naiveSearch("lorem ipsum lorem", "lorem"))  // it will give the count of "lorem" in a string using naive approach
