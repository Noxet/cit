workspace "cit"
    architecture "x64"
    configurations {"Debug", "Release"}

    language "C++"
    cppdialect "C++20"

    filter "configurations:Debug"
        -- Add preprocessor definition DEBUG to compiler
        defines {"DEBUG"}
        -- Enable debugging symbols
        symbols "On"
    
    filter "configurations:Release"
        defines {"RELEASE"}
        -- Turn on dat optimization
        optimize "On"

    filter "system:windows"
        defines {"WINDOWS"}


project "cit"
    location "src"
    kind "ConsoleApp"

    targetdir ("bin/%{prj.name}")
    objdir ("bin-int/%{prj.name}")

    pchheader "citpch.h"
	pchsource "src/citpch.cpp" -- This will automatically be platforms other than MSVC

    files
    {
        "src/**.h",
        "src/**.cpp",
    }

    includedirs
    {

    }
