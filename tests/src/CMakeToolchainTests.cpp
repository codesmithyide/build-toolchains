// SPDX-FileCopyrightText: 2015-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "CMakeToolchainTests.h"
#include "CodeSmithy/BuildToolchains/CMakeToolchain.h"
#include <Ishiko/Process.hpp>
#include <boost/filesystem.hpp>

using namespace Ishiko;

CMakeToolchainTests::CMakeToolchainTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "CMakeToolchain tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("generate test 1", GenerateTest1);
}

void CMakeToolchainTests::ConstructorTest1(Test& test)
{
    CodeSmithy::CMakeToolchain toolchain;

    ISHIKO_TEST_PASS();
}

void CMakeToolchainTests::GenerateTest1(Test& test)
{
    const boost::filesystem::path& cmakelists_path = test.context().getOutputPath("cmake/hello-world/CMakeLists.txt");
    boost::filesystem::create_directories(cmakelists_path.parent_path());
    test.utils().copyFile("${context.data}/cmake/hello-world/CMakeLists.txt", cmakelists_path.string());
    test.utils().copyFile("${context.data}/cmake/hello-world/main.cpp", "${context.output}/cmake/hello-world/main.cpp");

    CodeSmithy::CMakeToolchain toolchain;
    toolchain.generate(cmakelists_path.string(), Ishiko::CurrentEnvironment());

    ISHIKO_TEST_PASS();
}
