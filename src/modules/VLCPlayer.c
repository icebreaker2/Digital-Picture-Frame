#include "VLCPlayer.h"

/**
 * Plays a *.mov video given the path to the file.
 * @param pathToFile Is the path to the *.mov file including the files name.
 * @return If the video fails false is returned otherwise true.
 */
bool playMovVideo(const char *pathToFile) {
	libvlc_instance_t *inst;
	libvlc_media_player_t *mp;
	libvlc_media_t *m;
	libvlc_media_list_player_t *media_list_player;

	/* Load the VLC engine */
	//preparation of the vlc command
	const char *const vlc_args[] = {
			"-f", "-V", "X11"
	};

	inst = libvlc_new(sizeof(vlc_args) / sizeof(vlc_args[0]), vlc_args);

	/* Create a new item */
	//m = libvlc_media_new_location(inst, "http://mycool.movie.com/test.mov");
	m = libvlc_media_new_path(inst, pathToFile);

	/* Create a media player playing environement */
	mp = libvlc_media_player_new_from_media(m);
	libvlc_set_fullscreen(mp, 1);
	media_list_player = libvlc_media_list_player_new(inst);

	/* play the media_player */
	libvlc_media_player_play(mp);
	libvlc_media_list_player_set_playback_mode(media_list_player, libvlc_playback_mode_loop);
	//printf("%i", libvlc_media_discoverer_is_running(libvlc_MediaDiscovererStarted));
	libvlc_media_list_t *list = libvlc_media_list_new(inst);
	libvlc_media_list_add_media(list, m);
	libvlc_media_list_player_set_media_list(media_list_player, list);

	libvlc_media_list_player_play(media_list_player);

	sleep(10000); /* Let it play a bit */

	/* Stop playing */
	libvlc_media_list_player_stop(media_list_player);

	/* Free the media_player */
	libvlc_media_list_player_release(media_list_player);

	libvlc_release(inst);

	return false;
}

bool playMultipleMediaFiles(const char **fileList, uint32_t fileListLength) {
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
		printf("%s\n", fileList[i]);
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

	return false;
}

