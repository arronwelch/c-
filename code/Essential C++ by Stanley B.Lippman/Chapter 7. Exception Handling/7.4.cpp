/* 7.4 Local Resource Management */

extern Mutex m;
void f()
{
    // resource acquisition
    int *p = new int;
    m.acquire();

    process(p);

    // freeing up of resources
    m.release();
    delete p;
}

void f()
{
    try {
        // same as above
    }
    catch(...) {
        m.release();
        delete p;
        throw;
    }
}

#include <memory>
void f()
{
    auto_ptr<int> p(new int);
    MutexLock ml(m);
    process(p);
    // destructors for p and ml
    // are implicitly invoked here ...
}

class MutexLock {
public:
    MutexLock(Mutex m) : _lock(m)
        { lock.acquire(); }

    ~MutexLock() { lock.release(): }
private:
    Mutex &_lock;
}

#include <memory>

auto_ptr< string > aps(new string("vermeer"));
string *ps = new string("vermeer");

if ((aps->size() == ps->size()) &&
    (*aps == *ps))
    // equal ...