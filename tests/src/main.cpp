// SPDX-FileCopyrightText: 2015-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "MakeToolchainTests.h"
#include "MSBuildToolchainTests.h"
#include "CMakeToolchainTests.h"
#include <Ishiko/TestFramework.hpp>
#include <exception>

using namespace Ishiko;

int main(int argc, char* argv[])
{
    try
    {
        TestHarness::CommandLineSpecification command_line_spec;
        Configuration configuration = command_line_spec.createDefaultConfiguration();
        configuration.set("context.data", "../../data");
        CommandLineParser::parse(command_line_spec, argc, argv, configuration);

        TestHarness the_test_harness("CodeSmithyBuildToolchains Library Tests", configuration);

        TestSequence& the_tests = the_test_harness.tests();
        the_tests.append<MakeToolchainTests>();
        the_tests.append<MSBuildToolchainTests>();
        the_tests.append<CMakeToolchainTests>();

        return the_test_harness.run();
    }
    catch (const std::exception& e)
    {
        return TestApplicationReturnCode::exception;
    }
    catch (...)
    {
        return TestApplicationReturnCode::exception;
    }
}
