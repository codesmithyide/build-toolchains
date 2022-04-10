/*
    Copyright (c) 2020-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/build-toolchains/blob/main/LICENSE.txt
*/

#include "CMakeToolchainTests.h"
#include "CodeSmithy/BuildToolchains/CMakeToolchain.h"

using namespace Ishiko;

CMakeToolchainTests::CMakeToolchainTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "CMakeToolchain tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void CMakeToolchainTests::ConstructorTest1(Test& test)
{
    CodeSmithy::CMakeToolchain toolchain;

    ISHIKO_TEST_PASS();
}
