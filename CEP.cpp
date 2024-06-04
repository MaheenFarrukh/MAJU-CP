//Maheen Farrukh Khan
//FA23-BECE-0001
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void mainMenu(){
	int choice;
	cout << "Student Record Database System" << endl;
	cout << "------------------------------" << endl;
	cout << "1. Add New Student Record" << endl;
	cout << "2. Modify Existing Student Record" << endl;	
	cout << "3. Delete Student Record" << endl;
	cout << "4. Search Student Records" << endl;
	cout << "5. Display All Student Records" << endl;
	cout << "6. Generate Reports" << endl;
	cout << "7. Exit" << endl << endl;
}

void upp(string stuRecord[][7]){
	for (int i=0; i<3; i++){
    	for(int j=0; j<5; j++){
    		for(int k=0; k<stuRecord[i][j].length(); k++){
    			stuRecord[i][j][k] = toupper(stuRecord[i][j][k]);
			}
		}
	}
}
void checkLen(string stuRecord[][7], int n) {
    int id = stuRecord[n][0].length();
    int name = stuRecord[n][1].length();
    int age = stuRecord[n][2].length();
    int conInfo = stuRecord[n][3].length();

    while (id != 14 || age > 2 || conInfo != 11) {
        if (id != 14) {
            cout << "Oops! The Student ID you've entered is incorrect. Try Again.\n";
            cout << "Enter Student ID: ";
            getline(cin, stuRecord[n][0]);
        }
        if (age > 2) {
            cout << "Oops! Your age can't be more than 99 :( Try Again.\n";
            cout << "Enter Age: ";
            getline(cin, stuRecord[n][2]);
        }
        if (conInfo != 11) {
            cout << "Oops! Your phone number is too short or too long. It should be 11 digits. Try Again\n";
            cout << "Enter Contact Information: ";
            getline(cin, stuRecord[n][3]);
        }
        id = stuRecord[n][0].length();
        age = stuRecord[n][2].length();
        conInfo = stuRecord[n][3].length();
    }

    if (name < 8) {
        int nlen = 8 - name;
        stuRecord[n][1].append(nlen, ' ');
    }
}

void checkLenID(string ID){
	int id = ID.length();
	while (id!=14){
		cout << "Oops! The Student ID you've entered is incorrect. Try Again.\n";
		cout << "Enter Student ID: ";
		getline(cin, ID);
		int id = ID.length();
	}
}

void checkLenName(string name){
	int nameLen = name.length();
	if(nameLen<8){
		int nlen=8-nameLen;
		name.append(nlen, ' ');
	}
}

void checkLenConInfo(string conInfo){
	int conInfoLen = conInfo.length();
	while (conInfoLen!=11){
		cout << "Oops! Your phone number is too short or too long. It should be 11 Digits. Try Again\n";
			cout << "Enter Contact Information: ";
		getline(cin, conInfo);
		int conInfoLen = conInfo.length();
	}
}
		

void addStudent(string stuRecord[][7], int& n){
	cin.ignore();
	cout << "Add New Student Record" << endl;
	cout << "----------------------" << endl;
	cout << "Enter Student ID: ";
	getline(cin, stuRecord[n][0]);
	cout << "Enter Name: ";
	getline(cin, stuRecord[n][1]);
	cout << "Enter Age: ";
	getline(cin, stuRecord[n][2]);
	cout << "Enter Contact Information: ";
	getline(cin, stuRecord[n][3]);
	cout << "Enter current GPA: ";
	getline(cin, stuRecord[n][4]);
	cout << "Enter current semester(ie First, Second, etc): ";
	getline(cin, stuRecord[n][5]);
	cout << "Enter Courses Enrolled(separate by commas): ";
	getline(cin, stuRecord[n][6]);
	checkLen(stuRecord, n);
	upp(stuRecord);
	n++;
	cout << "Record Updated Successfully!";
}

