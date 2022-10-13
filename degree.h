//Define an enumerated data type DegreeProgram for the degree programs containing the data type values SECURITY, NETWORK, and SOFTWARE.

#pragma once
#include <string>
enum class DegreeProgram { UNDETERMINED, SECURITY, NETWORK, SOFTWARE, };
static const std::string degreeProgramStrings[] = { "UNDETERMINED", "SECURITY", "NETWORK", "SOFTWARE" };