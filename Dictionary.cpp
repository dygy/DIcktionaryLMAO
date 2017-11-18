// Dictionary.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
class DictionaryItem {
private:
    string RUword;
    string ENGWord;

public:

    DictionaryItem(string RUword, string ENGWord) {
        this -> RUword = RUword;
        this -> ENGWord = ENGWord;
    }

    string getRUWord() {
        return RUword;
    }
    string getENGWord() {
        return ENGWord;
    }
};
struct ABC {
    bool operator()( DictionaryItem lhs,DictionaryItem rhs) {
        return lhs.getRUWord() < rhs.getRUWord();
    }
};
void addW(vector<DictionaryItem> * words) {
			string continueWord = "Нет";
			while (continueWord == "Да") {
				string keyWord;
				cout << "Добавьте слово\n";
				cin >> keyWord;
				string translateKeyWord;
				cout << "Добавьте перевод\n";
				cin >> translateKeyWord;
				words->push_back(DictionaryItem(keyWord, translateKeyWord));
				cout << "Вернуться?(Да/Нет)\n";
				cin >> continueWord;
			}
		}
void showSpace(vector<DictionaryItem> * words) {
             sort(words->begin(), words->end(), ABC());
             for(int i = 0; i < words->size() - 1; ++i) {
                 cout << "[" << words->at(i).getRUWord() << "]" << " - " << words->at(i).getENGWord() << "\n";
             }
             cout << "\nЧтобы вернуть нажмите на любую клавишу\n";
             string readWord;
             cin >> readWord;
             return;
         }
void searchW(vector<DictionaryItem> * words) {
			string continueWord = "Нет";
			while (continueWord == "Да") {
				string searchWord;
				cout << "Введите слово\n";
				cin >> searchWord;
				for (int i = 0; i < words->size() - 1; i++) {
					if (words->at(i).getRUWord() == searchWord) {
						cout << "[" << words->at(i).getRUWord() << "]" << " - " << words->at(i).getENGWord() << "\n";
					}
				}
				cout << "Повторить?(Да/Нет)\n";
				cin >> continueWord;
			}
		}
void deleteW(vector<DictionaryItem> * words) {
         string continueWord= "Нет";
            while (continueWord == "Да") {
                string searchWord;
                cout << "Введите слово, перевод которого хотите исключить из словаря\n";
                cin >> searchWord;
                for(int i = 0; i < words->size() - 1; i++) {
                    if (words->at(i).getRUWord() == searchWord) {
                        words->erase(words->begin() + i);
                    }
              }
            cout << "Вернуться?(Да/Нет)\n";
             cin >> continueWord;
         }
        }
void printText(vector<DictionaryItem> * words) {
	sort(words->begin(), words->end(), ABC());
	unsigned long size = words->capacity();
	ofstream fout;
	fout.open("wordbook.txt");
	for (int i = 0; i < words->size() - 1; i++) {
		fout << words->at(i).getRUWord() << " " << words->at(i).getENGWord() << "\n";
	}
	fout.close();
}
void textread(vector<DictionaryItem> * words) {
	ifstream fin;
	string keyWord;
	string translateKeyWord;
	fin.open("wordbook.txt");
	if (!fin.is_open()) {
		cout << "Error";
	}
	while (!fin.eof()) {
		fin >> keyWord;
		fin >> translateKeyWord;
		words->push_back(DictionaryItem(keyWord, translateKeyWord));
	}
	fin.close();
}
void creatSpace() {
	system("clear");
	vector<DictionaryItem> words;
	textread(&words);
	short readNumber;
	string cycle = "Start";
	while (cycle == "Start") {
		system("clear");
		cout << "                       Словарь\n\n1. перевод.\n2.Демонстрация словаря.\n3. Добавить слово.\n4. Удаление слова.\n5. Выход.\n\nВыберите из списка то, что вы хотите осуществить: ";
		cin >> readNumber;

		switch (readNumber) {
		case 1:
			system("clear");
			searchW(&words);
			break;
		case 2:
			system("clear");
			showSpace(&words);
			break;
		case 3:
			system("clear");
			addW(&words);
			break;
		case 4:
			system("clear");
			deleteW(&words);
			break;
		case 5:
			system("clear");
			cycle = "Stop";
			break;
		}
	}
	printText(&words);
	return;
}
int main() {
	system("clear");
	creatSpace();
	return 0;
}
