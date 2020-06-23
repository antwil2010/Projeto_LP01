#include "mensagem.h"
#include <iostream>

int main(int argc, char *argv[]) {

    Message m1;
    m1.date = "22/06/2020";
    m1.time = "08:49:03";
    m1.message = "Olá, Mundo";

    Message m2;
    m2.date = "22/06/2020";
    m2.time = "08:49:32";
    m2.message = "Hello, World";
    m1.compare_dates(m2);
}