/*
-----------------------------------------------------
Arquivo PGM.hpp referente ao TP1
Caixa de Entrada de Emails
Materia Estrutura de Dados
Semestre 2022/02

Aluna: Maria Clara Oliveira Domingos Ruas
Matricula: 2021019572
-----------------------------------------------------

Projeto de simulacao de caixa de email


*/
#pragma once
#include <string>
#include "Email.hpp"

class CaixaEntrada {
  private:
    Email* primeiro;
    Email* ultimo;
    int tamanho;

public:
    CaixaEntrada();
    ~CaixaEntrada();
    Email* Posiciona(int pos, bool antes);
    void insereInicio(std::string item, int prioridade);
    void insereFinal(std::string item, int prioridade);
    void inserePosicao(std::string item, int prioridade, int pos);
    std::string removeInicio();
    void Imprime();
    void Limpa();

    friend class Usuario;
};