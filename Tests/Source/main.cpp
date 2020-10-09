/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildToolchains/blob/master/LICENSE.txt
*/

#include "VisualStudioToolchainTests.h"
#include "Ishiko/TestFramework/TestFrameworkCore.h"

using namespace Ishiko::Tests;

int main(int argc, char* argv[])
{
    TestHarness theTestHarness("CodeSmithyBuildToolchains");

    TestSequence& theTests = theTestHarness.tests();
    theTests.append<VisualStudioToolchainTests>();

    return theTestHarness.run();
}
