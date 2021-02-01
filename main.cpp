#include <iostream>
#include <string>

//ROT13 is a simple letter substitution cipher that replaces a letter with the letter 13 letters after it in the alphabet. 
//ROT13 is an example of the Caesar cipher. This function that takes and returns the string ciphered with Rot13. 
//If there are numbers or special characters included in the string, they should be returned as they are. Only letters from 
//the latin/english alphabet should be shifted, like in the original Rot13 "implementation".

using namespace std;

string rot13(string msg)
{
  for(unsigned long i = 0; i < msg.length(); i++) { //loop through each character
    if(isupper(msg[i])) { //check if uppercase character
      //replace with a 'shift' of +13 - dont forget ascii uppercase 'A' is 65 
      //%26 causes the range to loop within 26 value thus keeping it in a valid alphabetic range  
      msg[i] = char( int(msg[i] +13 -65) %26 +65 ); 
    }
    if(islower(msg[i])) { //check if lowercase character
      msg[i] = char( int(msg[i] +13 -97) %26 +97 ); //replace with a 'shift' of +13 - dont forget ascii lowercase 'a' is 97
    }
  }
  return msg;
}



int main() {
	std::cout << "\ntest: " << rot13("test"); // -> "grfg"
	std::cout << "\nTest: " << rot13("Test"); // -> "Grfg"
	std::cout << "\nAbCd: " << rot13("AbCd"); // -> "NoPq"
	std::cout << "\n";
}
