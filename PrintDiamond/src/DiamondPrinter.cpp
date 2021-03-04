#include "DiamondPrinter.hpp"

static char letters[] = { 'A', 'B', 'C' };

static string spaces(unsigned numSpaces) {
	string result = "";
	for (int i = 0; i < numSpaces; ++i)
		result += " ";
	return result;
}

string DiamondPrinter::getDiamond(char letter) {
	if (letter == 'A')
		return "A";

	unsigned n = letter - 'A';
	
	string diamond = spaces(n) + letters[0] + spaces(n) + "\n";
	
	for (unsigned i = 1; i <= n; ++i)
		diamond += spaces(n-i) + letters[i] + spaces(i*2 - 1) + letters[i] + spaces(n-i) + "\n";

	for(unsigned i = n-1; i > 0; --i)
		diamond += spaces(n-i) + letters[i] + spaces(i*2 - 1) + letters[i] + spaces(n-i) + "\n";

	diamond += spaces(n) + letters[0] + spaces(n);

	return diamond;
}
