add_library(stack stack.c)
add_library(converter converter.c)

add_executable(shuntingYard shuntingYard.c)

target_link_libraries(converter PRIVATE stack)
target_link_libraries(shuntingYard PRIVATE converter)