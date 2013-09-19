#include <stdio.h>
#include <stdlib.h>
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

PlayList *  FileManager::LoadPlayListFromFile(char * filePath)
{
  FILE * playlist = fopen(filePath, "r");

}

bool FileManager::CreatePlayList(char * name, Track * tracks, int numerTracks)
{
  
}


