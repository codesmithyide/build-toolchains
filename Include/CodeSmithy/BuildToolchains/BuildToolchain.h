/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildToolchains/blob/master/LICENSE.txt
*/

#ifndef _CODESMITHYIDE_BUILDTOOLCHAINS_BUILDTOOLCHAIN_H_
#define _CODESMITHYIDE_BUILDTOOLCHAINS_BUILDTOOLCHAIN_H_

namespace CodeSmithy
{

class BuildToolchain
{
public:
    virtual ~BuildToolchain() = default;
};

}

#include "linkoptions.h"

#endif
