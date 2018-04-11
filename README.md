# Index Implementation

## BUILD:
The build process for the main application is relatively simple. Just navigate to the /suffixtree/suffixtree/ and run make. The Makefile will generate a ../bin directory, and populate it with the executable.

## Running:
To run the application access the ../bin directory and run ./suffixtree. The application will prompt your for a string of text to process. This can be manually entered or pasted in from another source.

## Menu
Once the text has been provided for processing, a menu will appear. There will be several options available, all of which are quite self explanitory.

1. View Suffix Array
  *Produces a suffix array for the given processed text.
2. View LCP Array
  *Produces an LCP array for the given processed text.
3. View Suffix Tree
  *Produces a suffix tree for the given processed text.
4. Get Longest Substring
  *Finds the longest common substring in the given processed text.
5. Substring Query
  *Locates a substring within the given text, you will be prompted for input.
6. Get All Substrings
  *Produces a list of all occurences of a substring in the processed text, you will be prompted for input.
7. Exit
  *Exits the program.
