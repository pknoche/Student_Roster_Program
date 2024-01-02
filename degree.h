#include <string>

#ifndef degree_h
#define degree_h

enum class DegreeProgram {SECURITY, NETWORK, SOFTWARE, UNSPECIFIED}; // included UNSPECIFIED for
                                                                     // default contructor
static const string degreeProgramStrings[] = {"SECURITY", "NETWORK", "SOFTWARE", "UNSPECIFIED"};      // parallel array with string to print

#endif /* degree_h */
