#include <cassert>

#include "list.h"

int main(){

      //ls::list<int> my_list2({0, 1, 2});
      //ls::list<int> my_list3({0, 1, 5});
      //ls::list<int> l2(10);
      //ls::list<int> l1 = l2;

        //ls::list<int> l1({0, 1, 2, 4});
        //ls::list<int> l1 = {0, 1, 2};


        ls::list<int> mylist;
        //int foo [5] = { 16, 2, 77, 40, 12071 };
        //ls::list<int> l1(&foo[0],&foo[3]);
        ls::list<int>::iterator iter;
        ls::list<int>::iterator iter2;
        mylist.push_back(1);
        mylist.push_back(2);
        mylist.push_back(3);
        mylist.push_back(4);
        mylist.push_back(5);
        mylist.push_back(6);
        mylist.push_back(7);
        mylist.push_back(8);
        mylist.push_front(30);
        mylist.insert(iter,80);
        iter = mylist.begin();
        iter2 = mylist.begin();
        iter++;
        iter++;
        iter2++;
        //mylist.insert(iter,&foo[0],&foo[5]);
        //std::cout << ' ' <<  (my_list2!=my_list3)<< std::endl;

        std::cout << "mylist contains:";
        for (ls::list<int>::iterator it=mylist.begin(); it!=mylist.end(); it++)
          std::cout << ' ' << (*it)->data<<std::endl;




    return 0;
  }
