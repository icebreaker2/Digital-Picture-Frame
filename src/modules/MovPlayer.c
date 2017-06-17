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
	inst = libvlc_new(0, NULL);

	/* Create a new item */
	//m = libvlc_media_new_location(inst, "http://mycool.movie.com/test.mov");
	m = libvlc_media_new_path(inst, pathToFile);

	/* Create a media player playing environement */
	mp = libvlc_media_player_new_from_media(m);

	/* No need to keep the media now */
	libvlc_media_release(m);

	/* play the media_player */
	libvlc_media_player_play(mp);

	sleep(1); /* Let it play a bit */

	/* Stop playing */
	libvlc_media_player_stop(mp);

	/* Free the media_player */
	libvlc_media_player_release(mp);

	libvlc_release(inst);

	return false;
}
