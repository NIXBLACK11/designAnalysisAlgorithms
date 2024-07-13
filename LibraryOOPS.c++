/*
USER :  Library -> array[BOOK]
        Active -> BOOK

BOOK :  Name -> String
        Text -> array[string]
        Current -> pair<int, int>
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BOOK {
    string name;
    vector<string> text;
    int currentPage;
    
public:
    void setBOOK(string name, vector<string> text) {
        this->name = name;
        this->text = text;
        this->currentPage = 0;
    }
    
    void setCurrentPage(int currentPage) {
        this->currentPage = currentPage;
    }
    
    string getCurrentPage() {
        return text[currentPage];
    }
    
    string getBookName() {
        return name;
    }
};

class USER {
    string name;
    vector<BOOK> library;
    int active;
    
public:
    void setUser(string name) {
        this->name = name;
    }
    
    void addToLibrary(BOOK book) {
        library.push_back(book);
    }
    
    void setActive(string bookName, int currentPage) {
        int id = 0;
        for(auto it: library) {
            if(it.getBookName() == bookName) {
                it.setCurrentPage(currentPage);
                break;
            }
            id++;
        }
        
        active = id;
    }
    
    string getCurrentPage() {
        return library[active].getCurrentPage();
    }
    
    string getCurrentBook() {
        return library[active].getBookName();
    }
    
    vector<string> getLibrary() {
        vector<string> names;
        for(auto it: library) {
            names.push_back(it.getBookName());
        }
        
        return names;
    }
};

int main() {
    BOOK ob1;
    BOOK ob2;
    ob1.setBOOK("First book", {"first first page", "second second page"});
    ob2.setBOOK("Second book", {"first second page", "second second page"});
    
    USER us;
    us.setUser("siddharth");
    us.addToLibrary(ob1);
    us.addToLibrary(ob2);
    
    for(auto it: us.getLibrary()) {
        cout<<it<<", ";
    }
    cout<<endl;
    
    us.setActive("First book", 1);
    
    cout<<us.getCurrentBook()<<endl;
    
    cout<<us.getCurrentPage()<<endl;
    
    cout<<"------------"<<endl;
    
    USER us2;
    us2.setUser("us2");
    us2.addToLibrary(ob1);
    for(auto it: us2.getLibrary()) {
        cout<<it<<", ";
    }
    cout<<endl;
    
    cout<<us2.getCurrentBook()<<endl;
    
    cout<<us2.getCurrentPage()<<endl;
    
    
    
    return 0;
}
