/*
-----------------------------------------------------
Arquivo PGM.cpp referente ao TP1
Implementacao das funcoes da Estrutura ListaUsuario
Materia Estrutura de Dados
Semestre 2022/02

Aluna: Maria Clara Oliveira Domingos Ruas
Matricula: 2021019572
-----------------------------------------------------

Projeto de simulacao de caixa de email


*/

#include "CaixaEntrada.hpp"
#include <string>
#include "Email.hpp"
#include "Usuario.hpp"
#include "ListaUsuario.hpp"
#include <iostream>
#include "memlog.h"

    ListaUsuario::ListaUsuario(){

    /*
    Descricao: Construtor da Lista de Usuarios. Cria a cabeca e inicializa o tamanho 0
    Entrada: 
    Saida:
    */

        this -> primeiro = new Usuario();
        this -> ultimo = this -> primeiro;
        this -> tamanho = 0;
    }

    ListaUsuario::~ListaUsuario(){

    /*
    Descricao: Destrutor da Lista de Usuarios. Libera toda a memoria alocada na lista
    Entrada: 
    Saida:
    */

        limpa();
        delete this -> primeiro;

    }

    int ListaUsuario::checaPos(int id){

    /*
    Descricao: Confere em qual posicao da lista o Usuario com o ID fornecido se encontra
    Entrada: int id (id a ser procurado)
    Saida: int (posicao na lista)
    */

        Usuario *p;
        p = primeiro -> prox;
        int pos = 1;
        while(p -> prox != NULL){
            //LEMEMLOG((long int)(p), sizeof(int), 0);
            if(p -> id == id){
                break;
            }
            pos++;
            p = p -> prox;
        }

        return pos;

    }

    Usuario* ListaUsuario::Posiciona(int pos, bool antes=false){

    /*
    Descricao:Retorna um ponteiro do algum item da lista baseado em sua posicao.
    Entrada: int pos (posicao na lista), bool antes(para saber se é o email anterior a posicao ou a propria)
    Saida: Usuario * (ponteiro para a celula desejada)
    */

        Usuario *p; int i;
        if ( (pos > tamanho) || (pos <= 0) )
        //pos invalida
            return NULL;
        // Posiciona na célula anterior a desejada
        p = primeiro;
        for(i=1; i<pos; i++)
        {
            p = p->prox;
        }
        // vai para a próxima
        // se antes for false
        if(!antes)
            p = p->prox;
        return p;
    }

    std::string ListaUsuario::insereFinal(int item){

    /*
    Descricao: Cria novo Usuario e insere no final da lista
    Entrada: int item (inteiro referente ao id)
    Saida: std::string (mensagem de retorno da funcao)
    */

        if(!(IDExistente(item))){
            Usuario *nova;
            nova = new Usuario(item);
            ultimo->prox = nova;
            ultimo = nova;
            tamanho++;
            //ESCREVEMEMLOG((long int)(nova), sizeof(int), 0);
            aux = "OK: CONTA " + std::to_string(item) + " CADASTRADA";
        }
        else{
            aux = "ERRO: CONTA " + std::to_string(item) + " JA EXISTENTE";
        }

        
        return aux;
    }


    std::string ListaUsuario::removePosicao(int id){

    /*
    Descricao: Procura um ID na lista e remove o usuario com o ID
    Entrada: int id (ID do usuario a ser removido)
    Saida: std::string (mensagem de retorno da funcao)
    */

        if(IDExistente(id)){
            Usuario *p, *q;
            p = Posiciona(checaPos(id), true);
            q = p -> prox;
            p -> prox = q -> prox;
            tamanho--;
            q -> apagaUsuario();
            //ESCREVEMEMLOG((long int)(q), sizeof(int), 0);
            delete q;
            if(p -> prox == NULL)
                ultimo = p;
            aux = "OK: CONTA " + std::to_string(id) + " REMOVIDA";
            return  aux;
        }
        
        aux = "ERRO: CONTA " + std::to_string(id) + " NAO EXISTE";
        return  aux;
        
    }

    std::string ListaUsuario::mandaEmail(int id, std::string msg, int prioridade){

    /*
    Descricao: Envia um Email para um Usuario cadastrado
    Entrada: int id (ID do Usuario), std::string msg(mensagem do Email), int prioridade(prioridade do Email)
    Saida: std::string (Mensagem de retorno)
    */

        if(IDExistente(id)){
            Usuario * p;
            p = Posiciona(checaPos(id));
            return p -> recebeEmail(msg, prioridade);
        }

        aux = "ERRO: CONTA " + std::to_string(id) + " NAO EXISTE";
        return  aux;
    }

    std::string ListaUsuario::vizuEmail(int id){

    /*
    Descricao: Seleciona o Usuario baseado na ID e consulta o primeiro Email em sua caixa de entrada
    Entrada: int id (ID do Usuario)
    Saida: std::string (mensagem do Email ou mensagem de Erro)
    */

        if(IDExistente(id)){
            Usuario * p;
            p = Posiciona(checaPos(id));
            return p -> vizuEmail();
        }

        aux = "ERRO: CONTA " + std::to_string(id) + " NAO EXISTE";
        return  aux;

    }

    bool ListaUsuario::IDExistente(int id){

    /*
    Descricao: Confere se existe um usuario na lista com o ID fornecido
    Entrada: int id(id a ser conferido)
    Saida: bool (true se existir, false se nao existir)
    */

        Usuario *p;
        p = primeiro;
        while(p != NULL){
            //LEMEMLOG((long int)(p), sizeof(int), 0);
            if(p -> id == id){
                return true;
            }
            p = p -> prox;
        }

        return false;
        
    }

    void ListaUsuario::limpa(){

    /*
    Descricao: Desaloca a memoria utilizada na lista de Usuario
    Entrada: 
    Saida:
    */

        Usuario *p;
        p = primeiro -> prox;
        while (p != NULL) {
            primeiro -> prox = p -> prox;
            p -> apagaUsuario();
            //ESCREVEMEMLOG((long int)(p), sizeof(int), 0);
            delete p;
            p = primeiro -> prox;
        }
        ultimo = primeiro;
        tamanho = 0;

    }

