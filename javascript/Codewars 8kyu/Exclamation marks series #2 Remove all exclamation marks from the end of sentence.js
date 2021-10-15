// remove("Hi!") === "Hi";
// remove("Hi!!!") === "Hi";
// remove("!Hi") === "!Hi";
// remove("!Hi!") === "!Hi";
// remove("Hi! Hi!") === "Hi! Hi";
// remove("Hi") === "Hi";

function remove(s) {
  //coding and coding....
  return s.replace(/!*$/g, "");
}
