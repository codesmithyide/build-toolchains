/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildToolchains/blob/master/LICENSE.txt
*/

#include "CMakeToolchain.h"
#include "BuildToolchainErrorCategory.h"

using namespace Ishiko::Process;

namespace CodeSmithy
{

namespace
{

std::string CreateGenerationCommandLine(const std::string& cmakePath, const std::string& makefilePath)
{
    std::string commandLine = cmakePath;
    commandLine.append(" -G \"Visual Studio 15 2017 Win64\" -S ");
    commandLine.append(boost::filesystem::path(makefilePath).parent_path().string());
    commandLine.append(" -B ");
    commandLine.append(boost::filesystem::path(makefilePath).parent_path().string());
    commandLine.append(" -DBUILD_SHARED_LIBS=OFF -DSTATIC_CRT=OFF");
    return commandLine;
}

std::string CreateBuildCommandLine(const std::string& cmakePath, const std::string& makefilePath)
{
    std::string commandLine = cmakePath;
    commandLine.append(" --build ");
    commandLine.append(boost::filesystem::path(makefilePath).parent_path().string());
    return commandLine;
}

}

CMakeToolchain::CMakeToolchain()
    : m_cmakePath("cmake")
{
}

void CMakeToolchain::generate(const std::string& makefilePath, const Ishiko::Process::Environment& environment) const
{
    CMakeGenerationOptions options;
    generate(makefilePath, options, environment);
}

void CMakeToolchain::generate(const std::string& makefilePath, const CMakeGenerationOptions& options,
    const Ishiko::Process::Environment& environment) const
{
    std::string  commandLine = CreateGenerationCommandLine(m_cmakePath, makefilePath);
    ChildProcess process = ChildProcess::Spawn(commandLine, environment);
    process.waitForExit();
    int exitCode = process.exitCode();
    if (exitCode != 0)
    {
        Throw(BuildToolchainErrorCategory::eBuildError, "Process launched by " + commandLine + " exited with code "
            + std::to_string(exitCode), __FILE__, __LINE__);
    }
}

void CMakeToolchain::build(const std::string& makefilePath, const Environment& environment) const
{
    std::string commandLine = CreateBuildCommandLine(m_cmakePath, makefilePath);
    ChildProcess process = ChildProcess::Spawn(commandLine, environment);
    process.waitForExit();
    int exitCode = process.exitCode();
    if (exitCode != 0)
    {
        Throw(BuildToolchainErrorCategory::eBuildError, "Process launched by " + commandLine + " exited with code "
            + std::to_string(exitCode), __FILE__, __LINE__);
    }
}

}
