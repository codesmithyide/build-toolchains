/*
    Copyright (c) 2020-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/build-toolchains/blob/main/LICENSE.txt
*/

#ifndef _CODESMITHYIDE_BUILDTOOLCHAINS_CMAKETOOLCHAIN_H_
#define _CODESMITHYIDE_BUILDTOOLCHAINS_CMAKETOOLCHAIN_H_

#include "CMakeGenerationOptions.h"
#include <Ishiko/Process.hpp>
#include <string>

namespace CodeSmithy
{

class CMakeToolchain
{
public:
    CMakeToolchain();

    void generate(const std::string& makefilePath, const Ishiko::Environment& environment) const;
    void generate(const std::string& makefilePath, const CMakeGenerationOptions& options,
        const Ishiko::Environment& environment) const;

    void build(const std::string& makefilePath, const Ishiko::Environment& environment) const;

private:
    std::string m_cmakePath;
};

}

#include "linkoptions.h"

#endif
