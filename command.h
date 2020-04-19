#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <string>
#include <fstream>


#ifdef __unix__
  #define listTxtFilesNumberCmd "ls -l *.txt | wc -l"
#elif __linux__
  #define listTxtFilesNumberCmd "ls -l *.txt | wc -l"
#elif __APPLE__
  #define listTxtFilesNumberCmd "ls -l *.txt | wc -l"
#else
  #error "Err: System not defined!"
#endif


std::string executeCommand(const std::string& command);
int getTXTFilesNumber();

#endif // COMMAND_H
