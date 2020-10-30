/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildToolchains/blob/master/LICENSE.txt
*/

#ifndef _CODESMITHYIDE_TEST_BUILDTOOLCHAINS_MSBUILDTOOLCHAINTESTS_H_
#define _CODESMITHYIDE_TEST_BUILDTOOLCHAINS_MSBUILDTOOLCHAINTESTS_H_

#include "Ishiko/TestFramework/TestFrameworkCore.h"

class MSBuildToolchainTests : public Ishiko::Tests::TestSequence
{
public:
    MSBuildToolchainTests(const Ishiko::Tests::TestNumber& number, const Ishiko::Tests::TestEnvironment& environment);

private:
    static void ConstructorTest1(Ishiko::Tests::Test& test);
};

#endif
