#include <string>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <boost/python.hpp>

using std::string;
using std::cout;
using std::endl;

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




BOOST_PYTHON_MODULE(spam)
{
    using namespace boost::python;
    def("greet", greet);
    def("system", sys);
    def("strlen", string_length);
}