void modifyStudent(string stuRecord[][7], int& n){
	cin.ignore();
	int a, modChoice;
	string ID;
	bool cond = false;
	cout << "Modify Student Record" << endl;
	cout << "---------------------" << endl;
	cout << "Enter Student's ID: ";
	getline(cin, ID);
	for (int i=0; i<15; i++) {
        ID[i] = std::toupper(ID[i]);
    }
    for (int i=0;i<n;i++){
		if (ID==stuRecord[i][0]){
			int a = i;
			cond = true;
			cout << "Record Found\nSelect Field to modify:" << endl;
		}
	}
	
	if (cond==false){
		cout << "Record not found";
	}
	
	if (cond==true){
		cout << "1. Name\n2. Age\n3. Contact Information\n3. GPA\n4. Semester\n4. Courses Enrolled\n";
		cin >> modChoice;
		cin.ignore();
		switch (modChoice){
			case 1:
				cout << "Enter New Value: ";
				getline(cin, stuRecord[a][1]);                                                              
				break;
			case 2:
				cout << "Enter New Value: ";
				getline(cin, stuRecord[a][2]);
				break;
			case 3:
				cout << "Enter New Value: ";
				getline(cin, stuRecord[a][3]);
				break;
			case 4:
				cout << "Enter New Value: ";
				getline(cin, stuRecord[a][4]);
				break;
			case 5:
				cout << "Enter New Value: ";
				getline(cin, stuRecord[a][5]);
				break;
			case 6:
				cout << "Enter New Value: ";
				getline(cin, stuRecord[a][6]);
				break;
		}
		checkLen(stuRecord, a);
		upp(stuRecord);
		cout << "Record Updated Successfully!";
	}
}

void deleteRow(string stuRecord[][7], int& a, int& n) {
    for (int i = a; i < n - 1; ++i) {
        std::copy(stuRecord[i + 1], stuRecord[i + 1] + 7, stuRecord[i]);
    }

    // Clear the last row (optional)
    std::fill_n(stuRecord[n - 1], 7, "");

    // Decrement the number of rows
    n--;
}

void deleteStudent(string stuRecord[][7], int& n){
	cin.ignore();
	string ID;
	int a;
	bool cond=false;
	cout << "Delete Student Record" << endl;
	cout << "---------------------" << endl;
	cout << "Enter Student's ID: ";
	getline(cin, ID);
	for (int i=0; i<15; i++) {
        ID[i] = std::toupper(ID[i]);
    }
	for (int i=0;i<n;i++){
		if (ID==stuRecord[i][0]){
			a = i;
			cond = true;
			cout << "Student ID Found.\n";
			deleteRow(stuRecord, a, n);
			cout << "Record Deleted Successfully!";
			break;
		}
	}
	if (cond==false){
		cout << "Student ID not Found.";
	}
}

void searchStudent(string stuRecord[][7], int& n){
	cout << "---------------------" << endl;
	cout << "Search Record by:" << endl;
	cout << "1. Student ID\n2. Name\n3. Contact Information\n";
	int searchChoice;
	string ID, name, conInfo;
	cin >> searchChoice;
	cin.ignore();
	switch (searchChoice){
		case 1:
			cout << "Enter Student ID to search: ";
			getline(cin, ID);
			checkLenID(ID);
			for (int i=0; i<15; i++) {
       			 ID[i] = std::toupper(ID[i]);
    		}
			for (int i=0;i<n;i++){
				if (ID==stuRecord[i][0]){
					int a = i;
					for (int c=0; c<7; c++){
						cout << stuRecord[a][c] << "\t";
					}
					break;
				}
			}
			break;
		case 2:
			cout << "Enter Student Name: ";
			getline(cin, name);
			checkLenName(name);
			for (int i=0; i<name.length(); i++){
       			 name[i] = std::toupper(name[i]);
    		}
			for (int i=0;i<n;i++){
				if (name==stuRecord[i][1]){
					int a = i;
					for (int c=0; c<7; c++){
						cout << stuRecord[a][c] << "\t";
					}
					break;
				}
			}
			break;
		case 3:
			cout << "Enter Student Contact Information: ";
			getline(cin, conInfo);
			checkLenConInfo(conInfo);
			for (int i=0;i<n;i++){
				if (conInfo==stuRecord[i][3]){
					int a = i;
					for (int c=0; c<7; c++){
						cout << stuRecord[a][c] << "\t";
					}
					break;
				}
			}
			break;
	}
}

void displayAll(string stuRecord[][7], int& n){
	cout << "Display All Records" << endl;
	cout << "-------------------" << endl;
	for (int i=0; i<n; i++){
		for (int j=0; j<7; j++){
			cout << stuRecord[i][j] << "\t";
			if (j==1&&stuRecord[i][1].length()>16){
				cout << "\t";
			}
			else if (j==1){
				cout << "\t\t";
			}
		}
		cout << endl;
	}
}

