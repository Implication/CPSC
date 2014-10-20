#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include <iostream>
#define MAX 10000
using namespace std;

string multiply(char[], char[]);
int main(){
	char a[MAX];
	char b[MAX];
	string c;
	int la, lb;
	int i;
	cout << "Enter the first number :";
	cin >>  a;
	cout <<("Enter the second number : ");
	cin >> b;
	cout << "Multiplication of two numbers : " << endl;;
	c = multiply(a, b);
	
	cout << c << endl;
	system("pause");
	return 0;
}

string multiply(char a[], char b[]){
	string mul('0', MAX);
	char c[MAX];
	char temp[MAX];
	int la, lb;
	int i, j, k = 0, x = 0, y;
	long int r = 0;
	long sum = 0;
	la = strlen(a) - 1;
	lb = strlen(b) - 1;
	string p;
	for (i = 0; i <= la; i++){
		a[i] = a[i] - 48;
	}

	for (i = 0; i <= lb; i++){
		b[i] = b[i] - 48;
	}			
	for (i = lb; i >= 0; i--){
		r = 0;
		for (j = la; j >= 0; j--){
			temp[k++] = (b[i] * a[j] + r) % 10;
			cout << "At position " << k - 1 << "Temp is " << (temp[k - 1] + 48) - 48 << endl;

			r = (b[i] * a[j] + r) / 10;

		}
		temp[k++] = r;
		cout << "At position " << k - 1 << "Temp is " << (temp[k - 1] + 48) - 48 << endl;
		x++;
		for (y = 0; y < x; y++){
			temp[k++] = 0;
			cout << "At position " << k - 1 << " Temp is " << (temp[k - 1] + 48) - 48 << endl;
		}
	}

	k = 0;
	r = 0;
	for (i = 0; i < la + lb + 2; i++){
		sum = 0;
		y = 0;
		for (j = 1; j <= lb + 1; j++){
			if (i <= la + j){
				sum = sum + temp[y + i];
				cout << "position y: " <<  y + i << endl;
				cout << "Sum is currently:" << sum << endl;
			}
			y += j + la + 1;
		}
		c[k++] = (sum + r) % 10;
		cout << "c at" << k - 1 << "is " << (c[k - 1] + 48) - 48 << endl;
		r = (sum + r) / 10;
	}
	c[k] = r;
	j = 0;
	for (i = k - 1; i >= 0; i--){
		mul[j] = c[i] + 48;
		j++;
	}
	mul.erase(j);
	if (mul[0] == '0'){
		mul.erase(0,1);
	}
	return mul;
}