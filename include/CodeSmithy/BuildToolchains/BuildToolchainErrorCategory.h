/*
    Copyright (c) 2020-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/build-toolchains/blob/main/LICENSE.txt
*/

#ifndef _CODESMITHYIDE_BUILDTOOLCHAINS_BUILDTOOLCHAINERRORCATEGORY_H_
#define _CODESMITHYIDE_BUILDTOOLCHAINS_BUILDTOOLCHAINERRORCATEGORY_H_

#include <Ishiko/Errors.hpp>
#include <string>

namespace CodeSmithy
{

class BuildToolchainErrorCategory : public Ishiko::ErrorCategory
{
public:
    enum EErrorValues
    {
        eGeneric = -1,
        eBuildError = -2
    };

    static const BuildToolchainErrorCategory& Get() noexcept;

    const char* name() const noexcept override;

private:
    BuildToolchainErrorCategory() noexcept = default;
};

void Fail(Ishiko::Error& error, BuildToolchainErrorCategory::EErrorValues value) noexcept;
void Fail(Ishiko::Error& error, BuildToolchainErrorCategory::EErrorValues value, const std::string& message,
    const char* file, int line) noexcept;
void Throw(BuildToolchainErrorCategory::EErrorValues value, const std::string& message, const char* file, int line);

}

#endif
