#include <cstdlib>
#include <valarray>
#include<iostream>
#include<climits>

using namespace std;

typedef struct stack{
    int reg;
    struct stack* next;
}pilha;

class Stack
{
private:
    pilha* a;
    pilha* m;
public:
    Stack(){a = NULL;m = NULL;}
    bool isEmpty();
    int pop();
    int pop_min();
    int peek();
    int peek_min();
    void push_min(int reg);
    void push(int reg);
    int min();
};

bool Stack::isEmpty(){
    if (a == NULL) {
        return true;
    }else {
        return false;
    }
}

void Stack::push_min(int reg){
    pilha* aux = (pilha*)malloc(sizeof(pilha)); 
    aux->reg = reg;
    aux->next = m;
    m = aux;
}

int Stack::peek_min(){
    return m->reg;
}

int Stack::pop_min(){
    int aux = peek_min();
    m = m->next;
    return aux;
}

void Stack::push(int reg){
    if (isEmpty()){
        push_min(reg);
    }else{
        if (peek_min() <= reg){
            push_min(peek_min());
        }else{
            push_min(reg);
        }
    }
    pilha* aux = (pilha*)malloc(sizeof(pilha)); 
    aux->reg = reg;
    aux->next = a;
    a = aux;
}

int Stack::peek(){
    return a->reg;
}

int Stack::pop(){
    int aux = peek();
    a = a->next;
    int nulo = pop_min();
    return aux;
}

int Stack::min(){
    if (isEmpty()){
        return INT_MIN;
    }else{
        return peek_min();
    }
}

int main(int argc, char** argv) {
    int entrada;
    Stack estrutura;
    for (int i = 0;i<10;i++){
        cin>>entrada;
        estrutura.push(entrada);
    }
    cout<<estrutura.min();
    return 0;
}

