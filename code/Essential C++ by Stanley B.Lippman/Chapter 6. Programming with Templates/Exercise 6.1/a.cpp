/* Exercise 6.1 */

/*
 * Rewrite the following class definition to make it a class template:
 * 
 * class example {
 * public:
 *     example(double min, double max);
 *     example(const double *array, int size);
 *     double& operator[] (int index);
 *     bool operator==(const example1&) const;
 *     bool insert(const double*, int);
 *     bool insert(double);
 *     double min() const { return _min; }
 *     double max() const { return _max; }
 *     void min(double);
 *     void max(double);
 *     int count(double value) const;
 * private:
 *     int size;
 *     double *parray;
 *     double _min;
 *     double _max;
 * };
 */

template <typename T>
class example {
public:
    example(const T &min, const T &max);
    example(const T *array, int size);
    T& operator[] (int index);
    bool operator==(const example1&) const;
    bool insert(const T*, int);
    bool insert(const T&);
    T min() const { return _min; }
    T max() const { return _max; }
    void min(const T&);
    void max(const T&);
    int count(const T &value) const;
private:
    int size;
    T *parray;
    T _min;
    T _max;
};
