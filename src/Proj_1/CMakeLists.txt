project(Proj_1)
MESSAGE("------------------------Proj_1:Hello QT")

set(CMAKE_PREFIX_PATH $ENV{QT_PATH})

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
find_package(Qt5 COMPONENTS Core Gui Qml Widgets  Quick REQUIRED)

INCLUDE_DIRECTORIES(
	./header
	.
)

FILE(GLOB PROJECT_SOURCE_FILES ${PROJECT_SOURCE_FILES}
    *.cpp
	./src/*.cpp
    )
source_group("Source Files" FILES ${PROJECT_SOURCE_FILES})

FILE(GLOB PROJECT_HEADER_FILES ${PROJECT_HEADER_FILES}
	*.h
	./header/*.h
    )
source_group("Headers" FILES ${PROJECT_HEADER_FILES})

FILE(GLOB PROJECT_Res_FILES ${PROJECT_Res_FILES}
	./res/*.qrc
	./res/*.qml
    )
source_group("Headers" FILES ${PROJECT_Res_FILES})

FILE(GLOB UI_FILES ${UI_FILES}
	UI/*.ui) 
qt5_wrap_ui(WRAP_FILES ${UI_FILES})
set(RCC_FILES *.qrc)
source_group("Ui" FILES ${UI_FILES} ${WRAP_FILES} )

ADD_EXECUTABLE(${PROJECT_NAME} ${PROJECT_SOURCE_FILES} ${PROJECT_Res_FILES} ${PROJECT_HEADER_FILES} ${WRAP_FILES})
SET(EXECUTABLE_OUTPUT_PATH ${BIN_DIR})
target_link_libraries(${PROJECT_NAME}  Qt5::Core Qt5::Gui Qt5::Qml Qt5::Quick Qt5::Widgets )

set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER "Proj_1")










