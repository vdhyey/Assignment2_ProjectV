#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

#define PRE_RELEASE

struct STUDENT_DATA {
	string firstName;
	string lastName;
#ifdef PRE_RELEASE
	string email;
#endif
};

void readFile(vector<STUDENT_DATA>& StudentDataVectorObject) {

#ifdef PRE_RELEASE
	ifstream readFile("StudentData_Emails.txt");
#else
	ifstream readFile("StudentData.txt");
#endif

	if (!readFile.eof()) {
		string readline;
		while (getline(readFile, readline))
		{
			STUDENT_DATA students;
			string data;
			istringstream readData(readline);

			getline(readData, data, ',');
			students.lastName = data;

			getline(readData, data, ',');
			students.firstName = data;

#ifdef PRE_RELEASE
			getline(readData, data, '\n');
			students.email = data;
#endif
			StudentDataVectorObject.push_back(students);
		}
	}
}

int main() {

#ifdef PRE_RELEASE 
	cout << "Pre Release Version" << endl;
#else 
	cout << "Standard Version" << endl;
#endif

	vector<STUDENT_DATA> studentDataVector;

#ifdef PRE_RELEASE
	readFile(studentDataVector);
#else
	readFile(studentDataVector);
#endif

#ifdef NDEBUG
	cout << "Select Debug to print names";
#else
	for (STUDENT_DATA studentDataObject : studentDataVector) {
		cout << studentDataObject.firstName;
		cout << " ";
		cout << studentDataObject.lastName;
#ifdef PRE_RELEASE
		cout << " ";
		cout << studentDataObject.email;

#endif				
		cout << "\n";
	}
#endif

}