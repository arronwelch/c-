/* 7.5 The Standard Exceptions */

vector<string>*
init_text_vector(ifstream &infile)
{
    vector<string> *ptext = 0;
    try {
        ptext = new vector<string>;
        // open file and file vector
    }
    catch(bad_alloc) {
        cerr << "ouch. heap memory exhausted!\n";
        // ... clean up and text
    }
    return ptext;
}

#include <exception>

class iterator_overflow : public exception {
public:
    iterator_overflow(int index, int max)
        : _index(index), _max(max)
    {}

    int index() { return _index; }
    int max() { return _max; }

    // overrides exception::what()
    const char* what() const;

private:
    int _index;
    int _max;
};

catch(const exception &ex)
{
    cerr << ex.what() << endl;
}

#include <sstream>
#include <string>

const char*
iterator_overflow::
what() const
{
    ostringstream ex_msg;
    static string msg;

    // writes the output into the in-memory
    // ostringstream class object,
    // converting the integer values into
    // string representation ...

    ex_msg << "Internal error: current index "
        << _index << " exceeds maximum bound: "
        << _max;

    // extract the string object
    msg = ex_msg.str();

    // extract the const char* representation
    return msg.c_str();
}