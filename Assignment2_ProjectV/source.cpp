#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct STUDENT_DATA {
	string firstName;
	string lastName;
};

void readFile(vector<STUDENT_DATA>& StudentDataVectorObject) {

	ifstream readFile("StudentData.txt");

	if (!readFile.eof()) {
		string readline;
		while (getline(readFile, readline))
		{
			STUDENT_DATA students;
			string data;
			istringstream readData(readline);

			getline(readData, data, ',');
			students.lastName = data;

			getline(readData, data, '\n');
			students.firstName = data;

			StudentDataVectorObject.push_back(students);
		}
	}
}

int main() {

	vector<STUDENT_DATA> studentDataVector;

	readFile(studentDataVector);

	return 1;
}