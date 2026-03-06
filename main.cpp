/**
 * @file main.cpp
 * @author Gabbie Dement
 * @date 2026-03-05
 * @brief Driver file for this image stacker program
 * 
 * Interacts with the user to get image details and coordinates the stacking process using the Stacker class
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Stacker.h"

using namespace std;

int main(){
  Stacker myStacker;
  string imageName;
  int numImages;

  //user input
  cout << "Please enter the image you wish to stack: ";
  cin >> imageName;
  
  cout << "Please enter the number of images: ";
  cin >> numImages;

  cout << "\nStacking images:" << endl;

  for (int i = 1; i <= numImages; i++){
    stringstream ss;
    string padding = "";

    //manual logic for formatting so output of images is indented
    if (i < 10){
      padding = "00";
    } else if (i < 100){
      padding = "0";
    }

    //construct path to folder/folder_001.ppm
    ss << "ppms/" << imageName << "/" << imageName << "_" << padding << i << ".ppm";

    string fullPath = ss.str();
    cout << "     " << fullPath << endl;

    myStacker.readAndStack(fullPath);
  }

  myStacker.average(numImages);

  string outputFileName = imageName + ".ppm";
  myStacker.writeImage(outputFileName);

  cout << "\nStacking succeeded." << endl;
  cout << "Output written to: " << outputFileName << endl;

  return 0;
}
