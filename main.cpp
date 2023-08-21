#include <cstdlib>
#include "mediaplayer.h"

using namespace std;

int main()
{
	MediaPlayer player;
	player.addTrack("Dance the Night", "Barbie the Album");
	player.addTrack("Blank Space", "1989");
	player.addTrack("The Post", PG13);
    player.shuffleTracks();
	player.printDetails();

	return EXIT_SUCCESS;
}
