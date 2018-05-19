# List
Implementação do std::list para a disciplina de Estrutura Básica de Dados I (EDB I)

**Desenvolvido por:**

 - Alison Hedigliranes da Silva
 - Felipe Morais da Silva

# Objetivos
 
- [x] Special members;

- [x] Iterator methods;

- [x] Get iterators methods;

- [x] Common operations methods;

- [x] Operators overloading methods; and,

- [x] Iterator classes.

## Descrição

O projeto tem por objetivo o desenvolvimento da lista duplamente encadeada da biblioteca "list" do C++. Básicamento o projeto se divide em duas classes principais : Iterador e List,de modo que o iterador pode ser constante, onde o iterador é responsável por acessar e percorrer os elementos da lista. Já o List é a classe que possui todos os métodos de gerenciamento dos elementos como inserts e erases,push_back e etc.  

## Execução

Para gerar o executável rode dentro da pasta do programa:

```
make
```
Assim será gerado um executável nomeado "list".

Para executar o programa use:

```
./list
```

Para apagar o executável:

```
make clean
```

## Tratamento de Erros

Atualmente o programa trata os seguintes erros:

- Impede o uso de iteradores além do tamanho lista;

## Arquivos do projeto

A seguir descreveremos de forma rápida alguns arquivos que estão no projeto. 

### iterador.inl

Responsável por acessar e percorrer os elementos contidos na lista.


### list.inl

Responsável por gerenciar todos as açoes realizadas na lista.
