#include <stdio.h>
#include <stdlib.h>
#include <boost/regex.hpp>
#include "FileManager.h"

FileManger::FileManager(char * musicDir, char * plsylistDir)
{
  //probably should copy these strings...
  musicRootDirectory = musicDir;
  playListRootDirectory = playlistDir;
}

void FileManager::RefreshMusicDB()
{
  //check for main playlist
  //if it exists, load it into _activePlayLists
  //if it doesn't, iterate through our root directory building the playlist
  
}

PlayList *  FileManager::LoadPlayList(char * name)
{
  int pathLen = strlen(playListRootDirectory) + strlen(name);
  char * filePath = calloc(sizeof(char), pathLen);
  strcpy(filePath, playListRootDirectory);
  strcat(filePath, name);

  FILE * playList = fopen(filePath, "r");
  if (playList == null)
    {
      return null;
    }

  PlayList * newPlayList = new PlayList();
  char * line = 0;

  getline(&line, 0, playList);
  
  bool isExtendedM3U = !strcmp(line, "#EXTM3U");

  if (isExtendedM3U)
    {
        getline(&line, 0, playList);
    }
  static const boost::regex m3uExtExp("#EXTINF:([0-9]*),(.*) - (.*)");
  static const boost::regex fsExp("([^/]+)\.([^/]+)$");
  
  do {
    var track = new Track();
      if (isExtendedM3U)
	{
	  //parse the extended info
	  if (regex_match(line, m3uExtExp))
	    {
	      track.duration = atoi(match_results[1].str().c_str());
	      
	      track.artist = new char[match_results[2].str().length()];
	      strcpy(track.artist, match_results[2].str().c_str());

	      track.name = new char[match_results[3].str().length()];
	      strcpy(track.name, match_results[3].str().c_str());
	    }
	  
	}
      //'parse' the file path
      getline(&line, strlen(line), playList);
      track.filePath = calloc(sizeof(char), strlen(line));
      strcpy(track.filePath, line);
      if (!isExtendedM3U && regex_match(line, fsExp))
	{
	  track.name = new char[match_result[1].str().length()];
	  strcpy(track.name, match_result[1].str().c_str());
	  strcpy(track.ext, match_result[2].str().c_str());
	}
      //add the track to the play list
      newPlayList.tracks.push_back(track);
  } while (getline(&line, strlen(line), playList) != -1)
    
    fclose(playList);
    return newPlayList;
}

bool FileManager::AddToPlayList(char * name, Track *tracks[], int numTracks)
{
  int pathLen = strlen(playListRootDirectory) + strlen(name);
  char * filePath = calloc(sizeof(char), pathLen);
  strcpy(filePath, playListRootDirectory);
  strcat(filePath, name);

  FILE * playList = fopen(filePath, "a+");
  if (playList == null)
    {
      return false;
    }
  fseek(playList, 0, SEEK_SET);
  getline(&line, 0, playList);
  
  bool isExtendedM3U = !strcmp(line, "#EXTM3U");
  
  for (int i = 0; i < numTracks; ++i)
    {
      if (isExtendedM3U)
	{
	  fprintf(playList, "#EXTINF:%d,%s - %s\n", tracks[i]->duration, tracks[i]->name, tracks[i]->artist);
	}
      fprintf(playList, "%s\n\n", tracks[i]->filePath);
    }

  //if the playlist we are updating is the active playlist... update it.
  if (!strcmp(_activePlayList.name, name))
    {
      //update
      for (int i = 0; i < numTracks; ++i)
	{
	  _activePlayList.tracks.push_back(tracks[i]);
	}
      //invalidation
      //      delete _activePlayList;
      //      _activePlayList = LoadPlayList(name);
    }

  fclose(playlist);
  return true;
}


