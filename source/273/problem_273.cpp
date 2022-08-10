#include <problem_273.h>

#include <cassert>
#include <unordered_map>

std::unordered_map<int, std::string> ones_map {
    {0, ""},
    { 1, "One" },
    { 2, "Two" },
    { 3, "Three"},
    { 4, "Four" },
    { 5, "Five" },
    { 6, "Six" },
    { 7, "Seven" },
    { 8, "Eight" },
    { 9, "Nine" }
};

std::unordered_map<int, std::string> tens_map {
    {0, ""},
    { 1, "Ten" },
    { 2, "Twenty" },
    { 3, "Thirty"},
    { 4, "Forty" },
    { 5, "Fifty" },
    { 6, "Sixty" },
    { 7, "Seventy" },
    { 8, "Eighty" },
    { 9, "Ninety" }
};

std::unordered_map<int, std::string> specials_map {
    { 0, "Zero" },
    { 11, "Eleven" },
    { 12, "Twelve" },
    { 13, "Thirteen" },
    { 14, "Fourteen" },
    { 15, "Fifteen" },
    { 16, "Sixteen" },
    { 17, "Seventeen" },
    { 18, "Eighteen" },
    { 19, "Nineteen" }
};

std::unordered_map<int, std::string> grouping_map {
    { 0, "" },
    { 1, "Thousand" },
    { 2, "Million" },
    { 3, "Billion" },
    { 4, "Trillion" },
    { 5, "Quadrillion"},
    { 6, "Quintillion" }
};

std::string to_string_group_of_3(int number)
{
    assert(number < 1000);

    std::string number_string;
    std::string spacing = "";

    int hundreds = number / 100;
    if (hundreds) {
        number_string += ones_map[hundreds] + " Hundred";
        spacing = " ";
    }

    number %= 100;
    if (specials_map.find(number) != specials_map.end()) {
        if (number != 0) {
            number_string += spacing;
        }

        if (number != 0 || (number == 0 && hundreds == 0)) {
            number_string += specials_map[number];
        }
    }
    else {
        int tens = number / 10;
        if (tens != 0) {
            number_string += spacing;
        }

        number_string += tens_map[tens];
        if (tens != 0 || (tens == 0 && hundreds != 0)) {
            spacing = " ";
        }

        int ones = number %= 10;
        if (ones != 0) {
            number_string += spacing;
        }

        number_string += ones_map[ones];
    }

    return number_string;
}

std::string problem_273(int number)
{
    std::string number_string;

    int group = 0;
    std::string spacing = "";
    std::string group_spacing = "";

    do {
        int group_of_3 = number % 1000;
        number /= 1000;

        if (group_of_3 != 0 || (number == 0 && group == 0)) {
            number_string = to_string_group_of_3(group_of_3) +
                            group_spacing +
                            grouping_map[group] +
                            spacing +
                            number_string;
        }

        ++group;
        spacing = number != 0 && !number_string.empty() ? " " : "";
        group_spacing = " ";
    } while (number);

    return number_string;
}