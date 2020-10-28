/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildToolchains/blob/master/LICENSE.txt
*/

#include "BuildToolchainErrorCategory.h"

using namespace Ishiko;

namespace CodeSmithy
{

const BuildToolchainErrorCategory& BuildToolchainErrorCategory::Get() noexcept
{
    static BuildToolchainErrorCategory theCategory;
    return theCategory;
}

const char* BuildToolchainErrorCategory::name() const noexcept
{
    return "CodeSmithy::BuildToolchainErrorCategory";
}

void Fail(Error& error, BuildToolchainErrorCategory::EErrorValues value) noexcept
{
    error.fail(value, BuildToolchainErrorCategory::Get());
}

void Fail(Error& error, BuildToolchainErrorCategory::EErrorValues value, const std::string& message, const char* file,
    int line) noexcept
{
    error.fail(value, BuildToolchainErrorCategory::Get(), message, file, line);
}

void Throw(BuildToolchainErrorCategory::EErrorValues value, const std::string& message, const char* file, int line)
{
    throw Exception(value, BuildToolchainErrorCategory::Get(), message, file, line);
}

}
