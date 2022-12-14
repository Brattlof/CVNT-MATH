workspace "CVNT"
	architecture "x86_64"
	startproject "Playground"
	staticruntime "on"
	language "C++"
	cppdialect "C++20"
	
	targetdir ("%{wks.location}/Binaries/%{prj.name}/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}")
	objdir ("%{wks.location}/Binaries/%{prj.name}/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}")
	
	configurations
	{
		"Debug",
		"Release"
	}
	
	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
	}
	
	includedirs
	{
		"%{wks.location}/Source",
	}
	
	filter "system:windows"
		systemversion "latest"
		
project "Math"
	location "Source"
	kind "StaticLib"
	
	pchheader "pch.hpp"
	pchsource "Source/pch.cpp"
	
	files
	{
		"Source/**.h",
		"Source/**.hpp",
		"Source/**.c",
		"Source/**.cpp"
	}
	
	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"
		
	filter "configurations:Release"
		runtime "Release"
		optimize "on"
		
project "Playground"
	location "Playground"
	kind "ConsoleApp"
	
	files
	{
		"Playground/**.h",
		"Playground/**.hpp",
		"Playground/**.c",
		"Playground/**.cpp"
	}
	
	links
	{
		"Math"
	}
	
	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"
		
	filter "configurations:Release"
		runtime "Release"
		optimize "on"