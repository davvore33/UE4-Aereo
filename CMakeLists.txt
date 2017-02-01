cmake_minimum_required (VERSION 2.6)
project (UE4)
set(CMAKE_CXX_STANDARD 11)

include("C:/Users/matteo/Documents/Unreal Projects/Aereo/Intermediate/ProjectFiles/IncludeDirectories.cmake")
include("C:/Users/matteo/Documents/Unreal Projects/Aereo/Intermediate/ProjectFiles/Definitions.cmake")
include("C:/Users/matteo/Documents/Unreal Projects/Aereo/Intermediate/ProjectFiles/UE4Editor.cmake")

# Custom target for UE4Editor project, DebugGame configuration
set(MONO_ROOT_PATH "C:/Program Files (x86)/Epic Games/4.14/Engine/Binaries/DotNET")
set(BUILD cd "${MONO_ROOT_PATH}")

add_custom_target(UE4Editor-Mac-DebugGame ${BUILD} && UnrealBuildTool.exe UE4Editor Win64 DebugGame -project="C:/Users/matteo/Documents/Unreal Projects/Aereo/Aereo.uproject" -game)
add_custom_target(UE4Editor-Mac-DebugGame-clean ${BUILD} && UnrealBuildTool.exe UE4Editor Win64 DebugGame -project="C:/Users/matteo/Documents/Unreal Projects/Aereo/Aereo.uproject" -clean)


# Custom target for UE4Editor project, Development configuration
add_custom_target(UE4Editor ${BUILD} && UnrealBuildTool.exe UE4Editor Win64 Development -project="C:/Users/matteo/Documents/Unreal Projects/Aereo/Aereo.uproject" -game)
add_custom_target(UE4Editor-clean ${BUILD} && UnrealBuildTool.exe UE4Editor Win64 Development -project="C:/Users/matteo/Documents/Unreal Projects/Aereo/Aereo.uproject" -clean)


# Custom target for UE4Editor project, Shipping configuration
add_custom_target(UE4Editor-Mac-Shipping ${BUILD} && UnrealBuildTool.exe UE4Editor Win64 Shipping -project="C:/Users/matteo/Documents/Unreal Projects/Aereo/Aereo.uproject" -game)
add_custom_target(UE4Editor-Mac-Shipping-clean ${BUILD} && UnrealBuildTool.exe UE4Editor Win64 Shipping -project="C:/Users/matteo/Documents/Unreal Projects/Aereo/Aereo.uproject" -clean)

include("C:/Users/matteo/Documents/Unreal Projects/Aereo/Intermediate/ProjectFiles/UE4Game.cmake")

# Custom target for UE4Game project, DebugGame configuration
set(MONO_ROOT_PATH "C:/Program Files (x86)/Epic Games/4.14/Engine/Binaries/DotNET")
set(BUILD cd "${MONO_ROOT_PATH}")

add_custom_target(UE4Game-Mac-DebugGame ${BUILD} && UnrealBuildTool.exe UE4Game Win64 DebugGame -project="C:/Users/matteo/Documents/Unreal Projects/Aereo/Aereo.uproject" -game)
add_custom_target(UE4Game-Mac-DebugGame-clean ${BUILD} && UnrealBuildTool.exe UE4Game Win64 DebugGame -project="C:/Users/matteo/Documents/Unreal Projects/Aereo/Aereo.uproject" -clean)


# Custom target for UE4Game project, Development configuration
add_custom_target(UE4Game ${BUILD} && UnrealBuildTool.exe UE4Game Win64 Development -project="C:/Users/matteo/Documents/Unreal Projects/Aereo/Aereo.uproject" -game)
add_custom_target(UE4Game-clean ${BUILD} && UnrealBuildTool.exe UE4Game Win64 Development -project="C:/Users/matteo/Documents/Unreal Projects/Aereo/Aereo.uproject" -clean)


# Custom target for UE4Game project, Shipping configuration
add_custom_target(UE4Game-Mac-Shipping ${BUILD} && UnrealBuildTool.exe UE4Game Win64 Shipping -project="C:/Users/matteo/Documents/Unreal Projects/Aereo/Aereo.uproject" -game)
add_custom_target(UE4Game-Mac-Shipping-clean ${BUILD} && UnrealBuildTool.exe UE4Game Win64 Shipping -project="C:/Users/matteo/Documents/Unreal Projects/Aereo/Aereo.uproject" -clean)

