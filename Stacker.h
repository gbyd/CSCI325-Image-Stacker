/**
 * @file Stacker.h
 * @author Gabbie Dement
 * @date 2026-03-02
 * @brief Header file for the Stacker class. 
 * 
 * Handles image stacking by averaging RGB values from multiple PPM files.
 */

#ifndef STACKER_H
#define STACKER_H

#include <string>
#include <vector>

/**
 * Processes and stacks PPM (P3) images to remove noise.
 *
 * @class Stacker{ Stacker.h "image_stacker/Stacker.h"
 * @brief Removes noise from images
 *
 */
class Stacker {
 private:

  //A struct that contains 3 ints that represent a single pixel's color data.
  struct pixel {
    int red;
    int green;
    int blue;
  };

  //private member variables
  std::string magic_number; //the p3 value
  int width; //the image width
  int height; //the image height
  int max_color; //the max color depth of the image
  std::vector<pixel> pixels; //vector of pixel structs storing color info

 public:

/**
 * stacker constructor - it initializes image metadeta to default values
 *
 * @pre n/a 
 * @post private members are initialized to empty/zero
 * 
 */
  Stacker();


/**
 * opens a PPM file, reads the header, and adds pixel values to the running total in the 'pixels' vector. 
 *
 * @param std::string filename the relative path to the .ppm file
 * @pre filename must be a valid path to a P3 PPM file
 * @return void updates internal state of the pixels vector
 * @post internal pixel vector is resized and updated
 * 
 */
  void readAndStack(std::string filename);


/**
 * calculates the mean color values for the stacked image
 *
 * @param int n the total number of images that were read and stacked
 * @pre n must be greater than 0. readAndStack must have been called n times
 * @return void 
 * @post every rgb value in the pixels vector is divided by n to remove noise
 * 
 */
  void average(int n);


/**
 * saves the final averaged pixel data to a new PPM file
 *
 * @param std::string filename the name of the output file to create (ex: "orion.ppm")
 * @pre average has been called to finalize the pixel calculations
 * @return void 
 * @post a new P3 PPM file is written to the disk
 * 
 */
  void writeImage(std::string filename);
};

#endif 
