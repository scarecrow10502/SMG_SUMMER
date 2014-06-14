//problem 1 solution
#include<iostream>
using namespace std;
class book{
  
  char* author;
  char* title;
  bool is_free;
  int year;
  char* description;
  
public:
  book(const char*& author, const char*& title, bool is_free, int year, const char*& description){
    this->author = new char[strlen(author)];
    strcpy(this->author, author);
    this->title = new char[strlen(title)];
    strcpy(this->title, title);
    this->is_free = is_free;
    this->year = year;
    this->description = new char[strlen(description)];
    strcpy(this->description, description);
  }
  ~book(){
    delete[] author;
    delete[] title;
    delete[] description;
  }
  //this is not a good idea but for now it's ok!
  void print(){
    cout<<"------------------------------\n";
    cout<<"Title: "<<title<<endl;
    cout<<"Author: "<<author<<endl;
    cout<<"Year: "<<year<<endl;
    cout<<"Is available: "<<(is_free?"yes":"no")<<endl;
    cout<<"Description: "<<description<<endl;
    cout<<"------------------------------\n";
  }
};
int main(){
  int book_number;
  cin>>book_number;
  book** books = new book*[book_number];
  for(int i = 0; i<book_number; i++)
  {
    cin.ignore();
    char author[50];
    cin.getline(author, 50);
    char title[50];
    cin.getline(title, 50);
    char description[1000];
    cin.getline(description,1000);
    char available[4];
    cin>>available;
    bool is_free;
    if(strcmp(available, "Yes") == 0) is_free = true;
    else if(strcmp(available, "No") == 0) is_free = false;
    else{
      while(strcmp(available, "Yes") != 0 && strcmp(available, "No") != 0){
        cin>>available;
        if(strcmp(available, "Yes") == 0) is_free = true;
        else if(strcmp(available, "No") == 0) is_free = false;
      }
    }
    int year;
    cin>>year;
    cin.ignore();
    books[i] = new book(author, title, is_free, year, description);
  }
  for(int i = 0; i<book_number; i++){
    books[i]->print();
  }
  return 0;
}
