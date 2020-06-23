#ifndef AULA05_MENSAGEM_H
#define AULA05_MENSAGEM_H

#include <string>

struct hora {
    int hora;
    int minuto;
    int segundo;
};

struct mensagem {
    std::string mensagem;
    std::string terminal;
    std::string date;
    //time time;
    std::string content;

    //bool compare_dates(const mensagemm &other_mensagem);
};

#endif