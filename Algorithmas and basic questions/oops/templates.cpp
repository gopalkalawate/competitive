#include<iostream>
using namespace std;

template <typename T,typename T1>
class Node{
    T data;
    T1 data1;
    Node *next;
    
    public:



        void insertBeg(Node **head, T data,T1 data1){
            Node *newnode = new(Node);
            newnode->data = data;
            newnode->data1 = data1;
            if(*head == NULL){
                *head = newnode;
                newnode->next = NULL;
                return;
            }

            newnode->next = *head;
            (*head) = newnode;
        }

        void display(Node *head){
            Node *tmp = head;

            while(tmp!=NULL){
                cout<<tmp->data<<"->"<<tmp->data1<<'\n';
                tmp = tmp->next;
            }

        }
        
};

int main(){
    Node<int,char> gk; // Specify the template parameter as int
    Node<int,char>* head = nullptr; // Initialize head to nullptr
    gk.insertBeg(&head, 10,'a');
    gk.insertBeg(&head,100,'b');
    gk.display(head);
    return 0;
}