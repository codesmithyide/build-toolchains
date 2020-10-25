/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildToolchains/blob/master/LICENSE.txt
*/

#include "MSBuildToolchainTests.h"
#include "Ishiko/TestFramework/TestFrameworkCore.h"

using namespace Ishiko::Tests;

int main(int argc, char* argv[])
{
    TestHarness theTestHarness("CodeSmithyBuildToolchains");

    TestSequence& theTests = theTestHarness.tests();
    theTests.append<MSBuildToolchainTests>();

    return theTestHarness.run();
}