void generateReport(string stuRecord[][7], int& n){
	cout << "Generate Report" << endl;
	cout << "---------------" << endl;
    int bscs=0, bsse=0, bece=0, beee=0, bsaf=0, bsft=0, bese=0;
    string program;

    for (int i=0; i<n; i++){
        program = stuRecord[i][0].substr(5, 4);
        if (program == "BSCS"){
            bscs++;
        }
        if (program == "BSSE"){
            bsse++;
        }
        if (program == "BECE"){
            bece++;
        }
        if (program == "BEEE"){
            beee++;
        }
        if (program == "BSAF"){
            bsaf++;
        }
        if (program == "BSFT"){
            bsft++;
        }
        if (program == "BESE"){
            bese++;
        }
    }
    
    // Move progCount declaration here
    int progCount[7] = {bscs, bsse, bece, beee, bsaf, bsft, bese};

    // Print the program count
    string prog[7] = {"BSCS", "BSSE", "BECE", "BEEE", "BSAF", "BSFT", "BESE"};
    for (int j=0; j<7; j++){
        cout << "Number of students in " << prog[j] << ": " << progCount[j] << endl;
    }
}


int main(){
	string prog[7] = {"BSCS", "BSSE", "BECE", "BEEE", "BSAF", "BSFT", "BESE"};
	string stuRecord[1000][7] = {
        {"FA20-BECE-0001", "AHMED KHAN", "20", "03001234567", "3.5", "EIGHTH", "CS101, CS102"},
        {"SP21-BEEE-0002", "ALI AHMED", "21", "03011234567", "3.6", "SEVENTH", "CS101, CS103"},
        {"FA21-BSCS-0003", "FATIMA BALOCH", "22", "03061234567", "3.8", "SIXTH", "CS102, CS104"},
        {"SP22-BSSE-0004", "AHSAN RAZA", "23", "03241234567", "3.9", "FIFTH", "CS103, CS105"},
        {"FA22-BSAF-0005", "AYESHA IQBAL", "20", "03001234568", "3.4", "FOURTH", "CS104, CS106"},
        {"SP23-BSFT-0006", "USMAN FAROOQ", "21", "03011234568", "3.7", "THIRD", "CS105, CS107"},
        {"FA23-BECE-0007", "ZEESHAN ALI", "22", "03061234568", "3.5", "SECOND", "CS106, CS108"},
        {"SP24-BEEE-0008", "SAAD JAVED", "23", "03241234568", "3.8", "FIRST", "CS107, CS109"},
        {"FA21-BSCS-0009", "RANIA ASLAM", "20", "03001234569", "3.6", "SIXTH", "CS108, CS110"},
        {"SP22-BSSE-0010", "HAMZA SAEED", "21", "03011234569", "3.7", "FIFTH", "CS109, CS111"},
        {"FA22-BSAF-0011", "MARIAM ZUBAIR", "22", "03061234569", "3.9", "FOURTH", "CS110, CS112"},
        {"SP23-BSFT-0012", "SARA RIZWAN", "23", "03241234569", "3.4", "THIRD", "CS111, CS113"},
        {"FA23-BECE-0013", "OMAR SHAHZAD", "20", "03001234570", "3.5", "SECOND", "CS112, CS114"},
        {"SP24-BEEE-0014", "WAQAR HUSSAIN KHAN", "21", "03011234570", "3.6", "FIRST", "CS113, CS115"},
        {"FA20-BSCS-0015", "NIDA FARHAN", "22", "03061234570", "3.8", "EIGHTH", "CS114, CS116"}};


    int n = 15;
    int r = n+1;
    int choice;
	mainMenu();
	cin >> choice;
	while (choice<1||choice>7){
		cout << "INCORRECT INPUT. PLEASE CHOOSE FROM THE TABLE ONLY." << endl;
		cin >> choice;
	}
	while (choice!=7){
		switch (choice){
			case 1:
				addStudent(stuRecord, n);
				break;
			case 2:
				modifyStudent(stuRecord, n);
				break;
			case 3:
				deleteStudent(stuRecord, n);
				break;
			case 4:
				searchStudent(stuRecord, n);
				break;
			case 5:
				displayAll(stuRecord, n);
				break;
			case 6:
				generateReport(stuRecord, n);
				break;
		}
		cout << endl << endl;
		mainMenu();
		cin >> choice;
		while (choice<1||choice>7){
			cout << "INCORRECT INPUT. PLEASE CHOOSE FROM THE TABLE ONLY." << endl;
			cin >> choice;
			cin.ignore();
		}
	}
	
	// Save in a Word File
	ofstream Myfile("CEP.txt");
	if (Myfile.is_open()){
		for (int a=0; a<n; a++){
			for(int b=0; b<7; b++){
				Myfile << stuRecord[a][b] << "\t";
				if (b==1&&stuRecord[a][1].length()>16){
					Myfile << "\t";
				}
				else if (b==1){
					Myfile << "\t\t";
				}
			}
			Myfile << endl;
		}
	}
	Myfile.close();
	
}
