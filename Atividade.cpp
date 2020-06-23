#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "mensagem.h"
#include "data_hora.h"
#include "usage.h"

// Implementar um header para esse programa, separando funções e dados.

int main(int argc, char *argv[]){

    if(argc == 1){
        show_usage(argv[0]);
        //std::cout << "Uso: " << argv[0] << " add <mensagem> ou list" << std::endl;
        return 1;
    }
    std::string nome;
    nome = argv[1];
    if(nome != "add" && nome != "list"){
        show_usage(argv[0]);
        //std::cout << "Uso: " << argv[0] << " add <mensagem> ou list" << std::endl;
        return 1;
    }
    /*std::string mensagem;
    std::string terminal;*/
    mensagem mensagem;
    std::ofstream arquivo_escrita;
    std::ifstream arquivo_leitura;
    arquivo_escrita.open("teste.txt", std::ios::app);
    arquivo_leitura.open("teste.txt");
    int existe = 0;
    std::string data = "# ";
    std::string hora;
    data += get_current_date();
    hora = get_current_time();
    if(argc == 2 && nome == "add"){
        if(!arquivo_leitura.is_open()){
            std::cerr << "Arquivo não existente ou sem permissão de leitura." << std::endl;
            return 1;
        }
        while(!arquivo_leitura.eof()){
            std::getline(arquivo_leitura, mensagem.mensagem);
            if(mensagem.mensagem == data){
                existe = 1;
                continue;
            }
        }
        if(existe != 1){
            arquivo_escrita << "\n" << "# " << get_current_date() << "\n" <<std::endl;
        }
        std::cout << "Informe a mensagem: " << std::endl;
        std::getline(std::cin, mensagem.mensagem);
        if(!arquivo_escrita.is_open()){
            std::cerr << "Arquivo não existente ou sem permissão de escrita." << std::endl;
            return 1;
        }
        arquivo_escrita << "- " << hora << " " << mensagem.mensagem << std::endl;
        std::cout << "Mensagem: " << mensagem.mensagem << " Adicionada" << std::endl;
    } else if(nome == "add"){
        if(!arquivo_leitura.is_open()){
            std::cerr << "Arquivo não existente ou sem permissão de leitura." << std::endl;
            return 1;
        }
        while(!arquivo_leitura.eof()){
            std::getline(arquivo_leitura, mensagem.mensagem);
            if(mensagem.mensagem == data){
                existe = 1;
                continue;
            }
        }
        if(existe != 1){
            arquivo_escrita << "\n" << "# " << get_current_date() << "\n" <<std::endl;
        }
        if(!arquivo_escrita.is_open()){
            std::cerr << "Arquivo não existente ou sem permissão de escrita." << std::endl;
            return 1;
        }
        for(size_t i = 2; i < argc; i++){
            mensagem.terminal += argv[i];
            mensagem.terminal += " ";
        }
        arquivo_escrita << "- " << hora << " " << mensagem.terminal << std::endl;
        std::cout << "Mensagem: " << mensagem.terminal << "Adicionada" << std::endl;
    } else {
        if(!arquivo_leitura.is_open()){
            std::cerr << "Arquivo não existente ou sem permissão de leitura." << std::endl;
            return 1;
        }
        int line_number = 0;
        while(!arquivo_leitura.eof()){
            std::getline(arquivo_leitura, mensagem.mensagem);
            if(mensagem.mensagem[0] == data[0]){
                continue;
            }
            if(mensagem.mensagem.size() == 0){
                continue;
            }
            ++line_number;
            std::cout << line_number << ". " << mensagem.mensagem << std::endl;
        }
    }
    arquivo_leitura.close();
    arquivo_escrita.close();
    return 0;
}