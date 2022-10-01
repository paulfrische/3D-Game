workspace "3D"
    configurations { "Debug", "Release" }

project "3D-Game"
    kind "ConsoleApp"
    language "C++"
    targetdir "build/%{cfg.buildcfg}"
    links { "GL", "GLEW", "glfw" }

    files { "**.h", "**.hpp", "**.c", "**.cpp" }

    filter "configurations:Debug"
        defines { "DEBUG" }

    filter "configurations:Release"
        defines { "NDEBUG", "RELEASE" }
        optimize "On"
