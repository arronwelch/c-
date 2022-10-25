// Exercise 4.3:

// Consider the following global data:
// string program_name;
// string version_stamp;
// int tests_run;
// int tests_passed;

// Write a class to wrap around this data.

#ifndef GLOBALDATA_H_
#define GLOBALDATA_H_

#include <string>

using namesapce std;

class GlobalData {
public:
	GlobalData();
	~GlobalData();
	static string ProgramName();
	{
		return program_name;
	}
	static string VersionStamp()
	{
		return version_stamp;
	}
	static int VersionNumber()
	{
		return version_number;
	}
	static int TestsRun()
	{
		return tests_run;
	}
	static int TestsPassed()
	{
		return tests_passed;
	}
	static void ProgramName(const string &strName)
	{
		program_name = strName;
	}
	static void VersionStamp(const string &strStamp)
	{
		version_stamp = strStamp;
	}
	static void VersionNumber(const int &intNumber)
	{
		version_number = intNumber;
	}
	static void TestsRun(const int &intRun)
	{
		tests_run = intRun;
	}
	static void TestsPassed(const int &intPassed)
	{
		tests_passed = intPassed;
	}

private:
	static string _program_name;
	static string _version_stamp;
	static int _version_number;
	static int _tests_run;
	static int _tests_passed;
};

string GlobalData::program_name;
string GlobalData::version_stamp;
int GlobalData::version_number;
int GlobalData::tests_run;
int GlobalData::tests_passed;

#endif
