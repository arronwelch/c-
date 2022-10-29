// 4.4.h: solution for Exercise 4.4

/*
A user profile consists of a login, the actual user name, the number of times logged on, the number
of guesses made, the number of correct guesses, the current level --- one of beginner, intermediate,
advanced, or guru --- and the percentage correct (this latter may be computed or stored).Provide a
UserProfile class. Support input and output,equality and inequality.The constructors should allow
for a default user level and default login name of "guest".How might you guarantee that each
guest login for a particular session is unique?
*/

#ifndef USERPROFILE_H_
#define USERPROFILE_H_

#include <string>
#include <map>
#include <iostream>
//#include <cstdlib>

using namespace std;

class UserProfile {
public:
	enum uLevel { Beginner, Intermediate, Advanced, Guru};

	UserProfile();
	UserProfile(string login, uLevel level = Beginner);

	// default memberwise initialization and copy sufficient
	// no explicit copy constructor or copy assignment operator
	// no destructor necessary ...

	bool operator==(const UserProfile&);
	bool operator!=(const UserProfile &rhs);

	// read access functions
	string login() const { return _login; }
	string user_name() const { return _user_name; }
	int login_count() const { return _times_logged; }
	int guess_count() const { return _guesses; }
	int guess_correct() const { return _correct_guesses; }
	double guess_average() const;
	string level() const;

	// write access functions
	void reset_login(const string &val) { _login = val; }
	void user_name(const string &val) { _user_name = val; }

	void reset_level(const string&);
	void reset_level(uLevel newlevel) { _user_level = newlevel; }

	void reset_login_count(int val) { _times_logged = val; }
	void reset_guess_count(int val) { _guesses = val; }
	void reset_guess_correct(int val) { _correct_guesses = val; }

	void bump_login_count(int cnt=1) { _times_logged += cnt; }
	void bump_guess_count(int cnt=1) { _guesses += cnt; }
	void bump_guess_correct(int cnt=1) { _correct_guesses += cnt; }

private:
	string _login;
	string _user_name;
	int _times_logged;
	int _guesses;
	int _correct_guesses;
	uLevel _user_level;

	static map<string, uLevel> _level_map;
	static void init_level_map();
	static string guest_login();
};

inline double UserProfile::guess_average() const
{
	return _guesses
		? double(_correct_guesses) / double(_guesses) * 100
		: 0.0;
}

inline UserProfile::UserProfile(string login, uLevel level)
	: _login(login), _user_level(level),
	  _times_logged(1), _guesses(0), _correct_guesses(0){}

// #include <cstdlib>
#include <sstream>

inline UserProfile::UserProfile()
	: _login("guest"), _user_level(Beginner),
	  _times_logged(1), _guesses(0), _correct_guesses(0)
{
	static int id = 0;
//	char buffer[16];
	stringstream ss;

	// _itoa() is a Standard C library function
	// turns an integer into an ascii representation
//		itoa(id++, buffer, 10);

	ss << id++;

	// add a unique id during session to guest login
//	_login += buffer;
	_login += ss.str();
}

inline bool UserProfile::
operator==(const UserProfile &rhs)
{
	if (_login == rhs._login &&
		_user_name == rhs._user_name)
			return true;
	return false;
}

inline bool UserProfile::
operator != (const UserProfile &rhs) { return ! (*this == rhs); }

inline string UserProfile::level() const {
	static string _level_table[] = {
			"Beginner", "Intermediate", "Advanced", "Guru" };
	return _level_table[_user_level];
}

inline void UserProfile::reset_level(const string &level){
	map<string,uLevel>::iterator it;
	if (_level_map.empty())
		init_level_map();
	// confirm level is a recongnized user level ...
	_user_level =
		((it = _level_map.find(level)) != _level_map.end())
			? it->second : Beginner;
}

#endif
