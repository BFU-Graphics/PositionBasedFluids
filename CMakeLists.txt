cmake_minimum_required(VERSION 3.24)
project(PositionBasedFluids VERSION 2.0.0 DESCRIPTION "Position Based Fluids" LANGUAGES CXX)

# renderers backend
set(KASUMI_RENDERER_3D TRUE)
add_subdirectory(kasumi)

add_executable(PBF_APP main.cpp)
file(GLOB headers pbf_solver.h domain/*.h emitter/*.h neighbor_search/*.h kernel/*.h)
file(GLOB sources pbf_solver.cpp domain/*.cpp emitter/*.cpp neighbor_search/*.cpp kernel/*.cpp)
target_sources(PBF_APP
        PRIVATE
        ${sources}

        PUBLIC
        FILE_SET HEADERS
        BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/../
        FILES
        ${headers}
        )
set_target_properties(PBF_APP PROPERTIES CXX_STANDARD 20 CXX_EXTENSIONS ON)
target_include_directories(PBF_APP PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(PBF_APP PUBLIC Kasumi_Render3D)