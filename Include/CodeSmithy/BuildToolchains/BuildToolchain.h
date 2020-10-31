/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildToolchains/blob/master/LICENSE.txt
*/

#ifndef _CODESMITHYIDE_BUILDTOOLCHAINS_BUILDTOOLCHAIN_H_
#define _CODESMITHYIDE_BUILDTOOLCHAINS_BUILDTOOLCHAIN_H_

#include <Ishiko/Process.h>
#include <string>

namespace CodeSmithy
{

class BuildToolchain
{
public:
    virtual ~BuildToolchain() = default;

    virtual void build(const std::string& makefilePath, const Ishiko::Process::Environment& environment) const = 0;
};

}

#include "linkoptions.h"

#endif
