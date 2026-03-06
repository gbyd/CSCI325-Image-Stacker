/**
 * @file Stacker.cpp
 * @author AJ Hopkins
 * @ date 2026-03-03
 * @brief Implementation of the Stacker class
 *
 * Reads multiple image files, accumulates their RGB values,
 * averages them together, and writes the result to a new PPM file
 */

 #include "Stacker.h"
 #include <iostream>
 #include <fstream>
 #include <string>
 #include <vector>
 #include <sstream>


// Constructor
Stacker::Stacker() {
  magic_number = "";
  width = 0;
  height = 0;
  max_color = 0;
 }

 
// read and stack, if this is the first image it resizes and stores values directly.
void Stacker::readAndStack(std::string filename) {
  std::ifstream inFile(filename);

  if (!inFile.is_open()) {
   std::cerr << "Error: could not open file " << filename << std::endl;
   return;
  }

  //read the header values from the file
  std::string file_magic;
  int file_width, file_height, file_max_color;

  inFile >> file_magic >> file_width >> file_height >> file_max_color;

  //if this is the first image, save the header info and set up the pixels vector with the right number of pixels
  // all initialized to 0.
  if (pixels.empty()) {
   magic_number = file_magic;
   width = file_width;
   height = file_height;
   max_color = file_max_color;
   pixels.resize(width * height);

   // initialize all rgb values to 0
   for (int i = 0; i < width * height; i++) {
     pixels[i].red = 0;
     pixels[i].green = 0;
     pixels[i].blue = 0;
   }
  }

  //read every pixel in the file and add its rgb values to the running totals
  for (int i = 0; i < width * height; i++) {
    int r, g, b;
    inFile >> r >> g >> b;
    pixels[i].red += r;
    pixels[i].green += g;
    pixels[i].blue += b;
   }

   inFile.close();
  }

  //average

 void Stacker::average(int n) {
   for (int i = 0; i < width * height; i++) {
     pixels[i].red /= n;
     pixels[i].green /= n;
     pixels[i].blue /= n;
   }
  }

// writeImage
void Stacker::writeImage(std::string filename) {
  std::ofstream outFile(filename);

  if (!outFile.is_open()) {
   std::cerr << "Error: could not write to file " << filename << std::endl;
   return;
  }

  //write the PPM header
  outFile << magic_number << "\n";
  outFile << width << " " << height << "\n";
  outFile << max_color << "\n";

  //write pixel data
  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      int index = row * width + col;
      outFile << pixels[index].red << " "
              << pixels[index].green << " "
	      << pixels[index].blue << " ";
   }
   outFile << "\n";
  }

  outFile.close();
 }

   
