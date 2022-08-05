// 2.9 Setting Up a Header File

// NumSeq.h
bool				seq_elem(int pos, int &elem);
const vector<int>	*fibon_seq(int size);
const vector<int>	*lucas_seq(int size);
const vector<int>	*pell_seq(int size);
const vector<int>	*triang_seq(int size);
const vector<int>	*square_seq(int size);
cosnt vector<int>	*pent_seq(int size);
// and so on ...

// OK: this is a declaration
const int seq_cnt = 6;
extern const vector<int>* (*seq_array[seq_cnt])(int);
