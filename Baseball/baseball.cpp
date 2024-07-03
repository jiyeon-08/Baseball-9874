#include <iostream>
using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};
class Baseball {
public:
	Baseball(const string& question)
		:question(question) {
	}
	GuessResult guess(const string& guessNumber) {
		asserIllegalArgument(guessNumber);
		return { true, 3, 0 };
	}

	void asserIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != 3) {
			throw length_error("Must be trhee letters.");
		}
		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Must be number");
		}
		if (isDuplicatedNumber(guessNumber)) {
			throw invalid_argument("Must not have the same number.");
		}
	}

	bool isDuplicatedNumber(const string& guessNumber)
	{
		if (guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2]) {
			return true;
		}
		return false;
	}
private: 
	string question;
};