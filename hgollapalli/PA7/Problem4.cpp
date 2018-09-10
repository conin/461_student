#include <math.h>
#include<stdio.h>

namespace
{
	typedef struct Vect  // Vector struct for positions
	{
		float x;
		float y;
		float z;
	} Vect_t;


	/***********************************************************************
	*
	*  Function: findMaxDistance()
	*
	*  Input:
	*          int       nPlayers - number of players
	*          Vect_t   *playerArray - the array of players
	*  Output:
	*          float     maxDist - the maxDistance between any two players
	*
	***********************************************************************/

	float minDist = 100.0f;

	float findMax(int nPlayers, Vect_t *playerArray, int playerIndex)
	{
		float maxDist = 0.0f;    // current max distance
		if (playerIndex >= 0)
		{
			Vect_t tmpVect;   // temporary vector

			maxDist = findMax(nPlayers, playerArray, playerIndex - 1);

			for (int j = nPlayers - 1; j > playerIndex; j--)
			{
				// Find a vector between point i and j
				tmpVect.x = playerArray[playerIndex].x;
				tmpVect.x -= playerArray[j].x;

				tmpVect.y = playerArray[playerIndex].y;
				tmpVect.y -= playerArray[j].y;

				tmpVect.z = playerArray[playerIndex].z;
				tmpVect.z -= playerArray[j].z;

				// Get its length with out root

				float tmpDist = tmpVect.x*tmpVect.x;
				tmpDist += tmpVect.y*tmpVect.y;
				tmpDist += tmpVect.z*tmpVect.z;

				// determine if it’s a new maximum length
				if (tmpDist > maxDist)
				{
					// yes so keep it
					maxDist = tmpDist;
				}
				if (tmpDist < minDist)
					minDist = tmpDist;
			}
		}
		else
		{
			return 0;
		}
		return maxDist;
	}

	/// minDist  and maxDist
	float findMaxDistance(int nPlayers, Vect_t *playerArray)
	{
		///index should be between 0 to n-1
		if (nPlayers > 1)
		{
			return sqrtf(findMax(nPlayers, playerArray, nPlayers - 1));
		}

		else
			return 0;
	}
}

//int main()
//{
//	Vect *t = new Vect[3];
//	t[0].x = 1.0f;
//	t[0].y = 0.0f;
//	t[0].z = 0.0f;
//
//	t[1].x = 2.0f;
//	t[1].y = 0.0f;
//	t[1].z = 0.0f;
//
//	t[2].x = 3.0f;
//	t[2].y = 0.0f;
//	t[2].z = 0.0f;
//
//
//	printf("\nMax distance %f",findMaxDistance(3, t));
//	minDist = sqrtf(minDist);
//	printf("\nMin distance %f\n ", minDist);
//	return 0;
//}