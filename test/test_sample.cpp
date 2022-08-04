#include <gtest/gtest.h>

#include <sample.h>

TEST(Sample, MustReturnTrue)
{
    ASSERT_TRUE(sample());
}