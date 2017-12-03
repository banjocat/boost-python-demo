#include <string>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include <boost/python/dict.hpp>
#include <boost/python/list.hpp>

using namespace boost::python;
using std::string;
using std::cout;
using std::endl;

typedef std::vector<int> int_vector;
typedef std::vector<dict> dict_vector;


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

dict create_a_dict()
{
    dict x;
    x["message"] = "Hello World";
    list l;
    l.append("This");
    l.append("is");
    l.append("a");
    l.append("list");
    x["list"] = l;
    return x;
}

dict change_a_dict(dict val) {
    val["language"] = "C++";
    return val;
}

BOOST_PYTHON_MODULE(spam)
{
    class_<int_vector>("int_vector")
        .def(vector_indexing_suite<int_vector>() );


    def("create_a_dict", create_a_dict);
    def("change_a_dict", change_a_dict);
    def("greet", greet);
    def("system", sys);
    def("strlen", string_length);
    def("fibonacci", fibonacci);
}
