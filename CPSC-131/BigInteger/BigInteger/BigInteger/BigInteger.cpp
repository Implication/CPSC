#include "BigInteger.h"
#include "BigIntegerException.h"
#include <iostream>
#include <algorithm>

// view the header files and implement all the functions

// default constructor
BigInteger::BigInteger(){
	number = "0";  //Default number is zero
	size = number.length(); //Set size equal to the number of "digits" in number.
}


// constructor with one string argument
BigInteger::BigInteger(std::string value){

	//Throw for any character that isnt equal from teh characters 0 through 9
	for (int x = 0; x < value.length(); x++){
		if (value.at(x) < '0' || value.at(x) > '9'){
			throw NumberFormatException("Invalid string input");
		}
	//Throw to catch empty strings
	}
	if (value.empty()){
		throw NumberFormatException("Empty string input");
	}

	number = value; //Sets number equal to value
	char n = number.find_first_not_of("0"); //Used to find the first character of strings not equal to zero.
	if (n != std::string::npos){
		number = number.substr(n);
	}
	size = number.length();

}


// copy constructor **Not Needed for this formula, just to show knowledge of its use**
BigInteger::BigInteger(const BigInteger& bigInt) {
	number = bigInt.number;
	char n = number.find_first_not_of("0");
	if (n != std::string::npos){
		number = number.substr(n);
	}
	size = number.length();
}

// assignment operator not really needed since im not allocating memory
BigInteger& BigInteger::operator=(const BigInteger& bigInt) {
	if (this != &bigInt) {
		number = bigInt.number;
		char n = number.find_first_not_of("0");
		if (n != std::string::npos){
			number = number.substr(n);
		}
		size = bigInt.number.length();
	}
	return *this;
}

// destructor not needed since im not allocating memory
BigInteger::~BigInteger() {
}

// print the number without leading zero
std::string BigInteger::toString() {
	for (int x = 0; x < size; x++){
		if (number[x] >= '1' && number[x] <= '9'){
			number.erase(0, x);
			break;
		}
		if (x + 1 == size){
			number = "0";
		}
	}
	return number;
}

// addition operator
BigInteger operator+(const BigInteger& leftNum, const BigInteger& rightNum) {

	int length = max(leftNum.size, rightNum.size); //Stores the largest length of the sizes of the numbers 
	string revleft, revright; //Used to store the reverse string of the left number, and the right number
	string result; //stores the total result of the left number and the right number, 
	string storage_str; //stores the reference of the string at the position located
	char storage[2] = { 0 };
	if (leftNum.size < rightNum.size){
		revleft = string(leftNum.number.rbegin(), leftNum.number.rend()) + string(length - leftNum.size, '0');
		revright = string(rightNum.number.rbegin(), rightNum.number.rend());
	}
	else if(leftNum.size > rightNum.size){
		revleft = string(leftNum.number.rbegin(), leftNum.number.rend());
		revright = string(rightNum.number.rbegin(), rightNum.number.rend()) + string(length - rightNum.size, '0');
	}
	else{
		revleft = string(leftNum.number.rbegin(), leftNum.number.rend());
		revright = string(rightNum.number.rbegin(), rightNum.number.rend());
	}



	int carry = 0; //Stores the carry digit produced by the two numbers addition
	char c; //Stores the carry of the leftmost digit. If it is zero then it is erased from the string

	/*First places the strings of revright, and revleft at position X, in the storage string.
	Then converts the storage string into the value stored at the reference at position x using int1, which represents the leftNum
	and int2 which represent the Right number. Then adds the two digits together into storage int + the carry. Afterword if the stored int is 10
	or greater, the carry is equal to 1, and the stored int is equal to the first digit. Then result is equal to itself + the converted string of
	storage int, added by zero with the range of 0 through 9. If the carry is greater than 0, then the leftmost digit is equal to one*/
	for (int x = 0; x < length; x++){	
		int int1 = 0, int2 = 0, storage_int = 0;
		storage_str = revleft.at(x);
		int1 = atoi(storage_str.c_str());
		storage_str = revright.at(x);
		int2 = atoi(storage_str.c_str());
		storage_int = (int1 + int2 + carry);
		carry = 0;
		while (storage_int > 9){
			storage_int %= 10;
			carry = 1;
		}
		result  += itoa(storage_int, storage,10);
		if (carry > 0){
			c = '1';
		}
	}

	//Reverse the string to produce the desired addition
	result = c + string(result.rbegin(), result.rend());
	//If the leftmost digit is equal to zero, then delete the position, otherwise keep it.
	if (result.at(0) != '1'){
		result.erase(0, 1);
	}

	//Exit Stage Right
	return result;
}

