/*
-----------------------------------------------------
Arquivo Main.cpp referente ao TP1
Materia Estrutura de Dados
Semestre 2022/02

Aluna: Maria Clara Oliveira Domingos Ruas
Matricula: 2021019572
-----------------------------------------------------

Projeto de simulacao de caixa de email


*/

#include <iostream>
#include <string>
#include <string.h>
#include <fstream>

#include "CaixaEntrada.hpp"
#include "Email.hpp"
#include "ListaUsuario.hpp"
#include "Usuario.hpp"
#include "memlog.h"


using namespace std;
char LOGNOME[100];
int RANGE = 0;


int main(int argc, char *argv[]) {
  /*
  Descricao: programa principal da aplicacao
  Entradas: 
  Saídas: 0
  */

  string l = "-l";
  string p = "-p";
  string nomeArq;
  

  for(int j = 0; j < argc; j++){
    if(j == 0){
      nomeArq = argv[j + 1];
    }

    //Comando para geracao de log
    /*
    if(argv[j] == l){
      RANGE = 1;
    }
    if(argv[j] == p){
      strcpy(LOGNOME, argv[j + 1]);
    }
    */
  }

  //Logs de memoria
  /*
  iniciaMemLog(LOGNOME);

  if(RANGE){
    ativaMemLog();
  }
  else{
    desativaMemLog();
  }
  */
  
  //Definicao de variaveis
    ListaUsuario servidor;
    string comando, msg;
    int id, priori;
    bool pegaComando = true;


    std::ifstream MyReadFile(nomeArq);


  //loop para ler todos os comandos do arquivo
    while(!MyReadFile.eof()){
      //Pega qual é a palavra chave para o comando
      if(pegaComando){
        MyReadFile >> comando;
        pegaComando = false;
      }

      //Pega os dados seguintes baseado em qual comando foi pedido
      else{
        if(comando == "CADASTRA"){

          MyReadFile >> id;
          cout << servidor.insereFinal(id) << endl;

        }

        else if(comando == "REMOVE"){

          MyReadFile >> id;
          cout << servidor.removePosicao(id) << endl;

        }

        else if(comando == "ENTREGA"){

          MyReadFile >> id >> priori;
          msg = "";
          while (comando != "FIM"){
            MyReadFile >> comando;
            
            if(comando != "FIM"){
              msg = msg + comando + " ";
            }
            
          }
          cout << servidor.mandaEmail(id, msg, priori) << endl;

        }

        else if(comando == "CONSULTA"){
          
          MyReadFile >> id;
          cout << servidor.vizuEmail(id) << endl;
          
        }
        pegaComando = true;
      }
      
    }

    MyReadFile.close();

	//return finalizaMemLog();

  return 0;
}
