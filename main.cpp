#include <iostream>
#include <cctype>
#include <string>
#include <fstream> 
#include "unindent.h"

using std::cout;
using std::endl;

int main()
{
  //This makes a copy of the reformatted string so it does not get erased

  string new_code = indent_code("input.cpp");
  cout << "\n" << "Printing a copy of what got written to your specified file" << endl;
  cout << "-----------------------------------------------------" << endl;
  cout << endl;
  cout << new_code << endl;
  
  //This then writes the formatted string back into the file
  std::ofstream file("input.cpp");
  file << new_code;
  file.close();
  //This closes the file
  return 0;
}
