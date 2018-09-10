#include <stdio.h>
#include <string.h>
// Add functions and includes as needed

enum ChunkType
{
	VERTS_TYPE,
	NORMS_TYPE,
	ANIM_TYPE,
	TEXTURE_TYPE,
	UV_TYPE
};

#define UNUSED_VAR(v) ((void *)v)

bool equal(char *a, char *b)
{
	int s = strcmp(a, b);
	if (s == 0)
		return true;

	return false;
}

bool found(char* argv)
{
	bool fou = false;
	if (equal(argv, "ANIM_TYPE"))
		fou = true;
	else if (equal(argv, "NORMS_TYPE"))
		fou = true;
	else if (equal(argv, "TEXTURE_TYPE"))
		fou = true;
	else if (equal(argv, "UV_TYPE"))
		fou = true;
	else if (equal(argv, "VERTS_TYPE"))
		fou = true;

	return fou;
}

int main(int argc, char *argv[])
{
	
	if (argc == 7 &&
		((equal(argv[3], "-t") && found(argv[4]) && equal(argv[5], "-n") && !found(argv[6]) && !equal(argv[6], "player_8888888888888881")) ||
		(equal(argv[3], "-n") && !found(argv[4]) && !equal(argv[6], "player_8888888888888881") && equal(argv[5], "-t") && found(argv[6])))
		)
	{
		return 0;
	}
	return -1;	
}