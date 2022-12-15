/* Exercise 7.3 */

/*
Add a pair of exceptions to the Stack class hierarchy of Exercise 5.2 to handle the
case of attempting to pop a stack that is empty and attempting to push a stack that
is full. Show the modified pop() and push() member functions.
*/

template <typename elemType>
void pop(elemType &elem)
{
    if (empty())
        throw PopOnEmpty();
    elem = _stack[--_top];
    _stack.pop_back();
}

template <typename elemType>
void push(const elemType &elem) {
    if (! full()) {
        _stack.push_back(elem);
        ++_top;
        return;
    }
    throw PushOnFull();
}

#include <exception>
#include <string>

using std::exception;
using std::logic_error;
using std::string;

class StackException : public logic_error {
public:
    StackException(const char* what) : _what(what) {}
    const char* what() const { return _what.c_str(); }
protected:
    string _what;
};

class PopOnEmpty : public StackException {
public:
    PopOnEmpty() : StackException("Pop on Empty Stack") {}
};

class PushOnFull : public StackException {
public:
    PushOnFull() : StackException("Push on Full Stack") {}
};

void log(const char*);

int main()
{
    try {
        ;
    }
    catch(const PushOnFull &pof)
        { log(pof.what()); return; }
    catch(const StackException &stke)
        { log(stke.what()); return; }
    catch(const logic_error &lge)
        { log(lge.what()); return; }
    catch(const exception &ex)
        { log(ex.what()); return; }
}