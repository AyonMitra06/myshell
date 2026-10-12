#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cstddef>

using namespace std;

vector<string> tokens;

bool tokenize(const string& sentence) {
    int i = 0;

    // Clear previous tokens before processing new input
    tokens.clear();

    while (i < sentence.length()) {

        // Skip whitespace
        if (isspace(static_cast<unsigned char>(sentence[i]))) {
            i++;
            continue;
        }

        // Extract a token
        string token;

        while (i < sentence.length() &&
               !isspace(static_cast<unsigned char>(sentence[i]))) {
            token += sentence[i];
            i++;
        }

        tokens.push_back(token);
    }

    // Return false if no tokens were found
    return !tokens.empty();
}


//build a built in command checker
bool executeBuiltIn(const vector<string> & tokens){
	if (tokens.empty()){
		return false;
	}
	
	// checks if the command is echo 
	if(tokens[0] == "echo"){
		return true;
	}
	else{
		return false;
	}
}

int main() {
	bool running = true;
    while (running) {
        string sentence;

        // Stop if input ends or fails
        if (!getline(cin, sentence)) {
            break;
        }

        bool value = tokenize(sentence);

        // Skip empty or whitespace-only input
        if (!value) {
            continue;
        }

        // Exit if the first token is "exit"
        if (tokens[0] == "exit") {
            cout << "Exiting the program!" << endl;
            break;
        }
        
        //checks if the tokens contain a built in function called echo then print from the index 1 to end in the terminal
        if (executeBuiltIn(tokens)){
        	for(size_t i = 1; i<tokens.size(); i++){
        		cout<< tokens[i]<<" ";
			}
			cout<<endl;
		}
    }

    return 0;
}
