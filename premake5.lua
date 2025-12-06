workspace "clog"
    configurations { "Debug", "Release" }

    targetdir "bin/%{cfg.buildcfg}/"
    objdir "bin-int/%{cfg.buildcfg}/"
    startproject "clog"

    project "clog"
        kind "ConsoleApp"
        language "C++"
        cppdialect "C++23"

        files {"**.cpp", "**.hpp"}
        includedirs { "include" }

        filter "configurations:Debug"
            defines { "DEBUG" }
            symbols "On"
        
        filter "configurations:Release"
            defines { "NDEBUG" }
            optimize "On"