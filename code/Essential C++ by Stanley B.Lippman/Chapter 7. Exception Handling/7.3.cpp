/* 7.3 Trying for an Exception */

bool has_elem(Triangular_iterator first,
                Triangular_iterator last, int elem)
{
    bool status = true;

    try
    {
        while (first != last)
        {
            if (*first == elem)
                return status;
            ++first;
        }
    }
    // only exceptions of type iterator_overflow
    // are caught if thrown while the code
    // sequence within the try block is executed
    catch(iterator_overflow &iof)
    {
        log_message(iof.what_happened());
        log_message("check if iterators address same container");
    }

    status = false;
    return status;
}

*first

inline int Triangular_iterator::
operator*()
{
    check_integrity();
    return Triangular_iterator::_elems[_index];
}

inline void Triangular_iterator::
check_integrity()
{
    if (_index > Triangular::_max_elems)
        throw iterator_overflow(_index, Triangular::_max_elems);
    // ...
}

// executed if element is not found
// or if iterator_overflow exception is caught
status = false;
return status;

inline int Triangular_iterator::
operator*()
{
    check_integrity();
    return Triangular::_elems[_index];
}

return check_integrity()
        ? Triangular::_elems[_index]
        : 0;