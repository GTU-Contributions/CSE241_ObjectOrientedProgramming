// HW07_131044084_Mehmed_Mustafa
// main.cpp
//
// Created on 10/12/2015 by Mehmed Mustafa
// Last Edited on 15/12/2015 by Mehmed Mustafa

#include <iostream>
#include "number.h"
#include "naturalN.h"
#include "integerN.h"
#include "rationalN.h"
#include "realN.h"
#include "irrationalN.h"
#include "imaginaryN.h"
#include "complexN.h"

using namespace std;
using namespace MehmedsNumbers;

int main()
{
    cout << "TESTING COMPLEX CLASS" << endl;
	// --------------- TEST complexN class --------------- //
	complexN a(5.0, -5.0); // Magnitude is sqrt(25+25) = sqrt(50)
	complexN b(-4.0, 6.0); // Magnitude is sqrt(24+36) = sqrt(60)

    cout << "First number(a) is: " << a << endl;
    cout << "Second number(b) is: " << b << endl;
	if(a<b)
		cout << "a is smaller than b" << endl;
	else
		cout << "b is smaller than a" << endl;

	cout << "The sum(a+b) is: " << a+b << endl;
	cout << "The difference(a-b) is: " << a-b << endl << endl;

	// --------------- TEST complexN class END --------------- //

    
    
    cout << "TESTING IMAGINARY CLASS" << endl;

	// --------------- TEST imaginaryN class --------------- //
	imaginaryN c(3.2);
	imaginaryN d(-3.0);

    cout << "First number(c) is: " << c << endl;
    cout << "Second number(d) is: " << d << endl;
	if(c<d)
		cout << "c is smaller than d" << endl;
	else
		cout << "d is smaller than c" << endl;

	cout << "The sum(c+d) is: " << c+d << endl;
	cout << "The difference(c-d) is: " << c-d << endl << endl;

	// --------------- TEST imaginaryN class END --------------- //

    
    
    cout << "TESTING REAL CLASS" << endl;

	// --------------- TEST realN class --------------- //
	realN e(5.2);
	realN f(-8);

    cout << "First number(e) is: " << e << endl;
    cout << "Second number(f) is: " << f << endl;
	if(e<f)
		cout << "e is smaller than f" << endl;
	else
		cout << "f is smaller than e" << endl;

	cout << "The sum(e+f) is: " << e+f << endl;
	cout << "The difference(e-f) is: " << e-f << endl << endl;

	// --------------- TEST realN class END --------------- //    
    
    
    
    cout << "TESTING RATIONAL CLASS" << endl;

	// --------------- TEST rationalN class --------------- //
	rationalN g(1, 3);
	rationalN h(5, -3);

    cout << "First number(g) is: " << g << endl;
    cout << "Second number(h) is: " << h << endl;
	if(g<h)
		cout << "g is smaller than h" << endl;
	else
		cout << "h is smaller than g" << endl;

	cout << "The sum(g+h) is: " << g+h << endl;
	cout << "The difference(g-h) is: " << g-h << endl << endl;

	// --------------- TEST rationalN class END --------------- //      
    
    
    
    cout << "TESTING INTEGER CLASS" << endl;

	// --------------- TEST integerN class --------------- //
	integerN i(2);
	integerN j(-7);

    cout << "First number(i) is: " << i << endl;
    cout << "Second number(j) is: " << j << endl;
	if(i<j)
		cout << "i is smaller than j" << endl;
	else
		cout << "j is smaller than i" << endl;

	cout << "The sum(i+j) is: " << i+j << endl;
	cout << "The difference(i-j) is: " << i-j << endl << endl;

	// --------------- TEST integerN class END --------------- //    

    
    
    cout << "TESTING NATURAL CLASS" << endl;

	// --------------- TEST naturalN class --------------- //
	naturalN m(7);
	naturalN n(3);

    cout << "First number(m) is: " << m << endl;
    cout << "Second number(n) is: " << n << endl;
	if(m<n)
		cout << "m is smaller than n" << endl;
	else
		cout << "n is smaller than m" << endl;

	cout << "The sum(m+n) is: " << m+n << endl;
	cout << "The difference(m-n) is: " << m-n << endl << endl;

	// --------------- TEST naturalN class END --------------- //  
    
    
    
    cout << "TESTING NATURAL CLASS" << endl;

	// --------------- TEST naturalN class --------------- //
	naturalN k(2);
	naturalN l(3);

    cout << "First number(k) is: " << k << endl;
    cout << "Second number(l) is: " << l << endl;
	if(k<l)
		cout << "k is smaller than l" << endl;
	else
		cout << "l is smaller than k" << endl;

	cout << "The sum(k+l) is: " << k+l << endl;
	cout << "The difference(k-l) is: " << k-l << endl << endl;

	// --------------- TEST naturalN class END --------------- //   
    return 0;
}