include("C:/Users/matteo/Documents/Unreal Projects/Aereo/Intermediate/ProjectFiles/Aereo.cmake")

# Custom target for Aereo project, DebugGame configuration
set(MONO_ROOT_PATH "C:/Program Files (x86)/Epic Games/4.14/Engine/Binaries/DotNET")
set(BUILD cd "${MONO_ROOT_PATH}")

add_custom_target(Aereo-Mac-DebugGame ${BUILD} && UnrealBuildTool.exe Aereo Win64 DebugGame -project="C:/Users/matteo/Documents/Unreal Projects/Aereo/Aereo.uproject" -game)
add_custom_target(Aereo-Mac-DebugGame-clean ${BUILD} && UnrealBuildTool.exe Aereo Win64 DebugGame -project="C:/Users/matteo/Documents/Unreal Projects/Aereo/Aereo.uproject" -clean)


# Custom target for Aereo project, Development configuration
add_custom_target(Aereo ${BUILD} && UnrealBuildTool.exe Aereo Win64 Development -project="C:/Users/matteo/Documents/Unreal Projects/Aereo/Aereo.uproject" -game)
add_custom_target(Aereo-clean ${BUILD} && UnrealBuildTool.exe Aereo Win64 Development -project="C:/Users/matteo/Documents/Unreal Projects/Aereo/Aereo.uproject" -clean)


# Custom target for Aereo project, Shipping configuration
add_custom_target(Aereo-Mac-Shipping ${BUILD} && UnrealBuildTool.exe Aereo Win64 Shipping -project="C:/Users/matteo/Documents/Unreal Projects/Aereo/Aereo.uproject" -game)
add_custom_target(Aereo-Mac-Shipping-clean ${BUILD} && UnrealBuildTool.exe Aereo Win64 Shipping -project="C:/Users/matteo/Documents/Unreal Projects/Aereo/Aereo.uproject" -clean)

include("C:/Users/matteo/Documents/Unreal Projects/Aereo/Intermediate/ProjectFiles/AereoEditor.cmake")

# Custom target for AereoEditor project, DebugGame configuration
set(MONO_ROOT_PATH "C:/Program Files (x86)/Epic Games/4.14/Engine/Binaries/DotNET")
set(BUILD cd "${MONO_ROOT_PATH}")

add_custom_target(AereoEditor-Mac-DebugGame ${BUILD} && UnrealBuildTool.exe AereoEditor Win64 DebugGame -project="C:/Users/matteo/Documents/Unreal Projects/Aereo/Aereo.uproject" -game)
add_custom_target(AereoEditor-Mac-DebugGame-clean ${BUILD} && UnrealBuildTool.exe AereoEditor Win64 DebugGame -project="C:/Users/matteo/Documents/Unreal Projects/Aereo/Aereo.uproject" -clean)


# Custom target for AereoEditor project, Development configuration
add_custom_target(AereoEditor ${BUILD} && UnrealBuildTool.exe AereoEditor Win64 Development -project="C:/Users/matteo/Documents/Unreal Projects/Aereo/Aereo.uproject" -game)
add_custom_target(AereoEditor-clean ${BUILD} && UnrealBuildTool.exe AereoEditor Win64 Development -project="C:/Users/matteo/Documents/Unreal Projects/Aereo/Aereo.uproject" -clean)


# Custom target for AereoEditor project, Shipping configuration
add_custom_target(AereoEditor-Mac-Shipping ${BUILD} && UnrealBuildTool.exe AereoEditor Win64 Shipping -project="C:/Users/matteo/Documents/Unreal Projects/Aereo/Aereo.uproject" -game)
add_custom_target(AereoEditor-Mac-Shipping-clean ${BUILD} && UnrealBuildTool.exe AereoEditor Win64 Shipping -project="C:/Users/matteo/Documents/Unreal Projects/Aereo/Aereo.uproject" -clean)

set(CMAKE_CXX_COMPILER "C:/cygwin64/bin/clang-3.8.exe")
set(CMAKE_C_COMPILER "C:/cygwin64/bin/clang-3.8.exe")

add_executable(AereoEditorFake ${AereoEditor_FILES})
