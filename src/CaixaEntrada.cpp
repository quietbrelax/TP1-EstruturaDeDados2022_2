/*
-----------------------------------------------------
Arquivo PGM.cpp referente ao TP1
Implementacao das funcoes da Estrutura Caixa de Entrada
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
#include "memlog.h"

    CaixaEntrada::CaixaEntrada(){

    /*
    Descricao: Construtor da caixa de entrada. Cria a cabeca e inicializa o tamanho 0
    Entrada: 
    Saida:
    */

        this -> primeiro = new Email();
        this -> ultimo = this -> primeiro;
        this -> tamanho = 0;

    }

    CaixaEntrada::~CaixaEntrada(){

    /*
    Descricao: Destrutor da caixa de entrada. Libera toda a memoria alocada na lista
    Entrada: 
    Saida:
    */

        Limpa();
        delete this -> primeiro;

    }

    Email* CaixaEntrada::Posiciona(int pos, bool antes=false){

    /*
    Descricao: Retorna um ponteiro do algum item da lista baseado em sua posicao.
    Entrada: int pos (posicao na lista), bool antes(para saber se é o email anterior a posicao ou a propria)
    Saida: Email * (ponteiro para a celula desejada)
    */

        Email *p; int i;
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

    void CaixaEntrada::insereInicio(std::string item, int prioridade){

    /*
    Descricao: Cria novo Email e insere no comeco da lista
    Entrada: std::string item (mensagem do Email), int prioridade (prioridade do Email)
    Saida:
    */

        Email *nova;
        nova = new Email(item);
        nova -> msg = item;
        nova -> prioridade = prioridade;
        nova -> prox = primeiro -> prox;
        primeiro -> prox = nova;
        tamanho++;
        if(nova -> prox == NULL)
            ultimo = nova;

        //ESCREVEMEMLOG((long int)(nova), sizeof(int), 0);
    }

    void CaixaEntrada::insereFinal(std::string item, int prioridade){

    /*
    Descricao: Cria novo Email e insere no final da lista
    Entrada: std::string item (mensagem do Email), int prioridade (prioridade do Email)
    Saida:
    */

        Email *nova;
        nova = new Email(item);
        nova -> prioridade = prioridade;
        ultimo -> prox = nova;
        ultimo = nova;
        tamanho++;
        //ESCREVEMEMLOG((long int)(nova), sizeof(int), 0);

    }

    void CaixaEntrada::inserePosicao(std::string item, int prioridade, int pos){

    /*
    Descricao: Cria novo Email e insere na posicao desejada
    Entrada: std::string item (mensagem do Email), int prioridade (prioridade do Email), 
                int pos (posicao a ser adicionado)
    Saida:
    */

        Email *p, *nova;
        p = Posiciona(pos, true); // posiciona na célula anterior
        nova = new Email(item);
        nova -> prioridade = prioridade;
        nova -> prox = p -> prox;
        p -> prox = nova;
        tamanho++;
        if(nova -> prox == NULL)
            ultimo = nova;
        //ESCREVEMEMLOG((long int)(nova), sizeof(int), 0);

    }

    std::string CaixaEntrada::removeInicio(){

    /*
    Descricao: Remove o primeiro Email da lista
    Entrada: 
    Saida: std::string (mensagem do Email)
    */

        std::string aux;
        Email *p;
        if (tamanho == 0)
            return "CAIXA DE ENTRADA VAZIA";
        p = primeiro -> prox;
        primeiro -> prox = p -> prox;
        tamanho--;
        if(primeiro->prox == NULL)
            ultimo = primeiro;
        aux = p -> msg;
        //ESCREVEMEMLOG((long int)(p), sizeof(int), 0);
        delete p;
        return aux;

    }

    void CaixaEntrada::Limpa(){

    /*
    Descricao: Desaloca a memoria utilizada na lista de Email
    Entrada: 
    Saida:
    */

        Email *p;
        p = primeiro -> prox;
        while (p != NULL) {
            primeiro -> prox = p -> prox;
            //ESCREVEMEMLOG((long int)(p), sizeof(int), 0);
            delete p;
            p = primeiro -> prox;
        }
        ultimo = primeiro;
        tamanho = 0;

    }