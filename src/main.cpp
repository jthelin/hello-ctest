#include <iostream>

std::string name = "World";

int main(int argc, char** argv) {
    if (argc > 1) {
        name = argv[1];
    }

    std::cout << "Hello " << name << std::endl;

    std::string num_resource_groups_str = getenv("CTEST_RESOURCE_GROUP_COUNT");
    std::cout << "CTEST_RESOURCE_GROUP_COUNT = " << num_resource_groups_str << std::endl;
    int num_resource_groups = std::stoi(num_resource_groups_str);

    for (int g = 0; g < num_resource_groups; g++) {
        std::string grp_name = "CTEST_RESOURCE_GROUP_" + std::to_string(g);
        std::string grp_type = getenv(grp_name.c_str());
        std::cout << grp_name << " - Type = " << grp_type << std::endl;

        std::string grp_ids_var = std::string(grp_name).append("_").append(grp_type);
        std::transform(grp_ids_var.begin(), grp_ids_var.end(), grp_ids_var.begin(), toupper);
        std::cout << "Env variable: " << grp_ids_var << std::endl;
        std::string grp_ids = getenv(grp_ids_var.c_str());
        std::cout << grp_name << " - Properties: " << grp_ids << std::endl;
    }

    return EXIT_SUCCESS;
}
