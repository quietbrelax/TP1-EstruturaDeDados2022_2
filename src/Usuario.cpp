/*
-----------------------------------------------------
Arquivo PGM.cpp referente ao TP1
Implementacao das funcoes da Estrutura Usuario
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
#include "memlog.h"

    Usuario::Usuario(){
    /*
    Descricao: Construtor padrao do Usuario
    Entrada: 
    Saida:
    */

        this -> id = 0;
        this -> prox = NULL;

    }

    Usuario::Usuario(int ID){
    /*
    Descricao:Construtor do Usuario com ID passado como parametro
    Entrada: int ID 
    Saida:
    */

        this -> id = ID;
        this -> prox = NULL;

    }

    void  Usuario::setID(int ID){
    /*
    Descricao: Define um ID do Usuario
    Entrada: int ID (ID a ser colocado/atualizado)
    Saida:
    */

        this -> id = ID;

    }

    int  Usuario::getID(){
    /*
    Descricao: Retorna o ID de um Usuario
    Entrada: 
    Saida: int (ID)
    */

        return this -> id;

    }

    void  Usuario::apagaUsuario(){
    /*
    Descricao: Libera a memoria alocada para a caixa de entrada do Usuario
    Entrada: 
    Saida:
    */

        this -> minhaCaixa.Limpa();

    }

    std::string  Usuario::recebeEmail(std::string msg, int prioridade){
        
    /*
    Descricao: Recebe informacoes de um Email e coloca ele na lista baseado em sua prioridade
    Entrada: std::string msg (mensagem do Email), int prioridade(prioridade do Email)
    Saida: std::string (mensagem de retorno da funcao)
    */
        
        Email* p;
        p = minhaCaixa.primeiro;
        int pos = 1;
        
        while(p -> prox != NULL){
            p = p -> prox;
            if(prioridade > p -> prioridade){
                //LEMEMLOG((long int)(p), sizeof(int), 0);
                minhaCaixa.inserePosicao(msg, prioridade, pos);
                auxUs = "OK: MENSAGEM PARA " + std::to_string(this -> id) + " ENTREGUE";
                return  auxUs;
            }
            pos++;
        }
        minhaCaixa.insereFinal(msg, prioridade);
        auxUs = "OK: MENSAGEM PARA " + std::to_string(this -> id) + " ENTREGUE"; 
        return  auxUs;

    }

    std::string  Usuario::vizuEmail(){

    /*
    Descricao: Confere se existem mensagens. Caso exista, consulta a primeira da caixa
    Entrada: 
    Saida: std::string(mensagem de retorno da funcao)
    */

        if(minhaCaixa.tamanho == 0){
            return "CONSULTA " + std::to_string(this -> id) + ": CAIXA DE ENTRADA VAZIA";
        }

        auxUs = "CONSULTA " + std::to_string(this -> id) + ": " + this -> minhaCaixa.removeInicio();

        return auxUs;

    }