// multiplication operator
BigInteger operator*(const BigInteger& leftNum, const BigInteger& rightNum) {
	int length = max(leftNum.size, rightNum.size); //Stores the largest length of the sizes of the numbers 
	string revleft, revright; //Used to store the reverse string of the left number, and the right number
	int mat[10000]; //Multiples of everything including the zeroes
	int add[10000];
	string result; //stores the total result of the left number and the right number, 
	string storage_str; //stores the reference of the string at the position located
	char storage[500] = { 0 };
	int left[10000] = { 0 }; //Stores the digits of the left number after conversion to integers. Initalized to zero to prevent invalid numbers.
	int right[10000] = { 0 }; //Stores the digits of the right numbers after conversion to integers. Initialized to zero to prevent invalid numbers.
	int holder;

	//Setting the reverse of the numbers inputed
	revleft = string(leftNum.number.rbegin(), leftNum.number.rend()); 
	revright = string(rightNum.number.rbegin(), rightNum.number.rend());
	/*Converts the string of characters into integers and stores them into an int
	for the left number */
	for (int x = 0; x < leftNum.size ; x++){
		storage_str = revleft.at(x);
		holder = atoi(storage_str.c_str());
		left[x] = holder;
	}
	/*Converts the string of character itno integers and stores them into an int
	for the right number*/
	for (int x = 0; x < rightNum.size; x++){
		storage_str = revright.at(x);
		right[x] = atoi(storage_str.c_str());
	}
	int carry = 0; //Stores the carry digit produced by the two numbers addition
	char c; //Stores the carry of the leftmost digit. If it is zero then it is erased from the string
	int k = 0; //Increments the array place holder

	/*For loop used specifically in order to get the mat of the multiplication table
	Uses two for loops in order to multiply each number in the right digits by each digit in the left number, and adds the carry into the code
	takes that sum and gets the remainder of the sum and 10 to get the place holder. After this Carry is equal to the same sum divided by 10 in order to get 
	cut off the digit in the ones place and get the carry to add.*/
	for (int x = 0; x <= rightNum.size; x++){
		for (int y = 0; y <= leftNum.size; y++){			
			mat[k++] = (right[x] * left[y] + carry) % 10;
			carry = (right[x] * left[y] + carry) / 10;
		}
		mat[k++] = carry;
		for (int hold = 0; hold < x; hold++){
			mat[k++] = 0;
		}
	}
	k = 0; //Resets the increment to zero for the add array
	carry = 0; //Resets carry to zero in order to use for the add formula

	/*Hardest part to code right here. First for loop is equal to the total size of the left number and the right number in order to get the proper size
	of the result. The second for loop is used in order to get the proper sum of the column. This loop is equal only the the number of digits in the right number, since the number of rows cannot 
	be bigger than this. Integer column is the column of rows that is currently beign added. the for loop increment i is the index of the rox that we are adding.The if statement is used in this block
	in order to account only the index of places that need to be added in This prevents it from adding numbers that have already been added into the array.After
	getting all the numbers into the integer sum, these numbers are then added with the carry digit and modded by ten in order to get the sum of the row
	the carry digit is then added to the equation and the loop begins again.*/
	for (int i = 0; i < leftNum.size + rightNum.size; i++){
		int sum = 0;	
		int col = 0;
		for (int j = 1; j <= rightNum.size; j++){
			if (i <= leftNum.size - 1 + j){		
				sum += mat[col + i];
			}
			col += leftNum.size + j;
		}
		add[k++] = (sum + carry) % 10;
		carry = (sum + carry)  / 10;
	}
	add[k] = carry; //Set the very last integer to the carry digit. If carry is zero it is "erased" by the the toString.
	/*for loop used to convert the numbers back into characters in the string.*/
	for (int i = 0; i < k; i++){
		result += itoa(add[i], storage, 10);
	}
	//The number result is backwords since adding and multiplying is right to left. This is used to Reverse the number to the sum
	//from left to right.
	 result = string(result.rbegin(), result.rend());
	return result;
}

