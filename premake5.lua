workspace "Magician"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"



project "Magician"
	location "Magician"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.18362.0"

		defines
		{
			"MAGICIAN_PLATFORM_WINDOWS",
			"MAGICIAN_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "MAGICIAN_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "MAGICIAN_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "MAGICIAN_DIST"
		optimize "On"








project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Magician/vendor/spdlog/include",
		"Magician/src"
	}
	links
	{
		"Magician"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.18362.0"

		defines
		{
			"MAGICIAN_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "MAGICIAN_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "MAGICIAN_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "MAGICIAN_DIST"
		optimize "On"