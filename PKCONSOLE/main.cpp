#include <PKHeader/Shape.h>
#include <PKHeader/System.h>
#include <iomanip>
#include <iostream>
#include <optional>
#include <types.hpp>

int main(int argc, char** argv)
{
    Shape* practice_model = gsys->loadShape("courses/practice/practice.mod", true);
    if (practice_model) {
        std::cout << "vertex count: " << practice_model->m_vertexCount << std::endl;
        std::cout << "vertex normal count: " << practice_model->m_normalCount << std::endl;
    }

    return EXIT_SUCCESS;
}