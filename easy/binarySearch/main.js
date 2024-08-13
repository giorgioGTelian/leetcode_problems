/* Returns either the index of the location in the array,
  or -1 if the array did not contain the targetValue */
var doSearch = function(array, targetValue) {
	var min = 0;
	var max = array.length - 1;
	var guess;
	var countGuess = 0;
    
    while (min <= max) {
        guess = Math.floor((min + max) / 2);
        countGuess ++;

        if (array[guess] === targetValue) {
            println("Total guesses: " + countGuess); 
            println(guess);
            return guess; // Target found, return the index
        } else if (array[guess] < targetValue) {
            min = guess + 1; // Search in the right half
            println(min);
        } else {
            max = guess - 1; // Search in the left half
            println(max);
        }
    }

    return -1; // Target not found
};

var primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 
		41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97];

var result = doSearch(primes, 73);
println("Found prime at index " + result);

Program.assertEqual(doSearch(primes, 73), 20); // Test case for 73
Program.assertEqual(doSearch(primes, 41), 12); // Test case for 41
Program.assertEqual(doSearch(primes, 2), 0);   // Test case for 2
