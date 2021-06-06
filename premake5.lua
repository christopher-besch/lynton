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

project "lynton"
    language "C++"
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
        "utils/src"
    }

    links {
        "utils"
    }

    filter "platforms:WASM"
        linkoptions { "-s WASM=1", "-s EXPORTED_FUNCTIONS='[\"_main\"]'", "-s EXPORTED_RUNTIME_METHODS='[\"cwrap\"]'", "-s USE_SDL=2" }
        targetname ("%{prj.name}.html")

    filter "platforms:Linux"
        links {
            "SDL2"
        }
        targetname ("%{prj.name}")

    -- not supported
    filter "platforms:Windows"
        targetname ("%{prj.name}.exe")

include "utils"
