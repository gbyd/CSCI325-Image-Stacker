Names: Gabrielle Dement and AJ Hopkins

Date Made: 03/02/2026

Description: This program averages multiple PPM images to create a single clear image.

Division of Labor:

--- Gabrielle Dement: ---
- Made Stacker.h
- Wrote main.cpp for user input and filename generation
- Wrote Makefile

--- AJ Hopkins: ---
- Wrote Stacker.cpp (Stacker class implementation)
- Developed logic for PPM file parsing and pixel accumulation
- Wrote the averaging and file output logic

How to Run:
1. Type 'make' to compile.
2. Run './stacker'
3. Enter the folder name (ex: orion) and the number of images to stack (ex: 10)
4. Run 'make clean' to remove objects and the executable.

Design Decisions:

--- Stacker.h ---
- Standard guards are implemented to prevent duplicate definitions.
- Made sure to use the std::string and std::vector since using namespace std is poor practice in header files.
- Made sure to include the private member variables that were stated in the rubric.

--- Stacker.cpp ---
- Used a vector to store a running sum of RGB values. This allows the program to process an infinite number of images without storing every single image in memory at once.
- Followed the "P3" ASCII format for the writeImage method so the program can be compatiable with image viewers.
- Included checks to ensure that files open correctly before attempting to read or write pixel data.

--- main.cpp ---
- To replicate the formatting provided in the example output of the assignment, I used padded the filenames with zeros to match the project's directory structure.
- Used stringstream to link together folder names and filenames into valid system paths.

Challenges:
- Since the <iomanip> library was not allowed, I had to manually add padding in order to format it like the example that was provided. I'm not sure if that was required, but I did so just in case.
- The first time I ran the program to test it, the Makefile was not working. It was saying that there were unncessary spaces so I checked my tabbing only to realize that it was because I was using the regular file documenting headers. I altered the commenting to fit the ones needed for a Makefile and it ran as it should afterwards.
- The next error I encountered was the program telling me that it couldn't find the orion files. I realized that I had to scp the sample images over to the server and ran it again. The error was fixed after doing so.