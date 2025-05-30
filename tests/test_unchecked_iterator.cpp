#ifndef UTF8_FOR_CPP_TEST_UNCHECKED_ITERATOR_H_2675DCD0_9480_4c0c_B92A_CC14C027B731
#define UTF8_FOR_CPP_TEST_UNCHECKED_ITERATOR_H_2675DCD0_9480_4c0c_B92A_CC14C027B731

#if __has_include(<gtest/gtest.h>)
#include <gtest/gtest.h>
#else
#define F_TEST_NO_MAIN
#include "../extern/ftest/ftest.h"
#endif

#include "utf8/unchecked.h"

using namespace utf8::unchecked;


TEST(UnCheckedIteratrTests, test_increment)
{
    const char* threechars = "\xf0\x90\x8d\x86\xe6\x97\xa5\xd1\x88";
    utf8::unchecked::iterator<const char*> it(threechars);
    utf8::unchecked::iterator<const char*> it2 = it;
    EXPECT_EQ (it2, it);
    EXPECT_EQ (*it, 0x10346);
    EXPECT_EQ (*(++it), 0x65e5);
    EXPECT_EQ ((*it++), 0x65e5);
    EXPECT_EQ (*it, 0x0448);
    EXPECT_NE (it, it2);
    utf8::unchecked::iterator<const char*> endit (threechars + 9);
    EXPECT_EQ (++it, endit);
}

TEST(UnCheckedIteratrTests, test_decrement)
{
    const char* threechars = "\xf0\x90\x8d\x86\xe6\x97\xa5\xd1\x88";
    utf8::unchecked::iterator<const char*> it(threechars+9);
    EXPECT_EQ (*(--it), 0x0448);
    EXPECT_EQ ((*it--), 0x0448);
    EXPECT_EQ (*it, 0x65e5);
    EXPECT_EQ (--it, utf8::unchecked::iterator<const char*>(threechars));
    EXPECT_EQ (*it, 0x10346);

}

#endif
