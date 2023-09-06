/*
-----------------------------------------------------
Arquivo PGM.hpp referente ao TP1
Emails
Materia Estrutura de Dados
Semestre 2022/02

Aluna: Maria Clara Oliveira Domingos Ruas
Matricula: 2021019572
-----------------------------------------------------

Projeto de simulacao de caixa de email


*/
#pragma once
#include <string>

class Email {
  private:
    int prioridade;
    std::string msg;
    Email * prox;

public:
    Email();
    Email(std::string);
    void setPrioridade(int);
    void setMsg(std::string);
    int getPrioridade();
    std::string getMsg();
    
    friend class CaixaEntrada;
    friend class Usuario;

};