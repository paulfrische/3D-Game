workspace "3D"
    configurations { "Debug", "Release" }

project "3D-Game"
    kind "ConsoleApp"
    language "C++"
    targetdir "build/%{cfg.buildcfg}"
    links { "GL", "GLEW", "glfw" }

    files { "src/*.h", "src/*.hpp", "src/*.c", "src/*.cpp" }

    filter "configurations:Debug"
        defines { "DEBUG" }

    filter "configurations:Release"
        defines { "NDEBUG", "RELEASE" }
        optimize "On"
