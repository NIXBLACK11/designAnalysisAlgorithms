#include<iostream>
#include<string>

using namespace std;

class Trie {
public:
    struct node {
        node* child[26];
        bool isWord;
    };

    node* newNode() {
        struct node* temp = new node();
        temp->isWord = false;
        for(int i=0;i<26;i++) {
            temp->child[i] = NULL;
        }
        return temp;
    }

    node *head;

    Trie() {
        head = newNode();
    }
    
    void insert(string word) {
        node *curr = head;
        int n = word.size();
        for(int i=0;i<n;i++) {
            int ch = word[i]-'a';
            if(curr->child[ch]==NULL) {
                curr->child[ch] = newNode();
            }
            curr = curr->child[ch];
        }
        curr->isWord = true;
    }
    
    bool search(string word) {
        node *curr = head;
        int n = word.size();
        for(int i=0;i<n;i++) {
            int ch = word[i]-'a';
            if(curr->child[ch]==NULL) {
                return false;
            }
            curr = curr->child[ch];
        }
        return curr->isWord;
    }
    
    bool startsWith(string prefix) {
        node *curr = head;
        int n = prefix.size();
        for(int i=0;i<n;i++) {
            int ch = prefix[i]-'a';
            if(curr->child[ch]==NULL) {
                return false;
            }
            curr = curr->child[ch];
        }
        return true;
    }

    bool checkUtils(node* curr) {
        for(int i=0;i<26;i++) {
            if(curr->child[i]) {
                return false;
            }
        }
        return true;
    }

    bool deleteUtils(node* curr, int i, string word, int n) {
        bool val;

        if(i<n && curr->child[word[i]-'a']!=NULL) {
            val = deleteUtils(curr->child[word[i]-'a'], i+1, word, n);
        }

        if(i==n-1 && checkUtils(curr) && val) {
            delete curr;
            return true;
        } else {
            curr->isWord = false;
            return false;
        }
    }

    bool deleteT(string word) {
        if(search(word)) {
            node* curr = head;
            deleteUtils(curr, 0, word, word.size());
            return true;
        }
        return false;
    }

};

int main() {
    Trie tr;
    cout<<"\nEnter the word to insert:\n";
    char ch;
    string s;
    while(true) {
        cout<<"\nEnter i for insert, d for delete, s for search, p for prefix\n";
        cin>>ch;
        switch(ch) {
            case 'i':
                cout<<"\nEnter the string to insert\n";
                cin>>s;
                tr.insert(s);
                break;
            case 'd':
                cout<<"\nEnter the string to delete\n";
                cin>>s;
                cout<<"\nString" << (tr.deleteT(s) == true ? "Deleted\n" : "Not Deleted\n");
                break;
            case 's':
                cout<<"\nEnter the string to search\n";
                cin>>s;
                cout<<"\nString" << (tr.search(s) == true ? "Found\n" : "Not Found\n");
                break;
            case 'p':
                cout<<"\nEnter the string to prefix\n";
                cin>>s;
                cout<<"\nString" << (tr.startsWith(s) == true ? "Found\n" : "Not Found\n");
                break;
            default:
                cout<<"\n wrong input\n";
                break;
        }
    }
}
