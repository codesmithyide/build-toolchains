/*
    Copyright (c) 2020-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/build-toolchains/blob/main/LICENSE.txt
*/

#include "MakeToolchainTests.h"
#include "MSBuildToolchainTests.h"
#include "CMakeToolchainTests.h"
#include <Ishiko/TestFramework.hpp>

using namespace Ishiko;

int main(int argc, char* argv[])
{
    TestHarness theTestHarness("CodeSmithyBuildToolchains");

    TestSequence& theTests = theTestHarness.tests();
    theTests.append<MakeToolchainTests>();
    theTests.append<MSBuildToolchainTests>();
    theTests.append<CMakeToolchainTests>();

    return theTestHarness.run();
}
