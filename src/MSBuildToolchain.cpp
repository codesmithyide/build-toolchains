/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/build-toolchains/blob/main/LICENSE.txt
*/

#include "MSBuildToolchain.h"
#include "BuildToolchainErrorCategory.h"

namespace CodeSmithy
{

namespace
{

std::string CreateCommandLine(const std::string& msbuildPath, const std::string& makefilePath)
{
    std::string commandLine = msbuildPath;
    commandLine.append(" -property:Platform=x64 ");
    commandLine.append(makefilePath);
    return commandLine;
}

}

MSBuildToolchain::MSBuildToolchain()
    : m_msbuildPath("C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\MSBuild\\15.0\\Bin\\MSBuild.exe")
{
}

void MSBuildToolchain::build(const std::string& makefilePath) const
{
    std::string commandLine = CreateCommandLine(m_msbuildPath, makefilePath);
    Ishiko::ChildProcess processHandle = Ishiko::ChildProcess::Spawn(commandLine);
    processHandle.waitForExit();
    int exitCode = processHandle.exitCode();
    if (exitCode != 0)
    {
        Throw(BuildToolchainErrorCategory::eBuildError, "Process launched by " + commandLine + " exited with code "
            + std::to_string(exitCode), __FILE__, __LINE__);
    }
}

void MSBuildToolchain::build(const std::string& makefilePath, Ishiko::Error& error) const noexcept
{
    std::string commandLine = CreateCommandLine(m_msbuildPath, makefilePath);
    Ishiko::ChildProcess processHandle = Ishiko::ChildProcess::Spawn(commandLine, error);
    if (!error)
    {
        processHandle.waitForExit();
        int exitCode = processHandle.exitCode();
        if (exitCode != 0)
        {
            Fail(error, BuildToolchainErrorCategory::eBuildError, "Process launched by " + commandLine
                + " exited with code " + std::to_string(exitCode), __FILE__, __LINE__);
        }
    }
}

void MSBuildToolchain::build(const std::string& makefilePath, const Ishiko::Environment& environment) const
{
    std::string commandLine = CreateCommandLine(m_msbuildPath, makefilePath);
    Ishiko::ChildProcess processHandle = Ishiko::ChildProcess::Spawn(commandLine, environment);
    processHandle.waitForExit();
    int exitCode = processHandle.exitCode();
    if (exitCode != 0)
    {
        Throw(BuildToolchainErrorCategory::eBuildError, "Process launched by " + commandLine + " exited with code "
            + std::to_string(exitCode), __FILE__, __LINE__);
    }
}

void MSBuildToolchain::build(const std::string& makefilePath, const Ishiko::Environment& environment,
    Ishiko::Error& error) const noexcept
{
    std::string commandLine = CreateCommandLine(m_msbuildPath, makefilePath);
    Ishiko::ChildProcess processHandle = Ishiko::ChildProcess::Spawn(commandLine, environment, error);
    if (!error)
    {
        processHandle.waitForExit();
        int exitCode = processHandle.exitCode();
        if (exitCode != 0)
        {
            Fail(error, BuildToolchainErrorCategory::eBuildError, "Process launched by " + commandLine
                + " exited with code " + std::to_string(exitCode), __FILE__, __LINE__);
        }
    }
}

}
