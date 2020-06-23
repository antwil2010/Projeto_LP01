    #include "usage.h"
    #include <iostream>
    
    void show_usage(const std::string &prog_name) {
      std::cout << "Uso: " << prog_name << " add <mensagem> ou list" << std::endl;
    }