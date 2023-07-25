#include <iostream>
using namespace std;

class Node {
  public:
    char E;
    Node *next;
};

class List {
  private:
    Node *head;
    Node *tail;
    Node *curr;

  public:
    void createList(){
      Node *NewNode = new Node;
      NewNode->next = NULL;
      curr = tail = head = NewNode;
    }

    void insert(char element) {
      Node *NewNode = new Node;
      NewNode->E = element;
      NewNode->next = curr->next;
      curr->next = NewNode;
      if(tail == curr) {
        tail = curr->next;
      }
    }

    void moveToStart(){
      curr = head;
    }

    void next(){
      curr = curr->next;
    }

    void moveToEnd(){
      curr = tail;
    }
    
    void printList(){
      curr = head;
      while (curr != NULL){
        if (curr != head){
          cout << curr->E;
        }
        curr = curr->next;
      }
      cout << '\n';
    }
};

string text;
List lista;

int main(){

  while (cin >> text){
    lista.createList();
    for(int i = 0; i < text.length(); i++){

      if(text[i]=='['){
        lista.moveToStart();}
      
      else if(text[i]==']'){
        lista.moveToEnd();}
      
      else{
        lista.insert(text[i]);}
        lista.next();
    }
    lista.printList();
  }
  return 0;
}