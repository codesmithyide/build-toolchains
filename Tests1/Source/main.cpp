/*
    Copyright (c) 2020-2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildToolchains/blob/master/LICENSE.txt
*/

#include "MakeToolchainTests.h"
#include "MSBuildToolchainTests.h"
#include "CMakeToolchainTests.h"
#include <Ishiko/Tests.h>

using namespace Ishiko::Tests;

int main(int argc, char* argv[])
{
    TestHarness theTestHarness("CodeSmithyBuildToolchains");

    TestSequence& theTests = theTestHarness.tests();
    theTests.append<MakeToolchainTests>();
    theTests.append<MSBuildToolchainTests>();
    theTests.append<CMakeToolchainTests>();

    return theTestHarness.run();
}
