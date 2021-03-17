#include <iostream>
#include <cctype>
#include <string>
#include <fstream> 
#include "unindent.h"

using std::endl;
using std::cin;
using std::string;
using std::getline;
using std::cout;
using std::ifstream;

string removeLeadingSpaces(string line){
    string new_line = "";
    bool start = false;
    int dummy = 0;
    //This iterates through the loop
    for (int i = 0; i < line.length(); i++)
    {
        if (isspace(line[i]))
        {
            dummy++;
        }
        else{
        //If it is not a space then this makes start true which adds non leading to a string without exiting the loop
            start = true;
        }
        if (start)
        {
            new_line += line[i];
        }          
    }
    return new_line;   
}

string findFirstchar(string line){
    //The purpose of this function is to find a non space character which would be used to find a curly space so the 
    //indentation can be fixed

    string first_char;
    int dummy = 0;
    for (int i = 0; i < line.length(); i++)
    {
        if (isspace(line[i]))
        {
            dummy++;
        }
        else{
            //Returns the non-space first character
            first_char = line[i];
            return first_char;
        }
    
    }
    return first_char;
}

int countChar(string line, char c){
    //This counts the number of specified character which would be used to find the curly braces
    int count = 0;
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == c){
            count++;
        }
    }
    return count;
    
}

string indent_code(string filename){
  string reformatted = "";
  ifstream file(filename);
  int num_of_braces = 0;
  string first_char;
  
  //Thus reads line by line we use getline so we dont get individual characters 
  for (string line; getline(file,line);){
      first_char = findFirstchar(line);
      //If the first non space character is a cloing brace we tab one less than usual
      if (first_char == "}"){
          for (int tab=0; tab < num_of_braces-1; tab++){
             reformatted += "\t";
             }
        }
      else{
          //This tabs depending on the code blocks which are defined by curly braces
          for (int tab=0; tab < num_of_braces; tab++){
              reformatted += "\t"; 
              } 
      }
      //Adds new line to the code
      reformatted += removeLeadingSpaces(line) + "\n";
      num_of_braces += countChar(line, '{');
      num_of_braces -= countChar(line, '}');
    }

    //file.close() wasnt working so this was my substitute
  if (reformatted == ""){
      reformatted = "File not found please try again";
  }

  return reformatted;
}
  