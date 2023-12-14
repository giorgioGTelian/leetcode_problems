/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    //let x = prompt();
    console.log(x); 
  if (x < 0 || (x % 10 === 0 && x !== 0)) {
    return false;
  }
  
  return x === reverse(x);
};

const reverse = (num) => {
  let rev = 0;
  
  while (num != 0) {
    rev = rev * 10 + num % 10;
    num = parseInt(num / 10, 10);
  }
  
  return rev;

};
