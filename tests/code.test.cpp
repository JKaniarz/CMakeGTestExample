//
//  code.test.cpp
//  CMakeGTestExample
//
//  Created by John Kaniarz on 4/29/20.
//  Copyright © 2020 John Kaniarz. All rights reserved.
//

#include "code.hpp"
#include "gtest/gtest.h"

namespace {

TEST(AddTest, Add) {
	EXPECT_EQ(5, add(3,2));
}

} //namespace