/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildToolchains/blob/master/LICENSE.txt
*/

#include "VisualStudioToolchainTests.h"
#include "CodeSmithy/BuildToolchains/VisualStudioToolchain.h"

using namespace Ishiko::Tests;

VisualStudioToolchainTests::VisualStudioToolchainTests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "VisualStudioToolchain tests", environment)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void VisualStudioToolchainTests::ConstructorTest1(Test& test)
{
    CodeSmithy::VisualStudioToolchain toolchain;
    
    ISHTF_PASS();
}
