#ifndef AULA05_MENSAGEM_H
#define AULA05_MENSAGEM_H

#include <string>

struct Time {
  int hora;
  int minuto;
  int segundo;
};

struct Message {
  std::string date;
  Time time;
  std::string content;

  bool compare_dates(const Message &other_message);
};

#endif