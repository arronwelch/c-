
// Vector.h

class Vector{
private:
    double* elem;   // elem points to an array of sz doubles
    int sz;
public:
    Vector(int s);
    double& operator[](int i);
    int size();
};
