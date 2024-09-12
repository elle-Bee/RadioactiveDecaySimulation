cmake_minimum_required(VERSION 3.16...3.21)
project(RadioactiveDecaySimulation)

option(WITH_GEANT4_UIVIS "Build example with Geant4 UI and Vis drivers" ON)
if(WITH_GEANT4_UIVIS)
  find_package(Geant4 REQUIRED ui_all vis_all)
else()
  find_package(Geant4 REQUIRED)
endif()

include(${Geant4_USE_FILE})

include_directories(${PROJECT_SOURCE_DIR}/include 
                    ${Geant4_INCLUDE_DIR})
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

add_executable(RadioactiveDecaySimulation RadioactiveDecaySimulation.cc ${sources} ${headers})
target_link_libraries(RadioactiveDecaySimulation ${Geant4_LIBRARIES} )

set(RadioactiveDecaySimulation_SCRIPTS
    alpha.mac Cf238.mac Co60.mac debug.mac Gd158.mac electronicCapture.mac fullChain.mac neutron.mac
    proton.mac No252.mac Po212.mac Ra228.mac RadioactiveDecaySimulation.in singleDecay.mac timeWindow.mac
    timeWindowBiased.mac timeWindowBiased.data atomicDeexcitation.mac vis.mac
  )

#foreach(_script ${RadioactiveDecaySimulation_SCRIPTS})
#  configure_file(
#    ${PROJECT_SOURCE_DIR}/${_script}
#    ${PROJECT_BINARY_DIR}/${_script}
#    COPYONLY
#    )
#endforeach()

install(TARGETS RadioactiveDecaySimulation DESTINATION bin)

