/* 
 * File:   Containers.cpp
 * Author: MackSix
 * 
 * This program demonstrates Classes, Concrete & Abstract Types, Containers and 
 * Virtual Functions discussed in Chapter 3 of "The C++ Programming Language" 
 * 4th ed by Bjarne Stroustrup. 
 * 
 * Requires a C++11 standard compiler.
 *
 * Created on November 7, 2015, 8:15 AM
 */

#include <cstdlib>
#include <iostream>
#include <list>
#include "Container.h"
#include "Vector.h"

using namespace std;

class Vector_container : public Container { // Vector_container implements Container
    Vector v;
public:

    Vector_container(int s) : v(s) {
    } // Vector of s elements

    Vector_container(std::initializer_list<double> il) : v{il}
    {} // Vector initialized with list

    ~Vector_container() {} // destructor: release resources

    double& operator[](int i) override {
        return v[i];
    }

    int size() const override {
        return v.size();
    }
};

class List_container : public Container { // List_container implements Container
    list<double> ld; // (standard-library) list of doubles
public:
    
    List_container() {} // empty List
    
    List_container(initializer_list<double> il) : ld{il} {} // initialize with a list

    ~List_container() {} // destructor: release resources

    double& operator[](int i) override;

    int size() const override {
        return ld.size(); 
    }
};

double& List_container::operator[](int i) {
    for (auto& x: ld) {
        if (i == 0) return x;
        --i;
    }
    throw out_of_range("List container");
}

void use(Container& c) { // use() only knows how to use the Container interface
    cout << "Elements" << '\n';
    const int sz = c.size();
    for (int i = 0; i != sz; ++i)
        cout << c[i] << '\n';
}

int main() // C++ programs start by executing the function main
{
    List_container lc = {1, 11, 2, 13, 4, 15, 6, 17, 8, 19};
    use(lc); // use() works with a List_container that implements the Container interface
         
//    Vector_container vc = {1, 11, 2, 13, 4, 15, 6, 17, 8, 19}; // Same as below
    
    Vector_container vc {1, 11, 2, 13, 4, 15, 6, 17, 8, 19}; // Same as above
    
    
//    Vector_container vc(10); // initializes size
//    for (int i = 0; i != vc.size(); ++i)
//        vc[i] = i + 10; // fill each element with a number
    
    use(vc); // use() works with a Vector_container that implements the Container interface
    
    return 0;
}
