// HW02_131044084_Mehmed_Mustafa
// main.cpp
// Triangle Class
//
// Created on 16/10/2015 by Mehmed Mustafa
// Last Edited on 27/10/2015 by Mehmed Mustafa

#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

class Triangle{
public:
	Triangle();
	Triangle(double side);
	Triangle(double A, double B);
	Triangle(double A, double B, double C);
	void input();
	void output() const;
	void setSides(double sideA, double sideB, double sideC);
	void isValidTriangle(double sideA, double sideB, double sideC) const;
	double getA() const { return a; }
	double getB() const { return b; }
	double getC() const { return c; }
	//The getAngle functions use the Cosine Law formulas
	double getAngleA() const{return(acos((b*b+c*c-a*a)/(2*b*c))*180/3.141592);}
	double getAngleB() const{return(acos((a*a+c*c-b*b)/(2*a*c))*180/3.141592);}
	double getAngleC() const{return(acos((a*a+b*b-c*c)/(2*a*b))*180/3.141592);}
	bool isRightAngle() const;
	double getPerimeter() const { return a+b+c; }
	double getArea() const;

private:
	double a, b, c;
};

void printEverything(const Triangle t1){
	t1.isValidTriangle(t1.getA(), t1.getB(), t1.getC());
	cout << "---------------------------------------------" << endl;
	t1.output();

	cout << "The angles of the triangle are";
	cout << " A=" << t1.getAngleA();
	cout << " B=" << t1.getAngleB();
	cout << " C=" << t1.getAngleC() << endl;

	if(t1.isRightAngle())
		cout << "The triangle has a right angle: TRUE!" << endl;
	else
		cout << "The triangle has a right angle: FALSE!" << endl;

	cout << "The area of the triangle is: " << t1.getArea() << endl;
	cout << "The perimeter of the triangle is: " << t1.getPerimeter() << endl;
	cout << "---------------------------------------------" << endl;
}
bool isSameTriangle(const Triangle& t1, const Triangle& t2){
	if(t1.getPerimeter() == t2.getPerimeter() && 
			t1.getArea() == t2.getArea())
		return true;
	else
		return false;
}

int main(){
	Triangle t1(2, 4, 5), t2(3, 3, 3), t3(13, 13, 1), t4(5, 2, 4);
	printEverything(t1);
	printEverything(t4);

	if(isSameTriangle(t1, t4))
		cout << "The triangles are same." << endl;
	else
		cout << "The triangles aren't same!" << endl;

	printEverything(t2);
	printEverything(t3);

	if(isSameTriangle(t2, t3))
		cout << "The triangles are same." << endl;
	else
		cout << "The triangles aren't same!" << endl;

	cout << endl;

	Triangle j;
	j.input();
	j.output();
	printEverything(j);

	return 0;
}

Triangle::Triangle(){
	a = 1.0;
	b = 1.0;
	c = 1.0;
}
Triangle::Triangle(double side){
	isValidTriangle(side, side, side);
	a = side;
	b = side;
	c = side;
}
Triangle::Triangle(double A, double B){
	isValidTriangle(a, b, 1.0);
	a = A;
	b = B;
	c = 1.0;
}
Triangle::Triangle(double A, double B, double C){
	isValidTriangle(A, B, C);
	a = A;
	b = B;
	c = C;
}
void Triangle::isValidTriangle(double A, double B, double C) const{
	if(A<=0 || B<=0 || C<=0)
	{
		cerr << "The sides of the triangle can be ";
		cerr << "only positive non-zero numbers!" << endl;
		exit(1);
	}
	if((A>=B+C) || (B>=C+A) || (C>=A+B))
	{
		cerr << "The triangle is invalid!" << endl;
		exit(1);
	}
}
void Triangle::input(){
	cout << "Enter the A side of the triangle: ";
	cin >> a;
	cout << "Enter the B side of the triangle: ";
	cin >> b;
	cout << "Enter the C side of the triangle: ";
	cin >> c;
	isValidTriangle(a, b, c);
}
void Triangle::output() const{
	cout << "The sides of the triangle are";
	cout << " A=" << a;
	cout << " B=" << b;
	cout << " C=" << c << endl;
}
void Triangle::setSides(double A, double B, double C){
    isValidTriangle(A, B, C);
	a = A;
	b = B;
	c = C;
}
bool Triangle::isRightAngle() const{
	if((a*a + b*b == c*c) || (a*a + c*c == b*b) || (b*b + c*c == a*a))
		return true;
	else
		return false;
}
double Triangle::getArea() const{
	//s is the semi perimeter of the triangle
	double s = getPerimeter()/2;
	//Heron's formula
	return sqrt(s*(s-a)*(s-b)*(s-c));
}