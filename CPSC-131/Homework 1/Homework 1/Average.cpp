#include <iostream>
using namespace std;

long long average(int cases);

int ex1(){
	int cases;
	cout << "Enter the number of cases" << endl;
	cin >> cases;
	long long avg = average(cases);
	cout << "The average of this sale is: " << avg << endl;
	return 0;
}

long long average(int cases){
	bool notZero = true;
	long long int n;
	int avg = cases;	
	long long total = 0;
	for (int x = 0; x < cases; x++){
		if (notZero){
			while (notZero){
				cout << "Enter the number to compute the average of" << endl;
				cin >> n;
				total += n;
				if (n = 0){
					notZero = false;
				}
				if (n < 0){
					avg -= 1;
				}
			}
		}
		else{
			cin >> n;
			if (n > 0){
				total += n;
			}
			else{
				avg -= 1;
			}
		}
		}


	total /= avg;
	return total;
}
