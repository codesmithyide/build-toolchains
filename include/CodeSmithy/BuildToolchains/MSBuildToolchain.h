/*
    Copyright (c) 2020-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/build-toolchains/blob/main/LICENSE.txt
*/

#ifndef _CODESMITHYIDE_BUILDTOOLCHAINS_MSBUILDTOOLCHAIN_H_
#define _CODESMITHYIDE_BUILDTOOLCHAINS_MSBUILDTOOLCHAIN_H_

#include <Ishiko/Errors.hpp>
#include <Ishiko/Process.h>
#include <string>

namespace CodeSmithy
{

class MSBuildToolchain
{
public:
    MSBuildToolchain();

    void build(const std::string& makefilePath) const;
    void build(const std::string& makefilePath, Ishiko::Error& error) const noexcept;
    void build(const std::string& makefilePath, const Ishiko::Process::Environment& environment) const;
    void build(const std::string& makefilePath, const Ishiko::Process::Environment& environment,
        Ishiko::Error& error) const noexcept;

private:
    std::string m_msbuildPath;
};

}

#include "linkoptions.h"

#endif
