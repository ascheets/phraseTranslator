#pragma once
#include "HashTable/HashTable.h"
#include <iostream>
#include "PhraseTranslatorExceptions.h"
#include <string>
#include <fstream>

using namespace std;

class PhraseTranslator
{
 public:
    PhraseTranslator(string inFile);
    ~PhraseTranslator();

    void print();

    bool findTranslation(string& word);
    bool addTranslation(string& word, string& translation);
    bool removeTranslation(const string& word);

 private:
    HashTable <string> table;
    string file;

    void readFile();
};
