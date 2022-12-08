/* 7.2 Catching an Exception */

// defined elsewhere ...
extern void log_message(const char*);
extern string err_message[];
extern ostream log_file;

bool some_function()
{
    bool status = true;

    // ... we'll get to this part!

    catch(int errno) {
        log_message(err_message[errno]);
        status = false;
    }
    catch(const char *str) {
        log_message(str);
        status = false;
    }
    catch(iterator_overflow &iof) {
        iof.what_happened(log_file);
        status = false;
    }
    // last line of function
    return status;
}

throw 42;
throw "panic: no buffer!";
throw iterator_overflow(_index, Triangular::_max_elems);

catch(iterator_overflow &iof)
    {
        log_message(iof.what_happened());

        // rethrow for another catch clause to handle
        throw;
    }

// matches all exceptions
catch(...)
{
    log_message("exception of unknown type");
    // clean up and exit ...
}