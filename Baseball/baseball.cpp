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
		result = { false, 0, 0 };
		for (int i = 0; i < 3; i++) {
			if (guessNumber[i] == question[i]) {
				result.strikes++;
			}
			else if (question.find(guessNumber[i]) != string::npos) {
				result.balls++;
			}
		}
		if (result.strikes == 3) {
			result.solved = true;
		}
		return result;
		return { true, 3, 0 };
	}
private:
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

	GuessResult result;
	string question;
};