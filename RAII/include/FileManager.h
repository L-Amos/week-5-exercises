#pragma once
#include<string>

class FileManager
{
    public:
    FileManager(std::string fileName);
    ~FileManager();
    int getData();
    private:
    FILE * f;
};