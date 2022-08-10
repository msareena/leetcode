#include <gtest/gtest.h>

#include <string>

#include <273/problem_273.h>

struct TestParam
{
    int input_number;
    std::string expected_english_string;
};

class Problem273ParameterizedTestFixture
    : public ::testing::TestWithParam<TestParam>
{ };

TEST_P(Problem273ParameterizedTestFixture, ReturnsExpectedEnglishString)
{
    TestParam const param = GetParam();

    ASSERT_EQ(problem_273(param.input_number), param.expected_english_string);
}

INSTANTIATE_TEST_CASE_P(
    Problem273Tests,
    Problem273ParameterizedTestFixture,
    ::testing::Values(
        TestParam{
            .input_number=123,
            .expected_english_string="One Hundred Twenty Three"
        },
        TestParam{
            .input_number=0,
            .expected_english_string="Zero"
        },
        TestParam{
            .input_number=100,
            .expected_english_string="One Hundred"
        },
        TestParam{
            .input_number=313,
            .expected_english_string="Three Hundred Thirteen"
        },
        TestParam{
            .input_number=999,
            .expected_english_string="Nine Hundred Ninety Nine"
        },
        TestParam{
            .input_number=608,
            .expected_english_string="Six Hundred Eight"
        },
        TestParam{
            .input_number=34,
            .expected_english_string="Thirty Four"
        },
        TestParam{
            .input_number=17,
            .expected_english_string="Seventeen"
        },
        TestParam{
            .input_number=10,
            .expected_english_string="Ten"
        },
        TestParam{
            .input_number=810,
            .expected_english_string="Eight Hundred Ten"
        },
        TestParam{
            .input_number=12345,
            .expected_english_string="Twelve Thousand Three Hundred Forty Five"
        },
        TestParam{
            .input_number=1234567,
            .expected_english_string="One Million "
                                     "Two Hundred Thirty Four Thousand "
                                     "Five Hundred Sixty Seven"
        },
        TestParam{
            .input_number=1008000012,
            .expected_english_string="One Billion "
                                     "Eight Million "
                                     "Twelve"
        },
        TestParam{
            .input_number=1000,
            .expected_english_string="One Thousand"
        },
        TestParam{
            .input_number=1000000,
            .expected_english_string="One Million"
        },
        TestParam{
            .input_number=1000000000,
            .expected_english_string="One Billion"
        }
    )
);