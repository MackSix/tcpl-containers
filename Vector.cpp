/* 
 * File:   Vector.cpp
 * Author: MackSix
 * 
 * Created on November 11, 2015, 4:29 PM
 */

#include "Vector.h"

Vector::Vector(unsigned int s) : elem{new double[s]}, sz{s} // constructor: acquire resources
{
    for (int i = 0; i != s; ++i) elem[i] = 0; // initialize elements
}

Vector::Vector(std::initializer_list<double> lst) // initialize with a list
: elem{new double[lst.size()]}, sz{static_cast<unsigned int>(lst.size())}
{
    copy(lst.begin(), lst.end(), elem); // copy from lst into elem
}

Vector::~Vector() {
    delete[] elem;
} // destructor: release resources

double& Vector::operator[](unsigned int i) {
    return elem[i];
}

unsigned int Vector::size() const {
    return sz;
}
