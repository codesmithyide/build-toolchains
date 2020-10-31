/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildToolchains/blob/master/LICENSE.txt
*/

#ifndef _CODESMITHYIDE_BUILDTOOLCHAINS_MSBUILDTOOLCHAIN_H_
#define _CODESMITHYIDE_BUILDTOOLCHAINS_MSBUILDTOOLCHAIN_H_

#include "BuildToolchain.h"
#include <Ishiko/Errors.h>
#include <Ishiko/Process.h>
#include <string>

namespace CodeSmithy
{

class MSBuildToolchain : public BuildToolchain
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
