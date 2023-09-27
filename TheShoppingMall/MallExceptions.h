#pragma once
#include <iostream>
#include <exception>
using namespace std;

class MallExceptions
{

public:

    MallExceptions()
    {}

    virtual ~MallExceptions()
    {}

    virtual void show() const = 0;
};

class ListIsFullException : public MallExceptions
{

private: 
    const char* listName;

public:
    ListIsFullException(const char* name) : listName(name) {}
    void show() const { cout << "ERROR - the list " << listName << " is already full." << endl; }
};

class NullValException :public MallExceptions
{

private:
    const char* valName;

public:
    NullValException(const char* name) : valName(name) {}
    void show() const { cout << valName << " can't be null value." << endl; }
};

class GeneralException :public MallExceptions
{

private:
    const char* messageException;

public:
    GeneralException(const char* msg) : messageException(msg) {}
    void show() const { cout << messageException << endl; }
};



