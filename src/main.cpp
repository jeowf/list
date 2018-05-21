#include <cassert>

#include "list.h"

int main(){
    
        ls::list<int> l1({0, 1, 2, 4});
        //ls::list<int> my_list2 = {0, 1, 2};
    

    
        // ls::list<int> mylist;
        // //int foo [5] = { 16, 2, 77, 40, 12071 };
        // ls::list<int>::iterator iter;
        // ls::list<int>::iterator iter2;
        // mylist.push_back(1);
        // mylist.push_back(2);
        // mylist.push_back(3);
        // mylist.push_back(4);
        // mylist.push_back(5);
        // mylist.push_back(6);
        // mylist.push_back(7);
        // mylist.push_back(8);
        // mylist.push_front(30);
        // mylist.insert(iter,80);
        // iter = mylist.begin();
        // iter2 = mylist.begin();
        // iter++;
        // iter++;
        // iter2++;
        // mylist.erase(iter2,iter);
        // std::cout << ' ' <<  (*iter)->data<< std::endl;

        std::cout << "mylist contains:";
        for (ls::list<int>::iterator it=l1.begin(); it!=l1.end(); it++)
          std::cout << ' ' << (*it)->data<<std::endl;

    
    

    return 0;
  }
