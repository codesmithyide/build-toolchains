/*
    Copyright (c) 2020-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/build-toolchains/blob/main/LICENSE.txt
*/

#include "MakeToolchainTests.h"
#include "CodeSmithy/BuildToolchains/MakeToolchain.h"

using namespace Ishiko;

MakeToolchainTests::MakeToolchainTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "MakeToolchain tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void MakeToolchainTests::ConstructorTest1(Test& test)
{
    CodeSmithy::MakeToolchain toolchain;

    ISHIKO_TEST_PASS();
}
