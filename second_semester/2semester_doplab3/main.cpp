#include <iostream>
#define N 10
#define M 5
struct DC_List
{
    struct DC_List* next;
    struct DC_List* prev;
    int field;
};
void ADD(DC_List* head,int data)
{
    auto *p = head->next;
    auto *tmp = new DC_List;
    tmp->field = data;
    tmp->next = p;
    tmp->prev = head;
    if(head->next!=head) {
        p->prev = tmp;
    }
    head->next = tmp;
    if(head->prev == head)
        head->prev=head->next;
}
void INSERT(DC_List* head, int data, int place)
{
    struct DC_List* p = head->next;
    struct DC_List* tmp = new DC_List;
//    tmp->field = data;
    int s=1;
    while(p!= head)
    {
        if(s==place)
        {
            tmp->next = p->next;
            tmp->prev=p;
            p->next=tmp;
            tmp->next->prev=tmp;
            tmp->field = p->field;
            p->field = data;
            break;
        }
        s++;
        p=p->next;
    }
}
void DELETE(DC_List* head,int place)
{
    auto* p = head;
    int s=0;
    while (p->next != head) {
        if (s + 1 == place) {
            auto* tmp = p->next;
            p->next = p->next->next;
            tmp->next->prev = p;
            delete tmp;
            break;
            }
        p = p->next;
        s++;

    }
}


void printNext(DC_List* head)
{
    auto* p = head->next;
    while(p != head)
    {
        std::cout<<p->field<<" ";
        p = p->next;
    }
}
void printDown(DC_List* head)
{
    auto* p = head->prev;
    while(p != head)
    {
        std::cout<<p->field<<" ";
        p = p->prev;
    }
}
void CLEAR(DC_List* head)
{
    DC_List* tmp;
    auto* p = head->next;
    while(p != head)
    {
        tmp=p;
        p = p->next;
        delete tmp;
    }
}

int main() {
    srand(time(0));
    auto* head = new DC_List;
    head->next = head;
    head->prev = head;
    for(int j=0;j<N;j++)
        ADD(head,1+rand()%20);
    printNext(head);
    for(int j=0;j<M;j++)
        INSERT(head,-(1+rand()%20),1+rand()%N);
    std::cout<<"\n";
    printNext(head);
    for(int j=0;j<M;j++)
        DELETE(head,1+rand()%N);
    std::cout<<"\n";
    printNext(head);
    std::cout<<"\n";
    printDown(head);
    CLEAR(head);
    delete head;
    return 0;
}
