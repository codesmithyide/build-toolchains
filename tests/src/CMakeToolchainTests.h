/*
    Copyright (c) 2020-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/build-toolchains/blob/main/LICENSE.txt
*/

#ifndef _CODESMITHYIDE_TEST_BUILDTOOLCHAINS_CMAKETOOLCHAINTESTS_H_
#define _CODESMITHYIDE_TEST_BUILDTOOLCHAINS_CMAKETOOLCHAINTESTS_H_

#include <Ishiko/TestFramework.hpp>

class CMakeToolchainTests : public Ishiko::TestSequence
{
public:
    CMakeToolchainTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
};

#endif
