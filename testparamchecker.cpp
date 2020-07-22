#include "paramchecker.h"
#include <gtest/gtest.h>
 
TEST(VitalsTest, BPM) {
 std::vector<VitalCheckDetails> testInput = {{C_BPM ,100},{C_SPO2,100},{C_RESPRATE,50}};
    ASSERT_EQ(true, vitalsAreOk(testInput));
}
 
TEST(VitalsTest, SPO2) {
 std::vector<VitalCheckDetails> testInput = {{C_BPM ,100},{C_SPO2,40},{C_RESPRATE,50}};
    ASSERT_EQ(false, vitalsAreOk(testInput));
}

TEST(VitalsTest, SPO2_RESPRATE) {
 std::vector<VitalCheckDetails> testInput = {{C_BPM ,100},{C_SPO2,40},{C_RESPRATE,61}};
    ASSERT_EQ(false, vitalsAreOk(testInput));
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
