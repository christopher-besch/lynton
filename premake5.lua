outputdir = "%{cfg.buildcfg}-%{cfg.platform}"

workspace "lynton"
    startproject "lynton"

    configurations { "Debug", "Release", "Dist" }
    platforms { "WASM", "Linux", "Windows" }

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

project "lynton"
    language "C++"
    -- filter { "platforms:WASM" }
    --     architecture "x86"
    filter {}
        architecture "x86_64"
    cppdialect "c++latest"
    kind "ConsoleApp"

    location "%{prj.name}"
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp"
    }
    
    includedirs {
        "%{prj.name}/src",
    }

    filter "platforms:WASM"
        targetname ("%{prj.name}.html")
        linkoptions { "-mwasm64" }
    filter "platforms:Linux"
        targetname ("%{prj.name}")
    filter "platforms:Windows"
        targetname ("%{prj.name}.exe")
