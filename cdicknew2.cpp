#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <locale>
#include <algorithm>
using namespace std;

class DictionaryItem 
 {
private:
    string word;
    string translateWord;
    
public:
    
    DictionaryItem(string word, string translateWord)
        {
        this -> word = word;
        this -> translateWord = translateWord;
        }
    
    string getWord()
         {
        return word;
         }
    string getTranslateWord()
         {
        return translateWord;
         }
  };

struct Alphabet 
 {
    bool operator()( DictionaryItem lhs,DictionaryItem rhs)
                       {
        return lhs.getWord() < rhs.getWord();
                       }
 };

string lowercase(string word)
 {
    locale loc;
    string upgradeWord = "";
    for (int i = 0; i < word.length(); ++i)
          {
        upgradeWord += tolower(word[i],loc);
          }
    return upgradeWord;
 }
void addWords(vector<DictionaryItem> * words)
 {
    string continueWord;
    while (continueWord != "y")
       {
        continueWord = "";
        system("cls");
        string keyWord;
        cout << "enter english word" <<'\n';
        cin >> keyWord;
        string translateKeyWord;
        cout << "enter translation" << '\n';
        cin >> translateKeyWord;
        words->push_back(DictionaryItem(keyWord,translateKeyWord));
        while(continueWord != "y" && continueWord != "n")
           {
            system("cls");
            cout << "return?(Y/N)" << '\n';
            cin >> continueWord;
            continueWord = lowercase(continueWord);
           }
       }
 }    

void showDictionary(vector<DictionaryItem> * words)
 {
    system("cls");
    sort(words->begin(), words->end(), Alphabet());
    for(int i = 0; i < words->size(); ++i)
      {
        cout << "[" << words->at(i).getWord() << "]" << " - " << words->at(i).getTranslateWord() << '\n';
      }
    cout << "press any letter for return" <<'\n';
    string continueWord = "";
    while(continueWord == "") 
       {
        cin >> continueWord;
       }
    return;
 }
void changeWords(vector<DictionaryItem> * words) 
 {
    string continueWord;
    string ans;
    while (continueWord != "y")
       {
        system("cls");
        continueWord = "";
        ans="";
        bool itDone = false;
        string searchWord;
        cout << "entewr word for translation" << '\n';
        cin >> searchWord;
        searchWord = lowercase(searchWord);
        int ind=words->size();
        for(int i = 0; i <  ind; i++)
          {
            string word = words->at(i).getWord();
            string newTranslation;
            word = lowercase(word);
            if (word == searchWord) 
                {
               cout << "[" << words->at(i).getWord() << "]" << " - " << words->at(i).getTranslateWord() << '\n';
               cout << "change? Y/N" << '\n';
               cin >> ans;
               if (ans=="y")
                  {
               words->erase(words-> begin() + i);
               cout << "enter new translation" << '\n';
               cin >> newTranslation;
               words->push_back(DictionaryItem(word,newTranslation));
               break; 
                  }
               itDone = true;
                }
           }
        if(!itDone)
          {
            cout << "word is not found" << '\n';
          }
        while(continueWord != "y" && continueWord != "n")
          {
            cout << "return?(Y/N)"<<'\n';
            cin >> continueWord;
            continueWord = lowercase(continueWord);
          }
       }
  }
void searchWords(vector<DictionaryItem> * words) 
 {
    string continueWord;
    while (continueWord != "y")
       {
        system("cls");
        continueWord = "";
        bool itDone = false;
        string searchWord;
        cout << "entewr word for translation" << '\n';
        cin >> searchWord;
        searchWord = lowercase(searchWord);
        for(int i = 0; i <  words->size(); i++)
          {
            string word = words->at(i).getWord();
            word = lowercase(word);
            if (word == searchWord) 
                {
                cout << "[" << words->at(i).getWord() << "]" << " - " << words->at(i).getTranslateWord() << '\n';
                itDone = true;
                }
           }
        if(!itDone)
          {
            cout << "word is not found" << '\n';
          }
        while(continueWord != "y" && continueWord != "n")
          {
            cout << "return?(Y/N)"<<'\n';
            cin >> continueWord;
            continueWord = lowercase(continueWord);
          }
       }
  }

void deleteWords(vector<DictionaryItem> * words)
 {
    string continueWord;
    while (continueWord != "y") 
       {
        system("cls");
        continueWord = "";
        string searchWord;
        bool itDone = false;
        cout << "enter word for translation delete" << '\n';
        cin >> searchWord;
        searchWord = lowercase(searchWord);
        for(int i = 0; i <  words->size(); i++) 
          {
            string word = words->at(i).getWord();
            word = lowercase(word);
            if (word == searchWord) 
             {
                words->erase(words->begin() + i);
                itDone = true;
            }
          }
        if(!itDone)
          {
            cout << "word was not found" << '\n';
          }
        while(continueWord != "y" && continueWord != "n") 
          {
            cout << "return?(Y/N)" <<'\n';
            cin >> continueWord;
            continueWord = lowercase(continueWord);
          }
      }
}

void printText(vector<DictionaryItem> * words) 
 {
    sort(words->begin(), words->end(), Alphabet());
    unsigned long size = words->capacity();
    ofstream fout;
    fout.open("dictionary.txt");
    for(int i = 0; i <  words->size(); i++) 
      {
        if (i == words->size() - 1) 
        {
            fout << words->at(i).getWord() << " "<< words->at(i).getTranslateWord();
        } 
        else {
            fout << words->at(i).getWord() << " "<< words->at(i).getTranslateWord() << '\n';
             }
      }
    fout.close();
  }

void readText(vector<DictionaryItem> * words)
 {
    ifstream fin;
    string keyWord;
    string translateKeyWord;
    fin.open("dictionary.txt");
    if (!fin.is_open()) 
       {
        cout << "Error";
       }
    while(!fin.eof()) 
       {
        fin >>  keyWord;
        fin >> translateKeyWord;
        words->push_back(DictionaryItem(keyWord,translateKeyWord));
       }
    fin.close();
 }

void creatDictionary() {
    system("cls");
    vector<DictionaryItem> words;
    readText(&words);
    short readNumber;
    string cycle = "Start";
    while (cycle == "Start") 
          {
        system("cls");
        cout << " dictionary menu"<<'\n';
        cout << " 1. find translation"<<'\n';
        cout << " 2. demonstrate of dictionary"<<'\n';
        cout << " 3. enter new words"<<'\n';
        cout << " 4. delete words"<<'\n';
        cout << " 5. change words"<<'\n';
        cout << " 6. exit"<<'\n';
        cout << " select number from menu:";
        cin >> readNumber;
        
        switch (readNumber) 
          {
            case 1:
                searchWords(&words);
                break;
            case 2:
                showDictionary(&words);
                break;
            case 3:
                addWords(&words);
                break;
            case 4:
                deleteWords(&words);
                break;
            case 5:
                changeWords(&words);
                break;
            case 6:
                system("cls");
                cycle = "Stop";
                break;
            default:
                break;
          }
        
    }
    printText(&words);
    return;
 }

int main()
 {
    system("cls");
    creatDictionary();
    return 0;
 }