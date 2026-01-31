#include "storage/file/block.hpp"

namespace lunadb::storage
{
Block::Block(std::string filename, int number) :
    filename_(std::move(filename)),
    number_(number)
{
}

std::string Block::filename() const { return filename_; }
int Block::number() const { return number_; }
std::string Block::to_string() const
{
    return filename_ + ":" + std::to_string(number_);
}

} // namespace lunadb::storage