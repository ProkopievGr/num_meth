#include "pch.h"
#include <iostream>
#include <limits>
using namespace std;

template <class T>
T machine_epsilon(T e) {
	T a = 1;
	T b = 2;
	while(a + e / b > a)
		e /= b;
	return e;
}

template <class T>
T machine_zero(T e) {
	T prev_e = e;
	while(e != 0) {
		prev_e = e;
		e /= 2;
	}

	return prev_e;
}

template <class T>
T machine_infinity(T e) {
	T prev_e = e;
	while(1) {
		if(e == numeric_limits<T>::infinity()) break;
		else {
			prev_e = e;
			e *= 2;
		}
	};
	return prev_e;
}

int main() {
	float eps = machine_epsilon(1.0f);
	double eps_ = machine_epsilon((double)1.0f);
	cout << "Machine epsilon:\n";
	cout << "float: " << eps << "\n" << "double: " << eps_ << "\n\n";

	float zero = machine_zero(1.0f);
	double zero_ = machine_zero((double)1.0f);
	cout << "Machine zero:\n";
	cout << "float: " << zero << "\n" << "double: " << zero_ << "\n\n";

	float inf = machine_infinity(1.0f);
	double inf_ = machine_infinity((double)1.0f);
	cout << "Machine infinity:\n";
	cout << "float: " << inf << "\n" << "double: " << inf_ << "\n\n";
	return 0;
}
