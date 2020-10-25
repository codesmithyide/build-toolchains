/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildToolchains/blob/master/LICENSE.txt
*/

#include "MSBuildToolchainTests.h"
#include "CodeSmithy/BuildToolchains/MSBuildToolchain.h"

using namespace Ishiko::Tests;

MSBuildToolchainTests::MSBuildToolchainTests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "MSBuildToolchain tests", environment)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void MSBuildToolchainTests::ConstructorTest1(Test& test)
{
    CodeSmithy::VisualStudioToolchain toolchain;
    
    ISHTF_PASS();
}
