#pragma once

#include <memory>
#include <string>

class Track {
	std::string title;
public:
	Track(const std::string& title);
    virtual ~Track();
	virtual void printDetails() const;
};

class AudioTrack : public Track {
	std::string album;
public:
	AudioTrack(const std::string& title, const std::string& album);
    virtual ~AudioTrack();
	virtual void printDetails() const;
};

enum Rating {
	G, PG, PG13, R
};

class VideoTrack : public Track {
	Rating rating;
public:
	VideoTrack(const std::string& title, Rating rating);
    virtual ~VideoTrack();
	virtual void printDetails() const;
};

class MediaPlayer {
	std::vector<std::unique_ptr<Track> > tracks;
public:
	void addTrack(const std::string& title, const std::string& album);
	void addTrack(const std::string& title, Rating rating);
	void shuffleTracks();
	void printDetails() const;
	int getTrackCount() const;
};
