/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildToolchains/blob/master/LICENSE.txt
*/

#include "MakeToolchainTests.h"
#include "CodeSmithy/BuildToolchains/MakeToolchain.h"

using namespace Ishiko::Tests;

MakeToolchainTests::MakeToolchainTests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "MakeToolchain tests", environment)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void MakeToolchainTests::ConstructorTest1(Test& test)
{
    CodeSmithy::MakeToolchain toolchain;

    ISHTF_PASS();
}
