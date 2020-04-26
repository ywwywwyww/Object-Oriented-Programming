cmake_minimum_required(VERSION 3.15)
project(Problem1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Problem1 main.cpp pizza/pizza.cpp pizza/pizza.h pizza/cheese_pizza.cpp pizza/cheese_pizza.h generator/generator.cpp generator/generator.h pizza/veggie_pizza.cpp pizza/veggie_pizza.h pizza_factory/pizza_factory.cpp pizza_factory/pizza_factory.h pizza_factory/cheese_pizza_factory.cpp pizza_factory/cheese_pizza_factory.h pizza_factory/veggie_pizza_factory.cpp pizza_factory/veggie_pizza_factory.h pizza_store/pizza_store.cpp pizza_store/pizza_store.h pizza_heap/pizza_heap.cpp pizza_heap/pizza_heap.h sorter/sorter.cpp sorter/sorter.h sorter/customed_sorter.cpp sorter/customed_sorter.h sorter/stl_sort_sorter.cpp sorter/stl_sort_sorter.h sorter/stl_priority_queue_sorter.cpp sorter/stl_priority_queue_sorter.h)