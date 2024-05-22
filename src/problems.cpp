#include <vector>
#include <string>
#include <unordered_set>

// ############################### PROBLEM 1: Balanced Number [lvl 1] #############################################
//  A balanced number is a number where the sum of digits to the left of the middle digit(s)
//  and the sum of digits to the right of the middle digit(s) are equal.
//  If the number has an odd number of digits,
//  then there is only one middle digit. (For example, 92645 has one middle digit, 6.)
//  Otherwise, there are two middle digits. (For example, the middle digits of 1301 are 3 and 0.)
//  The middle digit(s) should not be considered when determining whether
//  a number is balanced or not, e.g. 413023 is a balanced number because the left sum and right sum are both 5.
//  Given a number, find if it is balanced, and return the string "Balanced" or "Not Balanced" accordingly.
//  The passed number will always be positive.

//  Examples
//  7 ==> return "Balanced"
//  Explanation:
//  middle digit(s): 7
//  sum of all digits to the left of the middle digit(s) -> 0
//  sum of all digits to the right of the middle digit(s) -> 0
//  0 and 0 are equal, so it's balanced.
//  295591 ==> return "Not Balanced"
//  Explanation:
//  middle digit(s): 55
//  sum of all digits to the left of the middle digit(s) -> 11
//  sum of all digits to the right of the middle digit(s) -> 10
//  11 and 10 are not equal, so it's not balanced.
//  959 ==> return "Balanced"
//  Explanation:
//  middle digit(s): 5
//  sum of all digits to the left of the middle digit(s) -> 9
//  sum of all digits to the right of the middle digit(s) -> 9
//  9 and 9 are equal, so it's balanced.
//  27102983 ==> return "Not Balanced"
//  Explanation:
//  middle digit(s): 02
//  sum of all digits to the left of the middle digit(s) -> 10
//  sum of all digits to the right of the middle digit(s) -> 20
//  10 and 20 are not equal, so it's not balanced.

std::string balancedNum(unsigned long long int number)
{

	std::vector<unsigned long long int> digits;

	while(number>=10){
		
		digits.emplace_back(number%10);

		number=(number-number%10)/10;

	}

	digits.emplace_back(number);

	// Corner case
	if(digits.size()<3)
		return "Balanced";

	bool even = digits.size()%2 == 0;

	int dist = even ? 1 : 0;

	int sum1=0;
	int sum2=0;

	int i1=0;
	int i2=digits.size()-1;

	while(i2-i1!=dist){
		sum1+=digits[i1++];
		sum2+=digits[i2--];
	}

	if(sum1==sum2)
		return "Balanced";

	else
  		return "Not Balanced";
}

// ********************************************************************************************************


// ############################### PROBLEM 2: Isograms [lvl 1] #############################################
// An isogram is a word that has no repeating letters, consecutive or non-consecutive. Implement a function 
//that determines whether a string that contains only letters is an isogram. Assume the empty string is an isogram. Ignore letter case.
// Example: (Input --> Output)
// "Dermatoglyphics" --> true
// "aba" --> false
// "moOse" --> false (ignore letter case)

bool is_isogram(std::string str) {
	std::unordered_set<char> acc;

	for (char c : str) {
		if (acc.count(c) > 0) {
			return false;
		}

		acc.insert(c);
	}

	return true;
}

// ********************************************************************************************************

// ############################### PROBLEM 3: All or Nothing [lvl 1] #############################################
// Suppose a student can earn 100% on an exam by getting the answers all correct or all incorrect. 
// Given a potentially incomplete answer key and the student's answers, 
// write a function that determines whether or not a student can still score 100%. 
// Incomplete questions are marked with an underscore, "_".

// ["A", "_", "C", "_", "B"]   # answer key
// ["A", "D", "C", "E", "B"]   # student's solution

// ➞ True

// # Possible for student to get all questions correct.

// ["B", "_", "B"]   # answer key
// ["B", "D", "C"]   # student's solution

// ➞ False

// # First question is correct but third is wrong, so not possible to score 100%.

// ["T", "_", "F", "F", "F"]   # answer key
// ["F", "F", "T", "T", "T"]   # student's solution

// ➞ True

// # Possible for student to get all questions incorrect.

// Examples
// (["B", "A", "_", "_"], ["B", "A", "C", "C"]) ➞ True
// (["A", "B", "A", "_"], ["B", "A", "C", "C"]) ➞ True
// (["A", "B", "C", "_"], ["B", "A", "C", "C"]) ➞ False
// (["B", "_"], ["C", "A"]) ➞ True
// (["B", "A"], ["C", "A"]) ➞ False
// (["B"], ["B"]) ➞ True
// (["_"], ["B"]) ➞ True


// Notes:
// Test has at least one question.
// len(key) == len(answers)

bool possibly_perfect(const std::vector<char>& key, const std::vector<char>& answers)
{
	bool all_correct = true;
	bool all_wrong   = true;

	for (size_t i = 0; i < key.size(); ++i) {
		if (key[i] == '_') {
			continue;
		}

		if (key[i] == answers[i]) {
			all_wrong = false;
		}
		else {
			all_correct = false;
		}
	}

	return all_wrong or all_correct;
}

// ********************************************************************************************************


