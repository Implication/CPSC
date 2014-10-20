#include <iostream>
#include <algorithm>
#include <string>


int result(int num1, int num2);
void fill(std::string num, std::string rev);
int main(){

	std::string num1, num2;
	std::cout << "Enter the first large number" << std::endl;
	std::cin >> num1;
	std::cout << "Ener the second large number" << std::endl;
	std::cin >> num2;
	
	size_t m = std::max(num1.size(), num2.size());
	(num1.size() < num2.size()) ? num1 = std::string(m - num1.size(), '0') + num1 : num2 = std::string(m - num2.size(), '0') + num2;
	std::string final(m + 1, '0');

	long long int  prodNum = 0;
	char carry = 0;
	char carry2 = 0;

	std::string::const_reverse_iterator n1 = num1.rbegin(), e = num1.rend(), n2 = num2.rbegin(), e2 = num2.rend();
	std::string::reverse_iterator f = final.rbegin();
	for (; n1 != e; ++n1, ++n2, ++f){
		char temp = (*n1 - '0') + (*n2 - '0') + carry;
		if (temp >= 10){
			carry = temp / 10;
			temp %= 10;
		}
		else{
			carry = 0;
		}
		*f = temp + '0';

		
	}
	final[0] = carry + '0';
		for (n2 = num2.rbegin(); n2 != e2; ++n2){
			long long int nu2 = *n2 - '0';
			std::string::const_reverse_iterator k2 = num2.rbegin();
			if (n2 != num2.rbegin()){
				while (k2 != n2){
					nu2 *= 10;
					k2++;
				}
			}
			for (n1 = num1.rbegin(); n1 != e; ++n1){
				long long int nu1 = *n1 - '0';
				std::string::const_reverse_iterator k1 = num1.rbegin();
				if (n1 != num1.rbegin()){
					while (k1 != n1){
						nu1 *= 10;
						k1++;
					}
				}
				prodNum += (nu1 * nu2);
			}
		}

	char n = final.find_first_not_of("0");
		 if (n != std::string::npos){
			 final = final.substr(n);
		 }
	

	std::cout << "Sum of the numbers is: " << final  << std::endl;
	std::cout << "Product of the numbers: " << prodNum << std::endl;


	return EXIT_SUCCESS;
}




