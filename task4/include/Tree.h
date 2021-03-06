#pragma once

#include <vector>
#include <string>
#include <filesystem>

using std::filesystem::path;

struct FileNode {
  std::string name;
  bool is_dir;
  std::vector<FileNode> children;
};

FileNode GetTree(const std::string& path, bool dirs_only);

void FilterEmptyNodes(const FileNode& node, const path& current_path);

bool operator == (const FileNode& f1, const FileNode& f2);
