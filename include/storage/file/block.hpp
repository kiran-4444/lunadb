#pragma once

#include <string>

namespace lunadb::storage
{
// A Block is the basic unit of disk persistence in the database.
// The Block is a fixed-size chunk of data that is stored on disk.
// Block resides in a file on disk and is identified by a file name and a block number.
// The default block size is 4096 bytes.
class Block
{
  private:
    std::string filename_;
    int number_;

  public:
    Block(std::string filename, int number);
    // Rule of Zero: Compiler generated copy/move/destructor are fine
    // Block(const Block &other) = default; // Implicitly generated
    // Block &operator=(const Block &other) = default; // Implicitly generated

    std::string filename() const;
    int number() const;
    std::string to_string() const;
};

} // namespace lunadb::storage