#include <iostream>
#include <exception>

using namespace std;

class PhraseTranslatorFileException: public exception
{

  virtual const char* what() const throw(){
    return "PhraseTranslatorFileException thrown";
  }

};
