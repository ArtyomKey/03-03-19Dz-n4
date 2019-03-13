#define INTLIST
using namespace std;

class int_list{
  private:
    struct Node {
      Node() : next( NULL ) {}
      Node( const T& t ) : data( t ), next( NULL ) {}
      // Значение узла
      int data;
      // Указатель на следующий узел
      Node* next;
    };
    Node* head;
  public:
    int_list();
    int_list(int_list& A);
    ~int_list();
    int operator[] (unsigned int n);
    void insert(unsigned int n, int x);
    int ins_pop(unsigned int n);  
};

int_list::int_list: head(NULL){};
int_list::int_list(int_list A){
  head = A.head;
};
int_list::~int_list(){
  while(head != NULL){
    Node* temp = head;
    head = head->next;
    delete temp;
  }
};
int int_list operator[](int n){
  Node* temp = head;
  for(it i = 0; i < n; i++){
    temp.head = temp->next;
  }
  int x = temp->data;
  delete temp;
  return x;
}
void int_list::insert(unsigned int n, int x){
  Node* temp = head;
  for(it i = 0; i < n-1; i++){
    temp.head = temp->next;
  }
  Node* temp1 = temp.head;
  temp->next->data = x;
  temp->next->next = temp1;
  head = temp;  
}
int int_list::ins_pop(unsigned int n){
  Node* temp = head;
  for(it i = 0; i < n-1; i++){
    temp.head = temp->next;
  }
  temp->next = temp->next->next;
  head = temp;
}