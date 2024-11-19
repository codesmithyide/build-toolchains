// SPDX-FileCopyrightText: 2015-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef _CODESMITHYIDE_TEST_BUILDTOOLCHAINS_CMAKETOOLCHAINTESTS_H_
#define _CODESMITHYIDE_TEST_BUILDTOOLCHAINS_CMAKETOOLCHAINTESTS_H_

#include <Ishiko/TestFramework.hpp>

class CMakeToolchainTests : public Ishiko::TestSequence
{
public:
    CMakeToolchainTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void GenerateTest1(Ishiko::Test& test);
};

#endif
