#include "CombinedNumberCalculator.hpp"
#include <algorithm> 

///
/// Helper functions.
///

static char getFirstDifferentDigit(const string &number, const char &digitToCompare) {
  for (const char &digit : number)
    if (digit != digitToCompare)
      return digit;
  return '\0';
}

// Example: number (421) and prefix (42).
static bool compareNumberWithPrefix(const string &number, const string &prefix) {
  const char &highestOrderDigit = prefix[0];
  string suffix = number.substr(prefix.size(), number.size());

  const char &firstDifferentDigit_FromSuffix = getFirstDifferentDigit(suffix, highestOrderDigit);
  if (firstDifferentDigit_FromSuffix != '\0')
    return firstDifferentDigit_FromSuffix < highestOrderDigit;
  
  const char &firstDifferentDigit_FromPrefix = getFirstDifferentDigit(prefix, highestOrderDigit);
  return firstDifferentDigit_FromPrefix > highestOrderDigit;
}

static bool handlePrefixNumber(const string &s1, const string &s2, const string &prefix) {
  if (s1 == prefix)
    return compareNumberWithPrefix(s2, prefix);
  else
    return !compareNumberWithPrefix(s1, prefix);
}

static unsigned getMaxLength(const string &s1, const string &s2) {
  return s1.size() > s2.size() ? s2.size() : s1.size();
}

static string getCommonPrefix(const string &s1, const string &s2) {
  string prefix = "";
  unsigned len = getMaxLength(s1, s2);

  for (int i = 0; i < len && s1[i] == s2[i]; ++i)
    prefix += s1[i];

  return prefix;
}

static bool compareNumbers(unsigned i, unsigned j) {
  if (i == j)
    return false;
  
  const string &s1 = to_string(i);
  const string &s2 = to_string(j);

  const string& prefix = getCommonPrefix(s1, s2);
  if (s1 == prefix || s2 == prefix)
    return handlePrefixNumber(s1, s2, prefix);
  
  return s1 > s2;
}

///
/// This is the entry point of the program.
/// In the sorting step, the comparator function returns i > j. This sorts in decreasing
/// order. The case when one number is a prefix of another is handled as a special case.
///

string CombinedNumberCalculator::getCombinedNumber(vector<unsigned> &numbers) {
  sort(numbers.begin(), numbers.end(), compareNumbers);

  string combinedNumber = "";
  for (auto number : numbers)
    combinedNumber += to_string(number);

  return combinedNumber;
}