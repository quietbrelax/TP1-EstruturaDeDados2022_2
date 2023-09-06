/*
-----------------------------------------------------
Arquivo PGM.cpp referente ao TP1
Implementacao das funcoes da Estrutura Email
Materia Estrutura de Dados
Semestre 2022/02

Aluna: Maria Clara Oliveira Domingos Ruas
Matricula: 2021019572
-----------------------------------------------------

Projeto de simulacao de caixa de email


*/

#include <string>
#include "Email.hpp"

    Email::Email(){

    /*
    Descricao: Construtor padrao do Email
    Entrada: 
    Saida:
    */

        this -> prox = NULL;
        this -> prioridade = 0;

    }

    Email::Email(std::string msg){

    /*
    Descricao: Construtor do Email com mensagem passada como parametro
    Entrada: std::string msg (mensagem)
    Saida:
    */

        this -> prox = NULL;
        this -> prioridade = 0;
        this -> msg = msg;

    }

    void Email::setPrioridade(int prior){

    /*
    Descricao: Define uma prioridade do Email
    Entrada: int prior (prioridade a ser colocada/atualizada)
    Saida:
    */

        this -> prioridade = prior;

    }

    void Email::setMsg(std::string msg){

    /*
    Descricao: Define uma mensagem do Email
    Entrada: std::string msg (mensagem a ser colocada/atualizada)
    Saida:
    */

        this -> msg = msg;

    }

    int Email::getPrioridade(){

    /*
    Descricao: Retorna a prioridade do Email
    Entrada: 
    Saida: int (prioridade do Email)
    */

        return this -> prioridade;

    }

    std::string Email::getMsg(){

    /*
    Descricao: Retorna a mensagem do Email
    Entrada: 
    Saida: std::string (mensagem do Email)
    */

        return this -> msg;

    }
