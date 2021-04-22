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

string getTab(int num){
  string tab = "";
  if(num == 0){
    return tab;
  }
  for(int i = 0; i < num; i++){
    tab += "\t";
  }
  return tab;
}

string indent_code(string filename){
  string reformatted = "";
  ifstream file(filename);
  int num_of_braces = 0;
  string first_char;
  int mcount = 0;
  
  //Thus reads line by line we use getline so we dont get individual characters 
  for (string line; getline(file,line);){
    mcount = mcount - countChar(removeLeadingSpaces(line),'}');
    reformatted += getTab(mcount) + removeLeadingSpaces(line) + "\n";
    mcount = mcount + countChar(removeLeadingSpaces(line),'{');

  }
  if (reformatted == ""){
      reformatted = "File not found please try again";
  }
  
  return reformatted;
}
  
