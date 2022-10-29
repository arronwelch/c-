
#include "4.4.h"

ostream& operator<<(ostream &os, const UserProfile &rhs)
{	// output of the form: stanl Beginner 12 100 10 10%
	os << rhs.login() << ' '
	   << rhs.level() << ' '
	   << rhs.login_count() << ' '
	   << rhs.guess_count() << ' '
	   << rhs.guess_correct() << ' '
	   << rhs.guess_average() << endl;
	return os;
}

// overkill ... but it allows a demostration ...
map<string,UserProfile::uLevel> UserProfile::_level_map;

void UserProfile::init_level_map(){
	_level_map["Beginner"] = Beginner;
	_level_map["Intermediate"] = Intermediate;
	_level_map["Advanced"] = Advanced;
	_level_map["Guru"] = Guru;
}

istream& operator>>(istream &is, UserProfile &rhs)
{	// yes, this assumes the input is valid ...
	string login, level;
	is >> login >> level;

	int lcount, gcount, gcorrect;
	is >> lcount >> gcount >> gcorrect;
	rhs.reset_login(login);
	rhs.reset_level(level);

	rhs.reset_login_count(lcount);
	rhs.reset_guess_count(gcount);
	rhs.reset_guess_correct(gcorrect);

	return is;
}

int main()
{
	UserProfile anon;
	cout << anon;	// test out of output operator

	UserProfile anon_too;	// to see if we get unique id
	cout << anon_too;

	UserProfile anna("AnnaL", UserProfile::Guru);
	cout << anna;

	anna.bump_guess_count(27);
	anna.bump_guess_correct(25);
	anna.bump_login_count();
	cout << anna;

	cin >> anon; // test out input operator
	cout << anon;
}