// ############################### PROBLEM 4: Find the odd int [lvl 2] #############################################
//  Given an array of integers, find the one that appears an odd number of times.
//  There will always be only one integer that appears an odd number of times.
//  Examples
//  [7] should return 7, because it occurs 1 time (which is odd).
//  [0] should return 0, because it occurs 1 time (which is odd).
//  [1,1,2] should return 2, because it occurs 1 time (which is odd).
//  [0,1,0,1,0] should return 0, because it occurs 3 times (which is odd).
//  [1,2,2,3,3,3,4,3,3,3,2,2,1] should return 4, because it appears 1 time (which is odd).

int findOdd(const std::vector<int> &numbers)
{
	int number=numbers[0];
	 
	for(size_t i=1;i<numbers.size();++i)
		number=number^numbers[i];
		
  return number;
}

// ********************************************************************************************************



// ############################### PROBLEM 5: The Vowel Code [lvl 2] #############################################
// Step 1: Create a function called encode() to replace all the lowercase vowels in 
// a given string with numbers according to the following pattern:
// a -> 1
// e -> 2
// i -> 3
// o -> 4
// u -> 5
// For example, encode("hello") would return "h2ll4". There is no need to worry about uppercase vowels in this exercise.
// Step 2: Now create a function called decode() to turn the numbers back into vowels according to the same pattern shown above.
// For example, decode("h3 th2r2") would return "hi there".
// For the sake of simplicity, you can assume that any numbers passed into the function will correspond to vowels.

std::string encode(const std::string &str) {
	std::string vowels("aeiou");
	std::string result = str;

	for (size_t i = 0; i < result.size(); ++i) {
		const size_t pos = vowels.find_first_of(str[i]);

		if (pos != std::string::npos) {
			result[i] = '1' + pos;
		}
	}

	return result;
}

std::string decode(const std::string &str) {
	std::string vowels("aeiou");
	std::string result = str;

	for (size_t i = 0; i < result.size(); ++i) {
		if (str[i] > '0' and str[i] < '6') {
			result[i] = vowels[str[i] - '1'];
		}
	}

	return result;
}

// ********************************************************************************************************



// ############################### PROBLEM 6: Bananas [lvl 3] #############################################
// > "What is your name" said Tim.
// "My name" said the mouse "Is Dinglemouse".
// > "What were you before the witch turned you into a mouse" said Rose.
// "I was a banana" said Dingle the mouse, "So be careful. If you see her, run away!".
// - Badjelly the Witch (12:32), Spike Milligan

// Given a string of letters a, b, n how many different ways can you make the word "banana" 
// by crossing out various letters and then reading left-to-right?
// (Use - to indicate a crossed-out letter)

// Example:

// Input
// bbananana

// Output
// b-anana--
// b-anan--a
// b-ana--na
// b-an--ana
// b-a--nana
// b---anana
// -banana--
// -banan--a
// -bana--na
// -ban--ana
// -ba--nana
// -b--anana

// Notes
// You must return all possible bananas, but the order does not matter
// The example output above is formatted for readability. Please refer to the example tests for expected format of your result.

//#include <iostream>

// Easiest solution: recursive <- construct all possible combinations of positions to remove 
// Keep track of the solution set and the position in our array of pointers
void visit(const std::string& s, std::unordered_set<std::string>& result, std::vector<size_t>& ptrs, size_t curr){

	// If we are not at the last element of ptrs recursively call the function on each other next position curr+1
	if(curr!=ptrs.size()-1){

		// We know how many times we have to call the function
		for(size_t i=curr;i<s.length()-(ptrs.size()-curr-1);++i){
			
			// Call the function on the next element recursively
			visit(s,result,ptrs,curr+1);
			
			//Modify the current pointer (and all the next ones <- no repetitions of positions)
			ptrs[curr]++;
			for(size_t j=curr+1;j<ptrs.size();++j)
				ptrs[j]=ptrs[j-1]+1;

		}

	}
	//Then if we are at the last element we can check it
	else{
		// Here i just need to cycle through each rightmost pointer up until the end of the string
		for(size_t i=ptrs[ptrs.size()-1];i<s.length();++i){
			
			//for(size_t j=0;j<ptrs.size()-1;++j)
			//	std::cerr<<ptrs[j]<<" ";
			//std::cerr<<i<<std::endl;

			// And perform my banana checking
			// This will contain the string to insert in the result
			std::string copy;
			// This will contain the word to check with "banana"
			std::string copy_truncated;
			// We can work under the assumption that there are no repetitions
			size_t idx_ptrs=0;
			// Construct the string without the positions in ptrs
			for(size_t j=0;j<s.length();++j){
				if(j==ptrs[idx_ptrs]){
					copy+="-";
					idx_ptrs++;
				}
				else{
					copy_truncated+=s[j];
					copy+=s[j];
				}
			}
			// Check if the truncated copy is a banana
			if(copy_truncated=="banana")
				result.insert(copy);
			// Else do nothing
		}
	}

}

std::unordered_set<std::string> bananas(const std::string& s) {
    
	std::string banana="banana";

	// Corner case checkings
	if(s.length()<banana.length())
		return {};

	if(s.length()==banana.length())
		if(s=="banana")
			return {s};
		else
			return {};

	std::unordered_set<std::string> result={};

	// Cycle through all the possible positions to remove with size i
	for(size_t i=1;i<s.length()-banana.length()+1;++i){

	// Construct a helper array with the starting combination 0,1,2,...,i-1
	std::vector<size_t> ptrs;

	for(size_t j=0;j<i;++j)
		ptrs.emplace_back(j);
	
	// Call the recursive function and let it do its job
	visit(s,result,ptrs,0);

	}
	
	return result;

}

// ********************************************************************************************************
