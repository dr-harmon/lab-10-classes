# Lab 10: Classes

This lab is a review of C++ classes and object-oriented programming concepts. We will build a simple simulation of a media player that has a single playlist containing a mix of audio and video tracks.

## Class Hierarchy

The media player should be implemented as a C++ class called `MediaPlayer`. The tracks it manages should be represented with classes `AudioTrack` and `VideoTrack` with a common base class `Track`. These tracks should be stored in a single vector of `unique_ptr` objects that is private to the `MediaPlayer` class.

The `Track` class should have a private `title` attribute that is initialized through a constructor parameter.

The `AudioTrack` class should have a private `album` attribute. This attribute and the `title` attribute should be initialized in a custom `AudioTrack` constructor.

The `VideoPlayer` class should have a private `Rating` attribute. The type of this attribute is an `enum` with values representing G, PG, PG-13, and R ratings. This attribute and the `title` attribute should be initialized in a custom `VideoPlayer` constructor.

## Add Track

The `MediaPlayer` class should have an overloaded `addTrack` method:

	void addTrack(const std::string& title, const std::string& album);
	void addTrack(const std::string& title, Rating rating);

The first method adds a new audio track to the playlist, and the second adds a new video track to the playlist.

## Print Details

All classes should have a `printDetails` method as follows:

* `Track`—prints "Title: TRACK" where "TRACK" is the object's `track` attribute
* `AudioTrack`—prints "=== AUDIO TRACK ===", invokes the `printDetails` of its parent, then prints "Album: ALBUM" where "ALBUM" is the object's `album` attribute.
* `VideoTrack`—prints "=== VIDEO TRACK ===", invokes the `printDetails` of its parent, then prints "Rating: RATING" where "RATING" is a string representation of the object's `rating` attribute.
* `MediaPlayer`—iterates through its vector of tracks and uses polymorphism to invoke each object's `printDetails` method.

Example code:

	MediaPlayer player;
	player.addTrack("Dance the Night", "Barbie the Album");
	player.addTrack("Blank Space", "1989");
	player.addTrack("The Post", PG13);
	player.printDetails();

Example output:

	=== AUDIO TRACK ===
	Title: Dance the Night
	Album: Barbie the Album
	=== AUDIO TRACK ===
	Title: Blank Space
	Album: 1989
	=== VIDEO TRACK ===
	Title: The Post
	Rating: PG-13

## Get Track Count

The `MediaPlayer` class should have a `getTrackCount` method that returns the number of tracks currently stored in its playlist.

## Shuffle Tracks

The `MediaPlayer` class should have a `shuffle` method that puts the playlist vector in a random order. You may re-use your code from "Lab 9: Randomness" for this purpose. Put the code for shuffling into separate files (not `mediaplayer.cpp`): `shuffle.h` for the header and `shuffle.cpp` for the implementation.

## Unit Tests

In the `mediaplayer_test.cpp` file, add a single unit test for the `getTrackCount` method.
