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
	libvlc_media_list_t* list = libvlc_media_list_new(inst);
	libvlc_media_list_add_media(list, m);
	libvlc_media_list_player_set_media_list(media_list_player,list);

	libvlc_media_list_player_play(media_list_player);

	sleep(10000); /* Let it play a bit */

	/* Stop playing */
	libvlc_media_list_player_stop(media_list_player);

	/* Free the media_player */
	libvlc_media_list_player_release(media_list_player);

	libvlc_release(inst);

	return false;
}

