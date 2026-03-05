add_library(CircularList CircularList.c)

add_executable(countingRhyme countingRhyme.c)

target_link_libraries(countingRhyme PRIVATE CircularList)