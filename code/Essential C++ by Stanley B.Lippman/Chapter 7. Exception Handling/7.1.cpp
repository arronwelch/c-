/* Chapter 7. Exception Handling */
/* 7.1 Throwing an Exception */

inline void Triangular_iterator::
check_integrity()
{
    if (_index > Triangular::_max_elems)
        throw iterator_overflow(_index,
                                Triangular::_max_elems);
    if (_index > Triangular::_elems.size())
        Triangular::gen_elements(_index);
}

throw 42;
throw "panic: no buffer!";

class iterator_overflow {
public:
    iterator_overflow(int index, int max)
        : _index(index), _max(max) {}
    int index() { return _index; }
    int max() { return _max; }

    void what_happened(ostream &os = cerr) {
        os << "Internal error: current index "
           << _index << " exceeds maximum bound: "
           << _max;
    }
private:
    int _index;
    int _max;
};

if (_index > Triangular::_max_elems) {
    iterator_overflow ex(_index, Triangular::_max_elems);
    throw ex;
}