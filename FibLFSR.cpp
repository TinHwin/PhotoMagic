#include <ostream>
#include <iostream>
#include <string>

#include "FibLFSR.hpp"

FibLFSR::FibLFSR(std::string seed)
{
  isAlphanumeric = false;

  // Check seed to determine if it is alphanumeric.
  for (unsigned int i = 0; i < seed.size(); i++)
  {
    if ((seed.at(i) != '0') && (seed.at(i) != '1'))
    {
      isAlphanumeric = true;
    }
  }
  
  stringInput = seed;
}

int FibLFSR::step()
{
  // Retrieve current private string data member from class.
  std::string inputString = this->getString();
  // Store new private string soon to be data member for class.
  std::string outputString;

  // If statement that determine which instructions to execute based on if it is alphanumeric or not.
  if (isAlphanumeric == true)
  {
    // Push the chars into a new string excluding the first char. But now it is based on input size rather than 16 bits.
    for (unsigned int i = 0; i < (inputString.size() - 1); i++)
    {
      outputString.push_back(inputString.at(i + 1));
    }

    char xorResult;

    // Determine if the size of input is enough for tap .at(2).
    if ((inputString.size() - 1) < 2)
    {
      // If it doesn't then tap .at(0) and .at(inputString.size() - 1) as that is the last position of tap.
      xorResult = xorAlphanumeric(inputString.at(0), inputString.at(inputString.size() - 1));
    }
    else
    {
      // If it does, then tap .at(0) and .at(2).
      xorResult = xorAlphanumeric(inputString.at(0), inputString.at(2));
    }

    // Determine if the size of input is enough for tap .at(3).
    if ((inputString.size() - 1) < 3)
    {
      // If it doesn't then tap xorResult from previous XOR and .at(inputString.size() - 1) as that is the last position of tap.
      xorResult = xorAlphanumeric(xorResult, inputString.at(inputString.size() - 1));
    }
    else
    {
      // If it does, then tap xorResult from previous XOR and .at(3).
      xorResult = xorAlphanumeric(xorResult, inputString.at(3));
    }

    // Determine if the size of input is enough for tap .at(5).
    if ((inputString.size() - 1) < 5)
    {
      // If it doesn't then tap xorResult from previous XOR and .at(inputString.size() - 1) as that is the last position of tap.
      xorResult = xorAlphanumeric(xorResult, inputString.at(inputString.size() - 1));
    }
    else
    {
        // If it does, then tap xorResult from previous XOR and .at(5).
      xorResult = xorAlphanumeric(xorResult, inputString.at(5));
    }

    // Push the new state back into the string
    outputString.push_back(xorResult);

    // Set this new string as the new seed
    this->setString(outputString);

    return xorResult;
  }
  else
  {
    // For loop that copy character by character from current string to new string.
    // But skips the first character as everything character will get shifted left by one.
    for(int i = 0; i < 15; i++)
    {
      outputString.push_back(inputString.at(i + 1)); 
    };

    // Store results from two character operating XOR.
    char xorResult;

    // XOR character at position 15 and position 13.
    // String actually stored the last binary bit as the first character in string.
    // Which is why .at() is at 0 for position 15 and .at() at 2 for position 13.
    if(inputString.at(0) == inputString.at(2))
    {
      xorResult = '0';
    }
    else
    {
      xorResult = '1';
    }

    // XOR character at position 12 and result of XOR from previous XOR operation.
    if(xorResult == inputString.at(3))
    {
      xorResult = '0';
    }
    else
    {
      xorResult = '1';
    }

    // XOR character at position 10 and result of XOR from previous XOR operation.
    if (xorResult == inputString.at(5))
    {
      xorResult = '0';
    }
    else
    {
      xorResult = '1';
    }

    // Check XOR result from all previous XOR operation and stores it as the first bit of a new string.
    // Or in a string, it will be stored as the last character of a string.
    if (xorResult == '0')
    {
      outputString.push_back('0');

      this->setString(outputString);

      return 0;
    }
    else
    {
      outputString.push_back('1');

      this->setString(outputString);

      return 1;
    }
  }
}

int FibLFSR::generate(int k)
{
  // Run step() k times.
  for(int i = 0; i < k; i++)
  {
    this->step();
  }

  int j = 0;
  int generateResult = 0;

  std::string stringInput = this->getString();
  
  if (isAlphanumeric == true)
  {
    for (unsigned int i = (stringInput.size() - 1); i > ((stringInput.size() - 1) - k); i--)
    {
      int jResult = (int)stringInput.at(i) << j;

      generateResult += jResult;

      j++;
    }
  }
  else
  {
    // Since binary bit and character in a string is opposite in position.
    // For loop is going at the end of the string to check character until it equals '1',
    // then I shifted the position based on j, which stored the position of binary bit.
    // So when it is equals '1', the jResult will stored the decimal value at that bit position.
    // Then it is added to generateResult, which is the total decimal value from all binary bit that
    // equals '1' based on the k bit to check.
    for(int i = 15; i > (15 - k); i--)
    {
      if(stringInput.at(i) == '1')
      {
        int jResult = 1 << j; 
    
        generateResult += jResult;
      }

      j++;
    }
  }

  return generateResult;
}

void FibLFSR::setString(std::string inputString)
{
  // Set private string data member with input string.
  stringInput = inputString;
}

bool FibLFSR::getIsAlphanumeric() const
{
  // Return private bool data member.
  return isAlphanumeric;
}

std::string FibLFSR::getString() const
{
   // Return private string data member.
  return stringInput;
}

std::ostream& operator<<(std::ostream& stringOutput, const FibLFSR& lfsr)
{
  // Send private string data member to ostream for output.
  stringOutput << lfsr.FibLFSR::getString();

  return stringOutput;
}
  
