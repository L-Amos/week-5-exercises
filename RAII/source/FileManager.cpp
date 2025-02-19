#include<string>
#include<iostream>
#include<fstream>
#include "FileManager.h"

FileManager::FileManager(std::string fileName) {
    f = std::fopen(fileName.c_str(), "rw");
    if(!f) {
        std::string err_msg = "Failed to open file " + fileName;
        throw std::runtime_error(err_msg);
    }
    std::cout << "File opened." << std::endl;
}

FileManager::~FileManager() {
    if(f) {
        std::fclose(f);
    }
    std::cout << "File closed." << std::endl;
}

int FileManager::getData() {
    int n;
    std::fscanf(f, "%d", &n);
    return n;
}
