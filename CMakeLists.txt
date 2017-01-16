cmake_minimum_required (VERSION 2.6)
project (UE4)
set(CMAKE_CXX_STANDARD 11)

include("/home/matteo/Documenti/Unreal Projects/Aereo/Intermediate/ProjectFiles/IncludeDirectories.cmake")
include("/home/matteo/Documenti/Unreal Projects/Aereo/Intermediate/ProjectFiles/Definitions.cmake")
include("/home/matteo/Documenti/Unreal Projects/Aereo/Intermediate/ProjectFiles/Aereo.cmake")

# Custom target for Aereo project, Debug configuration
set(MONO_ROOT_PATH "/opt/UnrealEngine/Engine/Binaries/DotNET")
set(BUILD cd "${MONO_ROOT_PATH}")

add_custom_target(Aereo-Mac-Debug ${BUILD} && mono UnrealBuildTool.exe Aereo Linux Debug -project="/home/matteo/Documenti/Unreal Projects/Aereo/Aereo.uproject" -game)
add_custom_target(Aereo-Mac-Debug-clean ${BUILD} && mono UnrealBuildTool.exe Aereo Linux Debug -project="/home/matteo/Documenti/Unreal Projects/Aereo/Aereo.uproject" -clean)


# Custom target for Aereo project, DebugGame configuration
add_custom_target(Aereo-Mac-DebugGame ${BUILD} && mono UnrealBuildTool.exe Aereo Linux DebugGame -project="/home/matteo/Documenti/Unreal Projects/Aereo/Aereo.uproject" -game)
add_custom_target(Aereo-Mac-DebugGame-clean ${BUILD} && mono UnrealBuildTool.exe Aereo Linux DebugGame -project="/home/matteo/Documenti/Unreal Projects/Aereo/Aereo.uproject" -clean)


# Custom target for Aereo project, Development configuration
add_custom_target(Aereo ${BUILD} && mono UnrealBuildTool.exe Aereo Linux Development -project="/home/matteo/Documenti/Unreal Projects/Aereo/Aereo.uproject" -game)
add_custom_target(Aereo-clean ${BUILD} && mono UnrealBuildTool.exe Aereo Linux Development -project="/home/matteo/Documenti/Unreal Projects/Aereo/Aereo.uproject" -clean)


# Custom target for Aereo project, Shipping configuration
add_custom_target(Aereo-Mac-Shipping ${BUILD} && mono UnrealBuildTool.exe Aereo Linux Shipping -project="/home/matteo/Documenti/Unreal Projects/Aereo/Aereo.uproject" -game)
add_custom_target(Aereo-Mac-Shipping-clean ${BUILD} && mono UnrealBuildTool.exe Aereo Linux Shipping -project="/home/matteo/Documenti/Unreal Projects/Aereo/Aereo.uproject" -clean)


# Custom target for Aereo project, Test configuration
add_custom_target(Aereo-Mac-Test ${BUILD} && mono UnrealBuildTool.exe Aereo Linux Test -project="/home/matteo/Documenti/Unreal Projects/Aereo/Aereo.uproject" -game)
add_custom_target(Aereo-Mac-Test-clean ${BUILD} && mono UnrealBuildTool.exe Aereo Linux Test -project="/home/matteo/Documenti/Unreal Projects/Aereo/Aereo.uproject" -clean)

include("/home/matteo/Documenti/Unreal Projects/Aereo/Intermediate/ProjectFiles/AereoEditor.cmake")

# Custom target for AereoEditor project, Debug configuration
set(MONO_ROOT_PATH "/opt/UnrealEngine/Engine/Binaries/DotNET")
set(BUILD cd "${MONO_ROOT_PATH}")

add_custom_target(AereoEditor-Mac-Debug ${BUILD} && mono UnrealBuildTool.exe AereoEditor Linux Debug -project="/home/matteo/Documenti/Unreal Projects/Aereo/Aereo.uproject" -game)
add_custom_target(AereoEditor-Mac-Debug-clean ${BUILD} && mono UnrealBuildTool.exe AereoEditor Linux Debug -project="/home/matteo/Documenti/Unreal Projects/Aereo/Aereo.uproject" -clean)


# Custom target for AereoEditor project, DebugGame configuration
add_custom_target(AereoEditor-Mac-DebugGame ${BUILD} && mono UnrealBuildTool.exe AereoEditor Linux DebugGame -project="/home/matteo/Documenti/Unreal Projects/Aereo/Aereo.uproject" -game)
add_custom_target(AereoEditor-Mac-DebugGame-clean ${BUILD} && mono UnrealBuildTool.exe AereoEditor Linux DebugGame -project="/home/matteo/Documenti/Unreal Projects/Aereo/Aereo.uproject" -clean)


# Custom target for AereoEditor project, Development configuration
add_custom_target(AereoEditor ${BUILD} && mono UnrealBuildTool.exe AereoEditor Linux Development -project="/home/matteo/Documenti/Unreal Projects/Aereo/Aereo.uproject" -game)
add_custom_target(AereoEditor-clean ${BUILD} && mono UnrealBuildTool.exe AereoEditor Linux Development -project="/home/matteo/Documenti/Unreal Projects/Aereo/Aereo.uproject" -clean)


# Custom target for AereoEditor project, Shipping configuration
add_custom_target(AereoEditor-Mac-Shipping ${BUILD} && mono UnrealBuildTool.exe AereoEditor Linux Shipping -project="/home/matteo/Documenti/Unreal Projects/Aereo/Aereo.uproject" -game)
add_custom_target(AereoEditor-Mac-Shipping-clean ${BUILD} && mono UnrealBuildTool.exe AereoEditor Linux Shipping -project="/home/matteo/Documenti/Unreal Projects/Aereo/Aereo.uproject" -clean)


# Custom target for AereoEditor project, Test configuration
add_custom_target(AereoEditor-Mac-Test ${BUILD} && mono UnrealBuildTool.exe AereoEditor Linux Test -project="/home/matteo/Documenti/Unreal Projects/Aereo/Aereo.uproject" -game)
add_custom_target(AereoEditor-Mac-Test-clean ${BUILD} && mono UnrealBuildTool.exe AereoEditor Linux Test -project="/home/matteo/Documenti/Unreal Projects/Aereo/Aereo.uproject" -clean)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_C_COMPILER "/usr/bin/clang")

add_executable(AereoEditorFake ${AereoEditor_FILES})
