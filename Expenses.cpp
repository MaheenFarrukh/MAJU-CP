#include <iostream>
using namespace std;

void expenses(int emp_exp[10][6]);

int main(){
	int salary;
	int emp_exp[10][6]={0};
	for (int i=0; i<10; i++){
		cout << "Employee ID: " << i+1 << endl;
		cout << "---------------" << endl;
		cout << "Enter Monthly Salary: ";
		cin >> salary;
		emp_exp[i][0]=i+1;
		emp_exp[i][1]=salary;
	}
	expenses(emp_exp);
}

void expenses(int emp_exp[10][6]){
	for (int a=0; a<10; a++){
		emp_exp[a][2]= emp_exp[a][1]*0.05;
		emp_exp[a][3]= emp_exp[a][1]*0.1;
		emp_exp[a][4]= emp_exp[a][1]*0.15;
		emp_exp[a][5]= emp_exp[a][1]-(emp_exp[a][2]+emp_exp[a][3]+emp_exp[a][4]);
	}
	
	cout << "Empolyee ID\tSalary\t\tTax(5%)\t\tRent(10%)\tOtherExpenses(15%)\tSavings" << endl;
	for (int j=0; j<10; j++){
		for (int k=0; k<6; k++){
			cout << emp_exp[j][k] << "\t\t";
		}
		cout << endl;
	}
}