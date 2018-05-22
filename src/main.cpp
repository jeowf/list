#include <cassert>

#include "list.h"

void printlist(ls::list<int>::iterator it,ls::list<int>::iterator begin,ls::list<int>::iterator end);

int main(){
        ls::list<int>::iterator main_iter;
        ls::list<int>::iterator iter1;
        ls::list<int>::iterator iter2;
        int range [] = {7,8,9};

        std::cout << " Criando construtor regular vazio"<<std::endl;
        ls::list<int> mylist;
        std::cout << " Tamanho = " << mylist.size()<< std::endl;
        printlist(main_iter,mylist.begin(),mylist.end());

        std::cout << " Verifica se a lista criada esta vazia"<<std::endl;
        std::cout << " Vazio = " << mylist.empty()<< std::endl;
        printlist(main_iter,mylist.begin(),mylist.end());

        std::cout << " Adicionando os elementos [10,20] no fim da lista"<<std::endl;
        mylist.push_back(10);
        mylist.push_back(20);
        std::cout << " Tamanho = " << mylist.size()<< std::endl;
        printlist(main_iter,mylist.begin(),mylist.end());

        std::cout << " Verifica novamente se a lista criada esta vazia"<<std::endl;
        std::cout << " Vazio = " << mylist.empty()<< std::endl;
        printlist(main_iter,mylist.begin(),mylist.end());


        std::cout << " Adicionando os elementos [100,200] no inicio da lista"<<std::endl;
        mylist.push_front(200);
        mylist.push_front(100);
        std::cout << " Tamanho = " << mylist.size()<< std::endl;
        printlist(main_iter,mylist.begin(),mylist.end());

        std::cout << " Deletando o primeiro elemento da lista"<<std::endl;
        mylist.pop_front();
        std::cout << " Tamanho = " << mylist.size()<< std::endl;
        printlist(main_iter,mylist.begin(),mylist.end());

        std::cout << " Deletando o ultimo elemento da lista"<<std::endl;
        mylist.pop_back();
        std::cout << " Tamanho = " << mylist.size()<< std::endl;
        printlist(main_iter,mylist.begin(),mylist.end());

        std::cout << " Limpando a Lista"<<std::endl;
        mylist.clear();
        std::cout << " Tamanho = " << mylist.size()<< std::endl;
        printlist(main_iter,mylist.begin(),mylist.end());

        std::cout << " Adicionando os elementos [1,2,3,4,5] no fim da lista"<<std::endl;
        mylist.push_back(1);
        mylist.push_back(2);
        mylist.push_back(3);
        mylist.push_back(4);
        mylist.push_back(5);
        std::cout << " Tamanho = " << mylist.size()<< std::endl;
        printlist(main_iter,mylist.begin(),mylist.end());

        std::cout << " Retornando o elemento na frente da Lista"<<std::endl;
        std::cout << " Primeiro elemento = " <<mylist.front()<< std::endl;
        printlist(main_iter,mylist.begin(),mylist.end());

        std::cout << " Retornando o elemento na final da Lista"<<std::endl;
        std::cout << " Primeiro elemento = " <<mylist.back()<< std::endl;
        printlist(main_iter,mylist.begin(),mylist.end());

        std::cout << " Inserindo [0] antes do terceiro elemento"<<std::endl;
        iter1 = mylist.begin();
        iter1++;
        iter1++;
        mylist.insert(iter1,0);
        std::cout << " Tamanho = " << mylist.size()<< std::endl;
        printlist(main_iter,mylist.begin(),mylist.end());

        std::cout << " Inserindo o range [7,8,9) antes do quinto elemento"<<std::endl;
        iter1++;
        mylist.insert(iter1,&range[0],&range[2]);
        std::cout << " Tamanho = " << mylist.size()<< std::endl;
        printlist(main_iter,mylist.begin(),mylist.end());

        std::cout << " Inserindo a lista {10,11} antes do oitavo elemento"<<std::endl;
        iter1++;
        mylist.insert(iter1,{10,11});
        std::cout << " Tamanho = " << mylist.size()<< std::endl;
        printlist(main_iter,mylist.begin(),mylist.end());

        std::cout << " Deletando o terceiro elemento da lista"<<std::endl;
        iter1 = mylist.begin();
        iter1++;
        iter1++;
        mylist.erase(iter1);
        std::cout << " Tamanho = " << mylist.size()<< std::endl;
        printlist(main_iter,mylist.begin(),mylist.end());

        std::cout << " Deletando do primeiro ao terceiro elemento da lista"<<std::endl;
        iter1 = mylist.begin();
        iter2 = mylist.begin();
        iter1++;
        iter1++;
        iter1++;
        mylist.erase(iter2,iter1);
        std::cout << " Tamanho = " << mylist.size()<< std::endl;
        printlist(main_iter,mylist.begin(),mylist.end());

        std::cout << " Encontrando o elemento [10] na lista"<<std::endl;
        std::cout << " Iterador apontado para = " << (*mylist.find(10))<< std::endl;
        printlist(main_iter,mylist.begin(),mylist.end());

        std::cout << " Substituindo os 2 primeiros elementos por [15,12,25)"<<std::endl;
        int range2 [] = {15,12,25};
        mylist.assign(&range2[0],&range2[2]);
        std::cout << " Tamanho = " << mylist.size()<< std::endl;
        printlist(main_iter,mylist.begin(),mylist.end());


        std::cout << " Substituindo os 3 primeiros elementos por {30,60,90}"<<std::endl;
        mylist.assign({30,60,90});
        std::cout << " Tamanho = " << mylist.size()<< std::endl;
        printlist(main_iter,mylist.begin(),mylist.end());

        std::cout << " Criando construtor count com 10 instancias"<<std::endl;
        ls::list<int> mylist2(10);
        std::cout << " Tamanho = " << mylist2.size()<< std::endl;
        printlist(main_iter,mylist2.begin(),mylist2.end());

        std::cout << " Substituindo todos os valores do contrutor count por 10"<<std::endl;
        mylist2.assign(10);
        std::cout << " Tamanho = " << mylist2.size()<< std::endl;
        printlist(main_iter,mylist2.begin(),mylist2.end());

        std::cout << " Criando construtor copia com os valores do construtor count"<<std::endl;
        ls::list<int> mylist3(mylist2);
        std::cout << " Tamanho = " << mylist3.size()<< std::endl;
        printlist(main_iter,mylist3.begin(),mylist3.end());

        std::cout << " Comparando o contrutor copia com count para vericar se sao iguais"<<std::endl;
        std::cout << " Copia e Count sao iguais= " <<(mylist2 == mylist3)<< std::endl<<std::endl;

        std::cout << " Comparando o contrutor count com o regular para vericar se sao diferentes"<<std::endl;
        std::cout << " Regular e Count sao diferentes= " <<(mylist2 != mylist)<< std::endl<<std::endl;

        std::cout << " Criando construtor initializer_list com os valores {9,8,7,6,5}"<<std::endl;
        ls::list<int> mylist4({9,8,7,6,5});
        std::cout << " Tamanho = " << mylist4.size()<< std::endl;
        printlist(main_iter,mylist4.begin(),mylist4.end());

        std::cout << " Criando construtor range com os valores [9,8,7,6,5)"<<std::endl;
        int range3 [] = {9,8,7,6,5};
        ls::list<int> mylist5(&range3[0],&range3[4]);
        std::cout << " Tamanho = " << mylist5.size()<< std::endl;
        printlist(main_iter,mylist5.begin(),mylist5.end());
        

    return 0;
}

void printlist(ls::list<int>::iterator it,ls::list<int>::iterator begin,ls::list<int>::iterator end){
    std::cout << " Elementos: ";
        for (it= begin; it!=end; it++)
          std::cout << ' ' << (*it)->data;
    std::cout << std::endl;
    std::cout << std::endl;       
}