#include "MovPlayer.h"

/**
 * Plays a *.mov video given the path to the file.
 * @param pathToFile Is the path to the *.mov file including the files name.
 * @return If the video fails false is returned otherwise true.
 */
bool playMovVideo(const char *pathToFile) {
	libvlc_instance_t *inst;
	libvlc_media_player_t *mp;
	libvlc_media_t *m;

	/* Load the VLC engine */
	//preparation of the vlc command
	const char * const vlc_args[] = {
			"-V", "X11"
			};
	inst = libvlc_new(sizeof(vlc_args) / sizeof(vlc_args[0]), vlc_args);

	/* Create a new item */
	//m = libvlc_media_new_location(inst, "http://mycool.movie.com/test.mov");
	m = libvlc_media_new_path(inst, pathToFile);

	/* Create a media player playing environement */
	mp = libvlc_media_player_new_from_media(m);
	libvlc_set_fullscreen(mp, 1);

	/* play the media_player */
	libvlc_media_player_play(mp);

	sleep(3); /* Let it play a bit */

	/* Stop playing */
	libvlc_media_player_stop(mp);

	/* Free the media_player */
	libvlc_media_player_release(mp);

	libvlc_release(inst);

	return false;
}
