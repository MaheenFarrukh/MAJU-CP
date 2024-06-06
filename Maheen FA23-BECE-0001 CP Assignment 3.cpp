#include <iostream>
using namespace std;


void checkChoice(int& choice){
	while (choice<1||choice>3){
		cout << "Oops! Your choice is out of range!\nTry Again.\n";
		cin >> choice;
	}
} 

int selectQuiz(){
	cout << "Welcome to the Quiz game!" << endl;
	cout << "Select the topic you would like to take the Quiz on:" << endl;
	cout << "1.Math\n2.History\n3.Pop Culture" << endl;
	int choice;
	cin >> choice;
	checkChoice(choice);
	return choice;
}

void demo(){
	cout << "Welcome to Quiz Demo!" << endl;
	cout << "---------------------" << endl << endl;
	cout << "Instructions:\n";
	cout << "You will be given a multiple choice question.\nYou only have to pick one answer\n";
	cout << "You cannot go back, forward or skip a question." << endl;
	cout << endl;
	cout << "Sample Question: What is 2+2?\n";
	cout << "1. 3\n2. 4\n3. 6" << endl;
	cout << "You can enter 1, 2, or 3 to select the answer" << endl;
	cout << "This is how to play the Quiz. Good Luck!" << endl << endl;
}

void quizMath(int& correct, int&incorrect){
	cin.ignore();
	int ansMath[10] = {2, 2, 3, 3, 2, 2, 2, 2, 2, 2};
	int choice;
	string quesMath[10] = {
		"What is the value of 7 x 8?",
		"Simplify 12 divided by 4",
		"What is the square root of 81",
		"Solve for x\n5x = 25",
		"What is the sum of the angles in a triangle",
		"What is 15% of 200?",
		"Simplify 3\\4 + 1\\4",
		"Find the perimeter of a square with side length 5",
		"What is 3²",
		"What is the next prime number after 7?"
	};
	string oppMath[10][3] ={
		{"54", "56", "64"},
		{"2", "3", "4"},
		{"7", "8", "9"},
		{"3", "4", "5"},
		{"90 degrees", "180 degrees", "360 degrees"},
		{"20", "25", "30"},
		{"1//2", "1", "3//2"},
		{"15", "20", "25"},
		{"6", "9", "12"},
		{"9", "11", "13"}
	};
	for (int i=0; i<10; i++){
		cout << "Question " << i+1 << endl;
		cout << "----------" << endl;
		cout << quesMath[i] << endl;
		for (int j=0; j<3; j++){
			cout << j+1 << ". " << oppMath[i][j] << endl;
		}
		cin >> choice;
		checkChoice(choice);
		if (choice==ansMath[i]){
			correct++;
		}
		else{
			incorrect++;
		}
		//cin.ignore();
	} 
}

void quizHistory(int& correct, int&incorrect){
	cin.ignore();
	int ansHistory[10] = {2, 2, 1, 1, 3, 2, 2, 2, 2, 2};
	int choice;
	string quesHistory[10] = {
		"Who is considered the founding father of Pakistan?",
		"In what year did Pakistan gain independence from British rule?",
		"What was the original capital of Pakistan after independence?",
		"Which language was declared the national language of Pakistan in 1948?",
		"Who was the first Prime Minister of Pakistan?",
		"When did East Pakistan become Bangladesh?",
		"What is the name of Pakistan's first female Prime Minister?",
		"Which country was the first to recognize Pakistan after its independence?",
		"In which year did Pakistan become a nuclear power?",
		"Who led Pakistan during the Kargil War in 1999?",
	};
	string oppHistory[10][3] ={
		{"Liaquat Ali Khan", "Muhammad Ali Jinnah", "Allama Iqbal"},
		{"1945", "1947", "1949"},
		{"Karachi", "Islamabad", "Lahore"},
		{"Urdu", "Punjabi", "Bengali"},
		{"Ayub Khan", "Zulfikar Ali Bhutto", "Liaquat Ali Khan"},
		{"1969", "1971", "1973"},
		{"Fatima Jinnah", "Benazir Bhutto", "Hina Rabbani Khar"},
		{"United States", "Iran", "Saudi Arabia"},
		{"1996", "1998", "2000"},
		{"Nawaz Sharif", "Pervez Musharraf", "Asif Ali Zardari"}
	};
	for (int i=0; i<10; i++){
		cout << "Question " << i+1 << endl;
		cout << "----------" << endl;
		cout << quesHistory[i] << endl;
		for (int j=0; j<3; j++){
			cout << j+1 << ". " << oppHistory[i][j] << endl;
		}
		cin >> choice;
		checkChoice(choice);
		if (choice==ansHistory[i]){
			correct++;
		}
		else{
			incorrect++;
		}
		//cin.ignore();
	} 
}

void quizPopCulture(int& correct, int&incorrect){
	cin.ignore();
	int ansPopCulture[10] = {1, 2, 2, 1, 2, 2, 1, 3, 3, 2};
	int choice;
	string quesPopCulture[10] = {
		"Who played Jack Dawson in the movie Titanic?",
		"What year was the first iPhone released?",
		"Which artist sang \"Thriller\"?",
		"What is the name of Harry Potter's pet owl?",
		"Which TV Show features a character named Sheldon Cooper",
		"Who is the creator of the Star Wars franchise?",
		"What was the highest grossing film of 1997?",
		"Which band was Freddie Mercury the lead singer of?",
		"In which city is the TV show \"Friends\" set?",
		"Who wrote the novel 1984?"
	};
	string oppPopCulture[10][3] ={
		{"Leonardo DiCaprio", "Bradd Pitt", "Tom Hanks"},
		{"2005", "2007", "2009"},
		{"Prince", "Michael Jackson", "Madonna"},
		{"Hedwig", "Errol", "Crookshanks"},
		{"Friends", "The Big Bang Theory", "How I Met Your Mother"},
		{"Steven Spielberg", "George Lucas", "James Cameron"},
		{"Titanic", "Men in Black", "Jurassic Park"},
		{"The Beatles", "The Rolling Stones", "Queen"},
		{"Los Angeles", "Chicago", "New York"},
		{"Aldous Huxley", "George Orwell", "Ray Bradbury"}
	};
	for (int i=0; i<10; i++){
		cout << "Question " << i+1 << endl;
		cout << "----------" << endl;
		cout << quesPopCulture[i] << endl;
		for (int j=0; j<3; j++){
			cout << j+1 << ". " << oppPopCulture[i][j] << endl;
		}
		cin >> choice;
		checkChoice(choice);
		choice = choice-1;
		if (choice==ansPopCulture[i]){
			correct++;
		}
		else{
			incorrect++;
		}
		//cin.ignore();
	} 
}

int main(){
	int correct=0, incorrect=0;
	string name;
	demo();
	cout << endl;
	cout << "Enter your name: ";
	getline(cin, name);
	cout << endl;
	int choice=selectQuiz();
	
	switch (choice){
		case 1:
			quizMath(correct, incorrect);
			break;
		case 2:
			quizHistory(correct, incorrect);
			break;
		case 3:
			quizPopCulture(correct, incorrect);
			break;
	}
	cout << "Correct Answers: " << correct << endl;
	cout << "Incorrect Answers: " << incorrect << endl; 
	cout << "Thanks For Playing" << name << "!" << endl;
	cout << "\n\nMaheen Farrukh Khan\nFA23-BECE-0001";
}