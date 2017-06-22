#include "VLCPlayer.h"

/**
 * Plays every known media file with vlc in full screen. Once the method is called it screens the media forever.
 * @param fileList Is a list of file names including their paths. The names and paths are used by vlc to play them.
 * @param fileListLength Is the length of the list.
 */
void playMultipleMediaFiles(const char **fileList, uint32_t fileListLength){
	// set the optional arguments and load/create the vlc engine/instance
	const char *const vlc_args[] = {
			"-f", "-V", "X11"
	};

	libvlc_instance_t *libvlc_instance = libvlc_new(sizeof(vlc_args) / sizeof(vlc_args[0]), vlc_args);
	libvlc_media_list_t *libvlc_media_list = libvlc_media_list_new(libvlc_instance);

	// create the media list
	uint32_t i = 0;
	for (i; i < fileListLength; i++) {
		libvlc_media_t *media = libvlc_media_new_path(libvlc_instance, fileList[i]);
		libvlc_media_list_add_media(libvlc_media_list, media);
		//printf("%s\n", fileList[i]);
	}

	// set the media list to a media list player with endless loop
	libvlc_media_list_player_t *media_list_player = libvlc_media_list_player_new(libvlc_instance);
	libvlc_media_list_player_set_playback_mode(media_list_player, libvlc_playback_mode_loop);
	libvlc_media_list_player_set_media_list(media_list_player, libvlc_media_list);

	// set the media player that is in full screen
	libvlc_media_player_t *media_player = libvlc_media_player_new(libvlc_instance);
	libvlc_set_fullscreen(media_player, 1);
	libvlc_media_list_player_set_media_player(media_list_player, media_player);

	// Start playing
	libvlc_media_list_player_play(media_list_player);

	for (;;) pause(); // play forever
}

