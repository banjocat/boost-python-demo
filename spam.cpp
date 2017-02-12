#include <string>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

using namespace boost::python;
using std::string;
using std::cout;
using std::endl;

typedef std::vector<int> int_vector;


void greet(string name)
{
    cout << "Hello " << name << endl;
}

int sys(string command)
{
    int sts = system(command.c_str());
    return sts;
}

int string_length(string word)
{
    return word.size();
}

int_vector fibonacci(int num)
{
    int_vector result;
    int first = 0;
    int second = 1;
    int next;
    for (int i = 0; i < num; i++) {
        if (i <= 1) {
            next = i;
        } else {
            next = first + second;
            first = second;
            second = next;
        }
        result.push_back(next);
    }
    return result;
}


BOOST_PYTHON_MODULE(spam)
{
    class_<int_vector>("int_vector")
        .def(vector_indexing_suite<int_vector>() );

    def("greet", greet);
    def("system", sys);
    def("strlen", string_length);
    def("fibonacci", fibonacci);
}
