/*
    Copyright (c) 2020-2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildToolchains/blob/master/LICENSE.txt
*/

#ifndef _CODESMITHYIDE_TEST_BUILDTOOLCHAINS_CMAKETOOLCHAINTESTS_H_
#define _CODESMITHYIDE_TEST_BUILDTOOLCHAINS_CMAKETOOLCHAINTESTS_H_

#include <Ishiko/Tests.h>

class CMakeToolchainTests : public Ishiko::Tests::TestSequence
{
public:
    CMakeToolchainTests(const Ishiko::Tests::TestNumber& number, const Ishiko::Tests::TestEnvironment& environment);

private:
    static void ConstructorTest1(Ishiko::Tests::Test& test);
};

#endif
