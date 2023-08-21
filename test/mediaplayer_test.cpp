#include <catch2/catch_test_macros.hpp>

#include "mediaplayer.h"

TEST_CASE("Track count should match number of tracks added") {
	MediaPlayer player;
	player.addTrack("Song1", "Album1");
    REQUIRE(player.getTrackCount() == 1);
	player.addTrack("Song2", "Album2");
    REQUIRE(player.getTrackCount() == 2);
	player.addTrack("Movie1", PG13);
    REQUIRE(player.getTrackCount() == 3);
}
