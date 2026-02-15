add_library(stack stack.c)

add_executable(ABB ABB.c)

target_link_libraries(ABB PRIVATE stack)