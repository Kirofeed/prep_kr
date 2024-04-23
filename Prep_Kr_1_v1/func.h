#ifndef FUNC_H
#define FUNC_H

#include <vector>
#include <string>
#include <map>
#include "writer.h"

std::multimap<std::string, std::pair <std::string, int>> ReadDataFromFile(std::string filename);
std::vector<Writer> CreateWriters(std::multimap<std::string, std::pair <std::string, int>> books);
void ProcessRequest(std::vector<Writer> writers, std::string RequestFilename, std::string OutFileName);

#endif // FUNC_H