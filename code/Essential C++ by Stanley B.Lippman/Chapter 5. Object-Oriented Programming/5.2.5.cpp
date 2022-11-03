#include <iostream>
#include <string>

using namespace std;

class LibMat {
public:
	LibMat() { cout << "LibMat::LibMat() default constructor!\n"; }

	virtual ~LibMat() { cout << "LibMat::~LibMat() destructor!\n"; }
	virtual void print() const
		{ cout << "LibMat::print() -- I am a LibMat object!\n"; }
};

void print(const LibMat &mat)
{
	cout << "in global print(): about to print mat.print()\n";

	// this resolves to a print() member function
	//		based on the actual object mat refers to ...
	mat.print();
}

class Book : public LibMat {
public:
	Book(const string &title, const string &author)
		: _title(title), _author(author){
		cout << "Book::Book(" << _title
				  << ", " << _author << ") constructor\n";
	}

	virtual ~Book(){
		cout << "Book::~Book() destructor!\n";
	}

	virtual void print() const {
		cout << "Book::print() -- I am a Book object!\n"
				  << "My title is: " << _title << '\n'
				  << "My author is: " << _author << endl;
	}

	const string& title() const { return _title; }
	const string& author() const { return _author; }

protected:
	string _title;
	string _author;
};

class AudioBook : public Book {
public:
	AudioBook(const string &title,
			  const string &author, const string &narrator)
		: Book(title,author),
		  _narrator(narrator)
	{
		cout << "AudioBook::AudioBook(" << _title
			<< ", " << _author
			<< ", " << _narrator
			<< ") constructor\n";
	}

	~AudioBook()
	{
		cout << "AudioBook::~AudioBook() destructor!\n";
	}
	virtual void print() const {
		cout << "AudioBook::print() -- I am an AudioBook object!\n"
			// note the direct access of the inherited
			// data members _title and _author
			<< "My title is: " << _title << '\n'
			<< "My author is: " << _author << '\n'
			<< "My anrrator is: " << _narrator << endl;
	}
	const string& narrator() const { return _narrator; }
protected:
	string _narrator;
};

class Magazine : public LibMat {
public:
	Magazine(const string& magazine)
		: _magazine(magazine)
	{
		cout << "Magazine::Magazine("
			<< _magazine
			<< ") constructor\n";
	}

	virtual ~Magazine()
	{
		cout << "Magazine::~Magazine() desctructor!\n";
	}

	virtual void print() const {
		cout << "Magazine::print() -- I am an Magazine object!\n"
			<< "My magazine is: " << _magazine << endl;
	}

protected:
	string _magazine;
};

int main()
{
	Magazine mg("Test Magazine");
	print(mg);
}
