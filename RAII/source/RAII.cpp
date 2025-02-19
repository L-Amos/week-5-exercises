#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include "FileManager.h"

int factorial(int n)
{
        if (n<0) {
            throw std::invalid_argument("Cannot perform factorial of negative numbers!");
        }
        return n == 0 ? 1 : n * factorial(n-1);
}

void printProcessedFile(std::string fileName)
{
    FileManager file_mgr = FileManager(fileName);
    int n = file_mgr.getData();
    std::cout<<"Ok"<<std::endl;
    while (n != EOF)
    {
        std::cout << n << "! = " << factorial(n) << std::endl;
        n = file_mgr.getData();
    }
}

int main()
{
    try
    {
        printProcessedFile("testFile.txt");
    }
    catch(std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
        std::cout << "We no longer have access to the file handle." << std::endl;
    }

    return 0;
}