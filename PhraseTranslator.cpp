#include "PhraseTranslator.h"

using namespace std;

//ctor
PhraseTranslator :: PhraseTranslator(string inFile)
{
    file = inFile;
    readFile();

}

//dtor
PhraseTranslator :: ~PhraseTranslator()
{
    cout << "Writing to the file" << endl;

    table.printToFile(file);

}

//readFile
void PhraseTranslator :: readFile()
{
    ifstream inFile;
    inFile.open(file.c_str());

    if(inFile.fail()){
	PhraseTranslatorFileException error;
	throw error;
    }

    string keyAndValue;

    while(true){

	getline(inFile, keyAndValue); 

	if(inFile.fail())
	    break;

	//cout << keyAndValue << endl;
	
	//position in string where we split key and value
	int breakPoint;

	for(int i = 0; i < keyAndValue.size(); i++){

	    if(keyAndValue.at(i) == ':'){
		breakPoint = i;
		break;
	    }
	}

	string key = keyAndValue.substr(0,breakPoint-1);
	
	table.insert(key, keyAndValue);
    }

    inFile.close();

}

//print
void PhraseTranslator :: print()
{
    table.print();
}

//findTranslation
bool PhraseTranslator :: findTranslation(string& word)
{
    bool retVal = false;

    if(table.find(word)){
	word = table[word];
	retVal = true;
    }

    return retVal;

}

//addTranslation
bool PhraseTranslator :: addTranslation(string& word, string& translation)
{

    bool retVal = false;

    if(table.find(word)){
	//throw ugly exception here
	cout << "Big nasty exception thrown" << endl;
    }
    else{
	table.insert(word, translation);
    }

    return retVal;
}

//removeTranslation
bool PhraseTranslator :: removeTranslation(const string& word)
{
    bool retVal = false;

    retVal = table.remove(word);

    return retVal;

}
