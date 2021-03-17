#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "unindent.h"

// add your tests here
TEST_CASE("Task A: Remove leading space --> Not remove"){
    CHECK(removeLeadingSpaces("fhubeufhbe jewfneiuv ijwidn") == "fhubeufhbe jewfneiuv ijwidn");
    CHECK(removeLeadingSpaces("this sentence has no leading space") == "this sentence has no leading space");
    CHECK(removeLeadingSpaces("this sentence has no leading space but has trailing          ") == "this sentence has no leading space but has trailing          ");

}

TEST_CASE("Task A: Remove leading space --> Removes it"){
    CHECK(removeLeadingSpaces("           this sentence has leading space") == "this sentence has leading space");
    CHECK(removeLeadingSpaces("        urnf_njfe_niejvn") == "urnf_njfe_niejvn");
    CHECK(removeLeadingSpaces("   monkey d luffy            ") == "monkey d luffy            ");

}


TEST_CASE("COUNT CHAR"){
    CHECK(countChar("ijnirbg nvruvbr # # # ", '#') == 3);
    CHECK(countChar(" a a a a a ", 'a') == 5);
    CHECK(countChar("         ijnirbg nvruvbr # # #        ", 'z') == 0);
}