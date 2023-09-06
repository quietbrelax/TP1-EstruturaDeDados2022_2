/*
-----------------------------------------------------
Arquivo PGM.hpp referente ao TP1
Usuario
Materia Estrutura de Dados
Semestre 2022/02

Aluna: Maria Clara Oliveira Domingos Ruas
Matricula: 2021019572
-----------------------------------------------------

Projeto de simulacao de caixa de email


*/
#pragma once
#include <string>
#include "CaixaEntrada.hpp"
#include "Email.hpp"

class Usuario {
  private:
    int id;
    CaixaEntrada minhaCaixa;
    Usuario * prox;
    std::string auxUs;

public:
    Usuario();
    Usuario(int);
    void setID(int);
    int getID();
    void apagaUsuario();
    std::string recebeEmail(std::string, int);
    std::string vizuEmail();
    
    friend class ListaUsuario;

};