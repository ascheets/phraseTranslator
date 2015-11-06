#include <iostream>
#include "PhraseTranslator.h"

using namespace std;

void runPT(PhraseTranslator& pTrans);
int showMenu();
bool findTranslation(PhraseTranslator& pTrans);
bool addTranslation(PhraseTranslator& pTrans);
bool deleteTranslation(PhraseTranslator& pTrans);

int main()
{
    //initialize a phrase translator from a file
    PhraseTranslator pTrans("phrases");

    runPT(pTrans);

    return 0;
}

void runPT(PhraseTranslator& pTrans)
{
    //bool to keep program running
    bool isRunning = true;

    //open program menu
    while(isRunning){

	int selection = showMenu();

	if(selection == 1){
	    
	    bool isSearching = true;

	    while(isSearching){
		//enter findTranslation
		isSearching = findTranslation(pTrans);
	    }
	    
	}
	else if(selection == 2){
	    
	    bool isAdding = true;

	    while(isAdding){
		//enter addTranslation
		isAdding = addTranslation(pTrans);
	    }	    

	}
	else if(selection == 3){
	    
	    bool isDeleting = true;

	    while(isDeleting){
		//enter deleteTranslation
		isDeleting = deleteTranslation(pTrans);
	    }	    
	    
	}
	else if(selection == 4){
	    //just quit
	    isRunning = false;
	}
	else{
	    cout << "Invalid option" << endl;
	    isRunning = false;	    
	}
    }


}

int showMenu()
{
    int retVal;
    bool valid = false;

    cout << "***Welcome to the Phrase Translating Program***" << endl;

    while(!valid){

	cout << "What would you like to do?" << endl;
	cout << "1.Find a translation" << endl;
	cout << "2.Add a new translation" << endl;
	cout << "3.Delete a translation" << endl;
	cout << "4.Quit" << endl;

	cin >> retVal;

	//selection data validation
	if(cin.good()){
	    
	    if(retVal < 1 || retVal > 4){
		cout << "Make this easier for all of us, enter a valid selection" << endl << endl;
	    }
	    else{
		valid = true;
	    }
	}
	else{
            cin.clear(); //clear bad input flag
	    cin.ignore();
	    cout << "Invalid input; please re-enter.\n" << endl << endl;
	}
    }

    return retVal;
    
}

bool findTranslation(PhraseTranslator& pTrans)
{
    bool retVal = true;

    //get input

    string word;

    cout << endl;

    cout << "Please enter the word you would like translated" << endl;

    cin >> word;

    if(cin.good()){
	//search the pT for word
	if(pTrans.findTranslation(word)){
	    cout << "Here is your translation" << endl;
	    cout << word << endl;
	}
	else{
	    cout << "So sorry, the word you are searching for is not in the database" << endl;
	}

	//keep searching?
	cout << endl;
	cout << "Would you like to search again? (y/n)" << endl;
	
	string response;
	bool valid = false;

	while(!valid){
	    
	    cin >> response;

	    if(cin.good()){
		if(response == "n" || response == "no"){
		    retVal = false;
		    valid = true;
		}
		else if(response == "y" || response == "yes"){
		    valid = true;
		}
		else{
		    cout << "Didn't quite catch that, try again." << endl;
		}
	    }
	    else{
		cin.clear(); //clear bad input flag
		cin.ignore();
		cout << "Invalid input; please re-enter.\n" << endl << endl;
	    }
	}
    }
    else{
	cin.clear(); //clear bad input flag
	cin.ignore();
	cout << "Invalid input; please re-enter.\n" << endl << endl;
    }

    return retVal;

}

bool addTranslation(PhraseTranslator& pTrans)
{
    bool retVal = true;

    //get input
    
    string word;

    cout << endl;

    cout << "Please enter the word you would like to add" << endl;

    cin >> word;

    if(cin.good()){
	//search the pT for word
	if(pTrans.findTranslation(word)){
	    cout << "This translation is already in database" << endl;
	    cout << word << endl;
	}
	else{
	    //get the translation

	    string translation;
	    string wordAndTranslation;
	    bool valid = false;

	    while(!valid){

		cout << endl;
		cout << "Please enter the translation of the word or zz to exit" << endl;

		cin >> translation;

		if(cin.good()){

		    if(translation != "zz"){

			wordAndTranslation = word + " ::: " + translation;

			//actually add the word to the database
			pTrans.addTranslation(word, wordAndTranslation);

			valid = true;
		    }
		    else{
			valid = true;
		    }
		}
		else{
		    cin.clear();
		    cin.ignore();
		    cout << "Invalid input; please re-enter.\n" << endl << endl;
		}
	    }
	    
	}

	//keep adding words?
	cout << endl;
	cout << "Would you like to add another word? (y/n)" << endl;

	string response;
	bool valid = false;

	while(!valid){

	    cin >> response;
	    
	    if(cin.good()){
		if(response == "n" || response == "no"){
		    retVal = false;
		    valid = true;
		}
		else if(response == "y" || response == "yes"){
		    valid = true;
		}
		else{
		    cout << "Didn't quite catch that, try again." << endl;
		}
	    }
	    else{
		cin.clear(); //clear bad input flag
		cin.ignore();
		cout << "Invalid input; please re-enter.\n" << endl << endl;
	    }
	}
    }
    else{
	cin.clear(); //clear bad input flag
	cin.ignore();
	cout << "Invalid input; please re-enter.\n" << endl << endl;
    }

    return retVal;

}

bool deleteTranslation(PhraseTranslator& pTrans)
{
    bool retVal = true;

    //get input

    string word;

    cout << endl;

    cout << "Please enter the word you would like to delete" << endl;

    cin >> word;

    if(cin.good()){
	//search the pT for word
	string forSearch = word;
	if(!(pTrans.findTranslation(forSearch))){
	    cout << "The word you are trying to delete is not in database" << endl;
	}
	else{
	    //actually remove word and translation from pT
	    pTrans.removeTranslation(word);
	}
	
	//keep deleting words?
	cout << endl;
	cout << "Would you like to delete another word? (y/n)" << endl;

	string response;
	bool valid = false;

	while(!valid){

	    cin >> response;
	    
	    if(cin.good()){
		if(response == "n" || response == "no"){
		    retVal = false;
		    valid = true;
		}
		else if(response == "y" || response == "yes"){
		    valid = true;
		}
		else{
		    cout << "Didn't quite catch that, try again." << endl;
		}
	    }
	    else{
		cin.clear(); //clear bad input flag
		cin.ignore();
		cout << "Invalid input; please re-enter.\n" << endl << endl;
	    }
	}
    
    }
    else{
	cin.clear(); //clear bad input flag
	cin.ignore();
	cout << "Invalid input; please re-enter.\n" << endl << endl;
    }

    return retVal;
}
