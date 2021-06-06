project "lynton"
    language "C++"
    cppdialect "c++17"
    kind "ConsoleApp"

    warnings "Extra"

    location ""
    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "src/**.h", "src/**.cpp"
    }

    includedirs {
        "%{wks.location}/utils/src"
    }

    filter "platforms:WASM"
        linkoptions { "-s WASM=1", "-s EXPORTED_FUNCTIONS='[\"_main\"]'", "-s EXPORTED_RUNTIME_METHODS='[\"cwrap\"]'", "-s USE_SDL=2" }
        targetname ("%{prj.name}.html")
    filter "platforms:Linux"
        -- I hate everything!
        buildoptions { "`sdl2-config --cflags --libs`" }
        links { "SDL2main", "SDL2", "SDL2_image" }
        targetname ("%{prj.name}")
    -- not supported
    filter "platforms:Windows"
        targetname ("%{prj.name}.exe")
    filter {}
