#ifndef IOSTREAM
#include<iostream>
#endif
#ifndef CAESARCIPHER_HPP
#include"caesarCipher.hpp"
#endif


void returnCase(std::string& text, std::string original){
	for(size_t i = 0; i < text.size(); i++){
		if(islower(original[i])) text[i] = tolower(text[i]);
		if(isupper(original[i])) text[i] = toupper(text[i]);
	}
}

int main(int argc, char **argv){

	if(argc != 4){
		std::cout << "Invalid arguments\n";
		return 100;
	}

	//Fetching the input
	std::string input, text;
	int shift;
	char setting;
	int i;
	char c;
	std::string buffer;
	

	i = 0;
	c = argv[1][i];
	while(c != '\0'){
		input.push_back(c);
		text.push_back(tolower(c));
		
		c = argv[1][++i];
	}
	
	i = 0;
	c = argv[2][i];
	while(c != '\0'){
		if(!isdigit(c)){
			std::cout << "Second argument invalid\n";
			return 20;
		}

		buffer.push_back(c);
		
		c = argv[2][++i];
	}
	shift = std::stoi(buffer);

	if(argv[3][1] != '\0' || (argv[3][0] != 'e' && argv[3][0] != 'd')){
		std::cout << "Third argument invalid\n";
		return 30;
	}
	setting = argv[3][0];
	if(setting == 'd') shift *= -1;


	//Encrypting/decrypting the text	
	std::string result = caesarCipher(text, shift);

	//Returning the original case of the text
	returnCase(result, input);

	//Output
	std::cout << result << '\n';

	return 0;
}
