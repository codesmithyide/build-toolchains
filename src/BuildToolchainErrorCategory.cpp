/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/build-toolchains/blob/main/LICENSE.txt
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

std::ostream& BuildToolchainErrorCategory::streamOut(int value, std::ostream& os) const
{
    switch (static_cast<Value>(value))
    {
    case Value::generic_error:
        os << "generic error";
        break;

    case Value::build_error:
        os << "build error";
        break;

    default:
        os << "unknown value";
        break;
    }
    return os;
}

void Fail(Error& error, BuildToolchainErrorCategory::Value value) noexcept
{
    error.fail(BuildToolchainErrorCategory::Get(), static_cast<int>(value));
}

void Fail(Error& error, BuildToolchainErrorCategory::Value value, const std::string& message, const char* file,
    int line) noexcept
{
    error.fail(BuildToolchainErrorCategory::Get(), static_cast<int>(value), message, file, line);
}

void Throw(BuildToolchainErrorCategory::Value value, const std::string& message, const char* file, int line)
{
    throw Exception(static_cast<int>(value), BuildToolchainErrorCategory::Get(), message, file, line);
}

}
