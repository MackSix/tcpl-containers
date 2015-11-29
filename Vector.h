/* 
 * File:   Vector.h
 * Author: MackSix
 *
 * Created on November 11, 2015, 4:29 PM
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <cstdlib>
#include <list>
using namespace std;

class Vector {
private:
    double* elem; // elem points to an array of sz doubles
    unsigned int sz;
public:
    Vector(unsigned int s);

    Vector(std::initializer_list<double> lst);   

    ~Vector();

    double& operator[](unsigned int i); 

    unsigned int size() const; 
};

#endif /* VECTOR_H */

