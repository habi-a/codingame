#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

int main()
{
  string block;
  bool newBlock;
  unsigned int j;
  string MESSAGE;
  string MESSAGE_BINNARY_WITH_ZERO;
  string MESSAGE_BINNARY;
  string RESPONSE;

  getline(cin, MESSAGE);

  // To Binnary
  for (std::size_t i = 0; i < MESSAGE.size(); ++i) {
      MESSAGE_BINNARY_WITH_ZERO = bitset<32>(MESSAGE.c_str()[i]).to_string();

      // Remove 0 head
      j = 0;
      while (j < 32 - 7 && MESSAGE_BINNARY_WITH_ZERO[j] != '1')
	j++;
      while (j < MESSAGE_BINNARY_WITH_ZERO.size()) {
	  MESSAGE_BINNARY += MESSAGE_BINNARY_WITH_ZERO[j];
	  j++;
      }
  }

  // Encoding
  newBlock = true;
  for (std::size_t k = 0; k < MESSAGE_BINNARY.size(); ++k) {
      if (newBlock) {
	  block = MESSAGE_BINNARY[k];
	  newBlock = false;
      }
      else {
	  if (MESSAGE_BINNARY[k] == block[0])
	    block += MESSAGE_BINNARY[k];
	  else {
	      // fill first block
	      if (block[0] == '1')
		RESPONSE += "0 ";
	      else
		RESPONSE += "00 ";

	      // fill second block
	      for (std::size_t l = 0; l < block.size(); ++l)
		RESPONSE += "0";

	      RESPONSE += " ";
	      newBlock = true;
	      k--;
	  }
      }
  }

  // fill first block
  if (block[0] == '1')
    RESPONSE += "0 ";
  else
    RESPONSE += "00 ";

  // fill second block
  for (std::size_t l = 0; l < block.size(); ++l)
    RESPONSE += "0";

  cout << RESPONSE << endl;
}
