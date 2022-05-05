#include "TreeTestCase.h"
#include "Tree.h"
#include <filesystem>
#include <fstream>


TEST(tree, test) {
ASSERT_THROW(GetTree("/non_exist_directory", true), std::invalid_argument);

std::vector<FileNode> d(0);
FileNode dir{};
dir.name = "first";
dir.is_dir = true;
dir.children = d;

std::vector<FileNode> f(0);
FileNode file{};
file.name = "second";
file.is_dir = false;
file.children = f;


ASSERT_EQ(operator==(dir,dir), true);

std::string path = std::filesystem::current_path();
std::filesystem::create_directory(path + "/new_dir");
std::filesystem::create_directory(path + "/new_dir" + "/child");

std::vector<FileNode> nd(0);
FileNode new_d{};
new_d.name = "new_dir";
new_d.is_dir = true;
new_d.children = nd;

std::vector<FileNode> c(0);
FileNode child{};
child.name = "child";
child.is_dir = true;
child.children = c;

new_d.children.push_back(child);

ASSERT_EQ(GetTree(path + "/new_dir", true), new_d);

FileNode new_f{};
new_f.name = "second";
new_f.is_dir = false;
new_f.children = f;

FilterEmptyNodes(file, ".");
ASSERT_EQ(new_f, file);

dir.children.push_back(file);
FilterEmptyNodes(dir, ".");
ASSERT_EQ(dir.children.size(), 1);

FileNode node = GetTree(std::filesystem::current_path(), true);
ASSERT_EQ(GetTree(std::filesystem::current_path(), true), node);

std::string direct = std::filesystem::current_path().string();
std::string new_dir = direct + "/dir";
std::filesystem::create_directory(new_dir);
std::ofstream test_file(new_dir + "/file.txt");
std::string file_name = (direct + "/dir" + "/file.txt");
test_file.close();
ASSERT_THROW(GetTree(file_name, true), std::invalid_argument);

ASSERT_NO_THROW(FilterEmptyNodes(GetTree(direct, false), direct));

std::filesystem::remove_all(new_dir);
}