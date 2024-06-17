workspace "UniversalEngine"
	architecture "x64"

	configurations {
		"Debug",
		"Dist",
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}

project "Application"
	location "Application"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	staticruntime "on"

	targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"Engine/src"
	}

	links{
		"Engine"
	}

	filter "system:windows"
		systemversion "latest"

		defines{
			"UE_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "UE_DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "UE_RELEASE"
		optimize "on"

	filter "configurations:Dist"
		defines "UE_DIST"
		optimize "on"

project "Engine"
	location "Engine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "on"

	targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

	pchheader "uepch.h"
	pchsource "Engine/src/uepch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"%{prj.name}/src"
	}

		defines
		{
			"_CRT_SECURE_NO_WARNINGS",
		}

	links{
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines{
			"UE_PLATFORM_WINDOWS",
			"GLFW_INCLUDE_NONE",
		}

	filter "configurations:Debug"
		defines "UE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "UE_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "UE_DIST"
		runtime "Release"
		optimize "on"
