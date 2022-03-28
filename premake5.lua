workspace "cit"
    architecture "x64"
    configurations {"Debug", "Release"}

    language "C++"
    cppdialect "C++20"

    -- disable compiler extensions
    conformancemode "Yes" -- MSVC
    -- Linux GNU make
    filter { "system:linux", "action:gmake" }
        buildoptions { "-pedantic-errors" }

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


googletestRoot = "vendor/googletest/googletest"


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


project "cit_tests"
    location "tests"
    kind "ConsoleApp"

    targetdir ("bin/%{prj.name}")
    objdir ("bin-int/%{prj.name}")

    staticruntime "on"  -- sets the /MT flag
    runtime "Debug"     -- sets /MTd

    pchheader "citpch.h"
	--pchsource "src/testpch.cpp" -- This will automatically be platforms other than MSVC

    files
    {
        "tests/**.h",
        "tests/**.cpp",
        "src/**.h",
        "src/**.cpp",
    }

    excludes "src/cit.cpp"

    includedirs
    {
        "src",
        googletestRoot .. "/include",
    }

    links { "googletest" }


--project "googletest"
--    location (googletestRoot .. "/src")
--    kind "StaticLib"
--
--    targetdir (googletestRoot .. "/build")
--    objdir (googletestRoot .. "/build")
--
--    files
--    {
--        googletestRoot .. "/src/**.h",
--        googletestRoot .. "/src/**.cc",
--    }
--
--    includedirs
--    {
--        googletestRoot,
--        googletestRoot .. "/include",
--    }