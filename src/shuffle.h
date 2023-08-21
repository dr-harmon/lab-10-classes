#pragma once

#include <memory>
#include <vector>

class Track;

void shuffle(std::vector<std::unique_ptr<Track> >& a);
