// nameShuffler('john McClane'); => "McClane john"

function nameShuffler(str) {
  //Shuffle It
  return str.split(" ").reverse().join(" ");
}
