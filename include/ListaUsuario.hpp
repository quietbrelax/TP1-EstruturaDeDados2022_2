/*
-----------------------------------------------------
Arquivo PGM.hpp referente ao TP1
Lista de Usuarios
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
#include "CaixaEntrada.hpp"
#include "Usuario.hpp"

class ListaUsuario {
  private:
    Usuario* primeiro;
    Usuario* ultimo;
    int tamanho;
    std::string aux;
public:
    ListaUsuario();
    ~ListaUsuario();
    Usuario* Posiciona(int pos, bool antes);
    int checaPos(int id);
    std::string insereFinal(int item);
    std::string removeInicio();
    std::string removeFinal();
    std::string removePosicao(int id);
    std::string vizuEmail(int id);
    std::string mandaEmail(int id, std::string msg, int prioridade);
    bool IDExistente(int);
    void limpa();
};