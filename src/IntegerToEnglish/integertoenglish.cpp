#include <string>
#include <math.h>
#include <iostream>

#include "integertoenglish.h"

using namespace std;

static string pow_of_3_names [3] = {
	"Million",
	"Billion",
	"Thousand"
};

static string digit_names [10] = {
	"", // Zero is an empty string since its ommited
	"One",
	"Two",
	"Three",
	"Four",
	"Five",
	"Six",
	"Seven",
	"Eight",
	"Nine"
};

static string teen_names[10] = {
	"Ten",
	"Eleven",
	"Twelve",
	"Thirteen",
	"Fourteen",
	"Fifteen",
	"Sixteen",
	"Seventeen",
	"Eighteen",
	"Nineteen"
};

static string pow_of_1_names[10] = {
	"", // Zero is not mentioned
	"Ten", // Never used, but still helpful to have as offset
	"Twenty",
	"Thirty",
	"Forty",
	"Fifty",
	"Sixty",
	"Seventy",
	"Eighty",
	"Ninety"
};

static int billion = pow(10, 9);
static int million = pow(10, 6);
static int thousand = pow(10, 3);

string IntegerToEnglish::numberToWords(int num) {

	if (num == 0) {
		return "Zero";
	}

	string final_string = "";

	int billions_part = num / billion;
	int millions_part = num % billion / million;
	int thousands_part = num % million / thousand;
	int hundreds_part = num % thousand;

    if (billions_part > 0) {
    	final_string += this->hundredsToString(billions_part) + " Billion ";
    }

    if (millions_part > 0) {
    	final_string += this->hundredsToString(millions_part) + " Million ";
    }

    if (thousands_part > 0) {
    	final_string += this->hundredsToString(thousands_part) + " Thousand ";
    }


    final_string += this->hundredsToString(hundreds_part);

    if (final_string.size() > 0) {
		return final_string.substr(0, final_string.size() - 1);
	}

	return final_string;
}

string IntegerToEnglish::hundredsToString(int num) {

	int hundreds_part = num % 1000;
	int teens_part = hundreds_part % 100;
	int ones_part = teens_part % 10;

	int hundreds_col_val = num % 1000 / 100;
	int tens_col_val = num % 100 / 10;
	int ones_col_val = num % 10;

	string final_string = "";

	if (hundreds_col_val > 0) {
		final_string += digit_names[num / 100] + " Hundred ";
	}

	if (tens_col_val == 0) {
		// do nothing
	} else if (tens_col_val == 1) {
		final_string += teen_names[ones_col_val];
	} else {
		final_string += pow_of_1_names[tens_col_val] + " ";
	}

	// If teens col value was one, then the ones value is part of "Eleven" or "Twelve"
	if (ones_col_val != 0 && (tens_col_val != 1)) {
		final_string += digit_names[ones_part];
	}

	return final_string;
}


