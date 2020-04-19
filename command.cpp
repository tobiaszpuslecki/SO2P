#include "command.h"

std::string executeCommand(const std::string& command)
{
    system((command + " > temporaryFile.txt").c_str());

    std::ifstream ifs("temporaryFile.txt");

    std::string ret;
    ifs >> ret;

    ifs.close();
    if (std::remove("temporaryFile.txt") != 0) {
        perror("Error deleting temporary buffor file !");
    }
    return ret;
}

int getTXTFilesNumber()
{
  return stoi(executeCommand(listTxtFilesNumberCmd));
}
