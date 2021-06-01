outputdir = "%{cfg.buildcfg}-%{cfg.platform}"

workspace "lynton"
    startproject "lynton"

    configurations { "Debug", "Release", "Dist" }
    platforms { "WASM", "Linux", "Windows" }

    -- wasm doesn't support 64bit
    filter { "platforms:WASM" }
        architecture "x86"
    filter { "not platforms:WASM" }
        architecture "x86_64"

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"
    filter "configurations:Release"
        defines { "RELEASE" }
        symbols "On"
        optimize "Full"
    filter "configurations:Dist"
        defines { "DIST" }
        optimize "Full"
    
    -- auto detection of system doesn't work with wasm
    filter "platforms:WASM"
        defines { "WASM" }
    filter "platforms:Linux"
        defines { "LINUX" }
    filter "platforms:Windows"
        defines { "WINDOWS" }
    filter {}

include "lynton"
