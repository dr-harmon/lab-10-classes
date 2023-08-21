#include "mediaplayer.h"
#include "shuffle.h"
#include <iostream>

using namespace std;

Track::Track(const string& title)
{
    this->title = title;
}

Track::~Track()
{
}

void Track::printDetails() const
{
    cout << "Title: " << title << endl;
}

AudioTrack::AudioTrack(const string& title, const string& album) : Track(title)
{
    this->album = album;
}

AudioTrack::~AudioTrack()
{    
}

void AudioTrack::printDetails() const
{
    cout << "=== AUDIO TRACK ===" << endl;
    Track::printDetails();
    cout << "Album: " << album << endl;
}

VideoTrack::VideoTrack(const string& title, Rating rating) : Track(title)
{
	this->rating = rating;
}

VideoTrack::~VideoTrack()
{    
}

void VideoTrack::printDetails() const
{
    cout << "=== VIDEO TRACK ===" << endl;

    Track::printDetails();

    cout << "Rating: ";

    switch (rating) {
        case G:
            cout << "G";
            break;
        case PG:
            cout << "PG";
            break;
        case PG13:
            cout << "PG-13";
            break;
        case R:
            cout << "R";
            break;
    }

    cout << endl;
}

void MediaPlayer::addTrack(const string& title, const string& album)
{
    unique_ptr<Track> track = make_unique<AudioTrack>(title, album);
    tracks.push_back(std::move(track));
}

void MediaPlayer::addTrack(const string& title, Rating rating)
{
    unique_ptr<Track> track = make_unique<VideoTrack>(title, rating);
    tracks.push_back(std::move(track));
}

void MediaPlayer::shuffleTracks()
{
    shuffle(tracks);
}

void MediaPlayer::printDetails() const
{
    for (auto track = tracks.begin(); track != tracks.end(); track++) {
        (*track)->printDetails();
    }
}

int MediaPlayer::getTrackCount() const
{
    return tracks.size();
}
