cmake_minimum_required(VERSION 3.7)

project("Bejeweld")

file(MAKE_DIRECTORY bin)

find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

INCLUDE_DIRECTORIES(include)

include_directories(ressources)


add_executable(Bejeweld main.cpp
                         src/Aleatoire.cpp
                         src/BanniereRessources.cpp
                         src/BoardModel.cpp
                         src/BoardView.cpp
                         src/Cscreen.cpp
                         src/Engine.cpp
                         src/GameScreen.cpp
                         src/Item.cpp
                         src/Label.cpp
                         src/Map_manager.cpp
                         src/Texture_manager.cpp
			             src/Grid.inl)
			             
target_include_directories(Bejeweld PUBLIC .)
target_link_libraries(Bejeweld sfml-graphics sfml-window sfml-system)



