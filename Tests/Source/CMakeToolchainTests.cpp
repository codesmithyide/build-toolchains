/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildToolchains/blob/master/LICENSE.txt
*/

#include "CMakeToolchainTests.h"
#include "CodeSmithy/BuildToolchains/CMakeToolchain.h"

using namespace Ishiko::Tests;

CMakeToolchainTests::CMakeToolchainTests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "CMakeToolchain tests", environment)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void CMakeToolchainTests::ConstructorTest1(Test& test)
{
    CodeSmithy::CMakeToolchain toolchain;

    ISHTF_PASS();
}
