#include "sqList.h"

int main()
{
    char a[4]={'a','b','c','d'};
    sqList<char> *l =new sqList<char>(a,4);
    l->dispList();
    l->max_remove(l);
    l->dispList();
    l->add_in_min(l,'e');
    l->dispList();


    sqList<char>* l1 =new sqList<char>();
    l1->insert_in_end('a');
        l1->insert_in_end('b');
            l1->insert_in_end('c');
                l1->insert_in_end('d');
                    l1->insert_in_end('e');
    l1->dispList();
    cout<<l1->get_length()<<endl;
    l1->is_empty();
    l1->dispList(3);
    l1->get_index('a');
    l1->insert(4,'f');
    l1->dispList();
    l1->delete_one(3);
    l1->dispList();
    delete l1;


}