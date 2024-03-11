#pragma once

class FibLFSR
{
public:
  // Constructor to create LFSR with the given initial seed
  FibLFSR(std::string seed);

  // Simulate one step and return the new bit as 0 or 1
  int step();

  // Simulate k steps and return a k-bit integer
  int generate(int k);

  // Mutator that change a private string.
  void setString(std::string inputString);

  // Accessor that return a private bool.
  bool getIsAlphanumeric() const;
  
  // Accessor that return a private string.
  std::string getString() const;
  
private:
  // Any fields that you need
  bool isAlphanumeric;

  std::string stringInput;

  // Helper function that xor two character by converting the char inputs into decimal ascii and xor its int value.
  char xorAlphanumeric(char lhs, char rhs)
  {
    int lhsConversion = (int)lhs;
    int rhsConversion = (int)rhs;

    int xorResult = lhsConversion ^ rhsConversion;

    // After xor, return the decimal ascii value as char which converted back into char.
    return (char)xorResult;
  }
};

std::ostream& operator<<(std::ostream&, const FibLFSR& lfsr);
