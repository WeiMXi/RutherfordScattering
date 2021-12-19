cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(RutherfordScattering)

find_package(Geant4 REQUIRED ui_all vis_all)
include(${Geant4_USE_FILE})

include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

add_executable(RuScat RuScat.cc ${sources} ${headers})
target_link_libraries(RuScat ${Geant4_LIBRARIES})

set(RUSCAT_SCRIPTS vis.mac run.mac)
foreach(_script ${RUSCAT_SCRIPTS})
    configure_file(
        ${PROJECT_SOURCE_DIR}/${_script}
        ${PROJECT_BINARY_DIR}/${_script}
        COPYONLY
    )
endforeach()

add_custom_target(RutherfordScattering DEPENDS RuScat)
